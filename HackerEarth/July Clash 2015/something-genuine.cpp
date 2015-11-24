#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;

int n,a[maxn],pos[maxn];

/* SPLAY TREE */
struct node{
    node *parent, *left, *right;
    ll S, s, n, v;
    int lazyInc;
}*root, *nilT;

void init(){
    nilT = new node;
    nilT->S = nilT->s = nilT->n = 0;
    nilT->parent = nilT->left = nilT->right = NULL;
    nilT->lazyInc = 0;
    root = nilT;
}

node *newNode(int v){
    node *p = new node;
    p->parent = p->left = p->right = nilT;
    p->S = v*v;
    p->s = v;
    p->v = v;
    p->n = 1;
    p->lazyInc = 0;
    return p;
}

void setLink(node *x, node *y, bool inleft){
    y->parent = x;
    if(inleft) x->left = y; else x->right = y;
}

void lazyUpdate(node *x){
    if(x==nilT) return;
    x->left->lazyInc += x->lazyInc;
    x->right->lazyInc += x->lazyInc;
    x->v += x->lazyInc;
    ll d=x->lazyInc;
    x->S += 2*(x->s * d + (x->n)*d*(d-1)/2) + x->n * d;
    x->s += x->n * d;
    x->lazyInc = 0;
}

void updateNode(node *x){
    if(x==nilT) return;
    lazyUpdate(x);
    lazyUpdate(x->left); lazyUpdate(x->right);
    x->n = x->left->n + x->right->n + 1;
    x->s = x->left->s + x->right->s + x->v;
    x->S = x->left->S + x->right->S + x->v * x->v;
}

void uptree(node *x){
    node *y = x->parent; node *z = y->parent;
    lazyUpdate(y); lazyUpdate(x);
    if(y == nilT) return;
    if(x == y->left){
        setLink(y,x->right,1);
        setLink(x,y,0);
    }else{
        setLink(y,x->left,0);
        setLink(x,y,1);
    }
    setLink(z,x,y==z->left);
    updateNode(y); updateNode(x);
}

void splay(node *x){
    while(1){
        node *y = x->parent;
        if(y == nilT) break;
        node *z = y->parent;
        if(z != nilT){
            if( (z->left == y) == (y->left == x) ) uptree(y);
            uptree(x);
        }
        uptree(x);
    }
}

node* nodeAt(node *p, int i){
    while(1){
        lazyUpdate(p);
        if(p->left->n + 1 == i) return p;
        if(p->left->n >= i) p = p->left;
        else{
            i -= p->left->n + 1;
            p = p->right;
        }
    }
    return p;
}

void split(node *r, node *&a, node *&b, int pos){
    if(pos==0){
        a = nilT;
        b = r;
        return;
    }

    a = nodeAt(r, pos);
    splay(a);
    b = a->right;
    a->right = nilT;
    b->parent = nilT;
    updateNode(a);
}

node* join(node *a, node *b){
    if(a == nilT){
        updateNode(b);
        return b;
    }
    while(a->right!=nilT){
        lazyUpdate(a);
        a = a->right;
    }
    splay(a);
    setLink(a,b,0);
    updateNode(a);
    return a;
}

void query(int pos){
    node *a, *b;
    split(root, a, b, pos);
    ++b->lazyInc;
    root = join(a, b);
    node *p = newNode(1);
    root = join(root, p);
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    init();

    ll res = 0;
    reset(pos,0);
    for(int i=1; i<=n; ++i){
        int last = pos[a[i]];
        query(last);
        pos[a[i]]=i;
        res = (res + root->S)%oo;
    }

    cout<<res<<endl;
}
