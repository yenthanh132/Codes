#include<bits/stdc++.h>
#define oo 1000000007

using namespace std;

const int maxn=100007;


//============================================
//SPLAY TREE
//============================================
struct node{
    int v,size;
    bool needSwap;
    node *left, *right, *parent;
} *root[2], *nilT;

void init(){
    nilT = new node;
    nilT->size = 0;
    root[0] = root[1] = nilT;
}

node * newnode(int v){
    node *p = new node;
    p->needSwap = 0;
    p->v = v;
    p->size = 1;
    p->left = p->right = p->parent = nilT;
    return p;
}

void setlink(node *x, node *y, bool inleft){
    y->parent = x;
    if(inleft) x->left = y; else x->right = y;
}

void lazyUpdate(node *x){
    if(x==nilT || !x->needSwap) return;
    node *pl = x->left, *pr = x->right;
    setlink(x,pl,0); setlink(x,pr,1);
    x->needSwap = 0;
    x->left->needSwap ^=1;
    x->right->needSwap ^=1;
}

void uptree(node *x){
    node *y = x->parent;
    if(y==nilT) return;
    lazyUpdate(y); lazyUpdate(x);
    node *z = y->parent;
    if(x == y->left){
        setlink(y,x->right,1);
        setlink(x,y,0);
    }else{
        setlink(y,x->left,0);
        setlink(x,y,1);
    }
    setlink(z,x,z->left==y);
    y->size = 1 + y->left->size + y->right->size;
    x->size = 1 + x->left->size + x->right->size;
    lazyUpdate(z);
}

void splay(node *x){
    lazyUpdate(x);
    while(1){
        node *y=x->parent;
        if(y==nilT) return;
        node *z=y->parent;
        if(z != nilT && (z->left == y) == (y->left == x)) uptree(y);
        uptree(x);
    }
}

node *getnode(node *root, int idx){
    node *p = root;
    while(1){
        lazyUpdate(p);
        if(p->left->size + 1 == idx) return p;
        else if(p->left->size + 1 < idx){
            idx -= p->left->size + 1;
            p=p->right;
        }else p=p->left;
    }
}

void split(node *r,int idx, node *&ln, node *&rn){
    if(idx==0){
        ln=nilT;
        rn=r;
        return;
    }
    if(idx==r->size){
        ln=r;
        rn=nilT;
        return;
    }
    node *p = getnode(r,idx);
    splay(p);
    rn = p->right;
    rn->parent = nilT;
    p->right = nilT;
    p->size = p->left->size + 1;
    ln=p;
}

node *join(node *ln, node *rn){
    if(ln==nilT) return rn;
    if(rn==nilT) return ln;
    lazyUpdate(ln);
    while(ln->right!=nilT){
        ln = ln->right;
        lazyUpdate(ln);
    }
    splay(ln);
    setlink(ln,rn,0);
    ln->size = ln->left->size + ln->right->size + 1;
    return ln;
}

//======================================================

//======================================================
//SMALLEST CLOSING CIRCLE
//======================================================

struct Point {
	double x,y;
	Point(){}
	Point(double a, double b) {
		x=a; y=b;
	}
	Point subtract(Point p) {
		return Point(x - p.x, y - p.y);
	}
	double distance(Point p) {
		return hypot(x - p.x, y - p.y);
	}
	double cross(Point p) {
		return x * p.y - y * p.x;
	}
	double norm() {
		return x * x + y * y;
	}
};

struct Circle {
	Point c;
	double r;
    Circle(){}
	Circle(Point a, double b) {
		c=a; r=b;
	}
	bool contains(Point p) {
		return c.distance(p) <= r + 1e-9;
	}
};



struct SmallestClosingCircle{
	/*
	 * Returns the smallest circle that encloses all the given points. Runs in expected O(n) time, randomized.
	 * Note: If 0 points are given, null is returned. If 1 point is given, a circle of radius 0 is returned.
	 */
	Circle *makeCircle(vector<Point> points) {
		//random_shuffle(points.begin(),points.end());
		Circle *c = NULL;
		for (int i = 0; i < points.size(); i++) {
			Point p = points[i];
			if (c == NULL || !c->contains(p))
				c = makeCircleOnePoint(points,0,i, p);
		}
		return c;
	}

	Circle *makeCircleOnePoint(vector<Point> &points, int fromIdx, int toIdx, Point p) {
		Circle *c = new Circle(p, 0);
		for (int i = fromIdx; i < toIdx; i++) {
			Point q = points[i];
			if (!c->contains(q)) {
				if (c->r == 0)
					c = makeDiameter(p, q);
				else
					c = makeCircleTwoPoints(points,0,i, p, q);
			}
		}
		return c;
	}


	// Two boundary points known
	Circle *makeCircleTwoPoints(vector<Point> &points, int fromIdx, int toIdx, Point p, Point q) {
		Circle *temp = makeDiameter(p, q);
		bool ContainsAll=1;
		for(int i = fromIdx; i < toIdx; ++i) if(!temp->contains(points[i])){
            ContainsAll = 0;
            break;
		}
		if (ContainsAll) return temp;

		Circle *left = NULL;
		Circle *right = NULL;
		for (int i = fromIdx; i < toIdx; ++i) {
            Point r = points[i];
			Point pq = q.subtract(p);
			double cross = pq.cross(r.subtract(p));
			Circle *c = makeCircumcircle(p, q, r);
			if (c == NULL)
				continue;
			else if (cross > 0 && (left == NULL || pq.cross(c->c.subtract(p)) > pq.cross(left->c.subtract(p))))
				left = c;
			else if (cross < 0 && (right == NULL || pq.cross(c->c.subtract(p)) < pq.cross(right->c.subtract(p))))
				right = c;
		}
		return (right == NULL || left != NULL && left->r <= right->r) ? left : right;
	}

	Circle *makeDiameter(Point a, Point b) {
		return new Circle(Point((a.x + b.x)/ 2, (a.y + b.y) / 2), a.distance(b) / 2);
	}

	Circle *makeCircumcircle(Point a, Point b, Point c) {
		double d = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) * 2;
		if (fabs(d)<1e-9) return NULL;
		double x = (a.norm() * (b.y - c.y) + b.norm() * (c.y - a.y) + c.norm() * (a.y - b.y)) / d;
		double y = (a.norm() * (c.x - b.x) + b.norm() * (a.x - c.x) + c.norm() * (b.x - a.x)) / d;
		Point p = Point(x, y);
		return new Circle(p, p.distance(a));
	}

} smallestClosingCircle;

//======================================================
int N,Q;
int arr[2][maxn];

node* build_tree(int id, int l, int r){
    if(l>r) return nilT;
    int mid=(l+r)/2;
    node *p = newnode(arr[id][mid]);
    p->left = build_tree(id,l,mid-1);
    p->right = build_tree(id,mid+1,r);
    p->left->parent = p->right->parent = p;
    p->size = 1 + p->left->size + p->right->size;
    return p;
}

void query1(int id, int A, int B){
    node *ln, *mn, *rn;
    split(root[id],B,ln,rn);
    split(ln,A-1,ln,mn);
    mn->needSwap ^= 1;
    root[id] = join(join(ln,mn),rn);
}

void query2(int id, int l1, int r1, int l2, int r2){
    node *p1,*p2,*p3,*p4,*p5;
    split(root[id],r2,p4,p5);
    split(p4,l2-1,p3,p4);
    split(p3,r1,p2,p3);
    split(p2,l1-1,p1,p2);
    root[id] = join(p1,join(p4,join(p3,join(p2,p5))));
}

void query3(int l, int r){
    node *p1,*p2,*p3,*p4,*p5,*p6;
    split(root[0],r,p2,p3);
    split(p2,l-1,p1,p2);
    split(root[1],r,p5,p6);
    split(p5,l-1,p4,p5);
    root[0]=join(p1,join(p5,p3));
    root[1]=join(p4,join(p2,p6));
}

int maxV, minV;
vector<int> xList,yList;
vector<Point> pList;

void addToList(vector<int> &arr, node *p){
    if(p==nilT) return;
    lazyUpdate(p);
    addToList(arr,p->left);
    arr.push_back(p->v);
    addToList(arr,p->right);
}

void printNode(node *p){
    if(p==nilT) return;
    printNode(p->left);
    cout<<p->v<<' ';
    printNode(p->right);
}

double query4(int l, int r){
    double res=0;
    node *p1,*p2,*p3,*p4,*p5,*p6;
    split(root[0],r,p2,p3);
    split(p2,l-1,p1,p2);
    split(root[1],r,p5,p6);
    split(p5,l-1,p4,p5);
    xList.clear(); yList.clear();
    addToList(xList,p2); addToList(yList,p5);
    root[0]=join(p1,join(p2,p3));
    root[1]=join(p4,join(p5,p6));
    pList.clear();
    for(int i=0; i<xList.size(); ++i) pList.push_back(Point(xList[i],yList[i]));
//    for(int i=0; i<xList.size(); ++i) cout<<xList[i]<<' '; cout<<endl;
//    for(int i=0; i<yList.size(); ++i) cout<<yList[i]<<' '; cout<<endl;
//    printNode(root[0]); cout<<endl;
//    printNode(root[1]); cout<<endl;
    Circle *c = smallestClosingCircle.makeCircle(pList);
    return c->r;
}

int main(){
    //freopen("input.txt","r",stdin);
    init();
    scanf("%d%d",&N,&Q);
    for(int i=0; i<2; ++i) for(int j=1; j<=N; ++j) scanf("%d",&arr[i][j]);
    root[0]=build_tree(0,1,N);
    root[1]=build_tree(1,1,N);
    int key,id,l1,r1,l2,r2;
    for(int i=0; i<Q; ++i){
        scanf("%d",&key);
        if(key==1){
            scanf("%d%d%d",&id,&l1,&r1);
            query1(id,l1,r1);
        }else if(key==2){
            scanf("%d%d%d%d%d",&id,&l1,&r1,&l2,&r2);
            query2(id,l1,r1,l2,r2);
        }else if(key==3){
            scanf("%d%d",&l1,&r1);
            query3(l1,r1);
        }else if(key==4){
            scanf("%d%d",&l1,&r1);
            printf("%0.2lf\n",query4(l1,r1));
        }
    }
}
