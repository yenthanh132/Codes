#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

///////////TREAP/////////////
#define MAXINT 32767
#define maxn 100007

struct node{
    int v,priority,size;
    ll sum;
    node *left, *right, *parent;
} *nil, *xroot, *yroot, sentinal;

void setlink(node *x, node *y, bool inleft){
    y->parent=x;
    if (inleft) x->left=y; else x->right=y;
}

void init(){
    srand(time(NULL));
    sentinal.v=sentinal.priority=sentinal.size=sentinal.sum=0;
    nil=&sentinal;
    xroot=nil; yroot=nil;
}

node* newnode(int v){
    node* p=new node;
    p->v=v; p->size=1; p->sum=v;
    p->priority=rand()%MAXINT+1;
    p->left=nil; p->right=nil; p->parent=nil;
    return p;
}

void uptree(node *& root, node *x){
    node *y=x->parent, *z=y->parent;
    if(x==y->left){
        setlink(y,x->right,true);
        setlink(x,y,false);
    }else{
        setlink(y,x->left,false);
        setlink(x,y,true);
    }
    setlink(z,x,z->left==y);
    if(y==root) root=x;
    y->size = y->left->size + y->right->size+1;
    y->sum = y->left->sum + y->right->sum + y->v;
    x->size = x->left->size + x->right->size+1;
    x->sum = x->left->sum + x->right->sum + x->v;
}

void add(node *&root, int v){
    if(root==nil){
        root=newnode(v);
        return;
    }
    node *x=root, *y;
    while(x!=nil){
        y=x;
        if(v < y->v) x=y->left; else x=y->right;
    }
    x=newnode(v);
    setlink(y,x,v < y->v);
    while(y!=nil) y->size++, y->sum += v, y=y->parent;
    while(x->parent != nil && x->parent->priority < x->priority) uptree(root,x);
}

void del(node *&root, int v){
    node *x=root, *y, *z;
    while (x!=nil && x->v != v) if(v<x->v) x=x->left; else x=x->right;
    while(x->left != nil && x->right != nil)
        if(x->left->priority > x->right->priority) uptree(root,x->left); else uptree(root,x->right);
    z=x->parent;
    if(x->left!=nil) y=x->left; else y=x->right;
    setlink(z,y,z->left==x);
    while(z!=nil) (z->size)--, z->sum -= v, z=z->parent;
    if(x==root) root=y;
    delete x;
}

void getsmaller(node *&root, int v, int& count, ll& sum){
    count=sum=0;
    node* x=root;
    while (x!=nil)
        if(v>=x->v) count+=x->left->size+1, sum += x->left->sum+x->v, x=x->right;
        else x=x->left;
}

void getbigger(node *&root, int v, int& count, ll& sum){
    count=sum=0;
    node* x=root;
    while (x!=nil)
        if(v<=x->v) count+=x->right->size+1, sum += x->right->sum+x->v, x=x->left;
        else x=x->right;
}       

//------------------------------

//#include <conio.h>

pii p[maxn];

int main(){
    int N,Q,BASE,count;
    ll T=0,sum;
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d",&N,&Q,&BASE);
    init();
    FOR(i,1,N){
        scanf("%d%d",&p[i].fi,&p[i].se);
        add(xroot,p[i].fi+p[i].se); add(yroot,p[i].fi-p[i].se);
    }
    int k,i,a1,b1,a2,b2,x,y,X,Y;
    FOR(index,1,Q){
        scanf("%d",&k);
        if(k){
            scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
            x=(a1*(T%BASE)+b1)%BASE; y=(a2*(T%BASE)+b2)%BASE;
            X=x+y; Y=x-y;
            getsmaller(xroot,X,count,sum);  T=ll(X)*count-sum;
            getbigger(xroot,X,count,sum); T+=sum-ll(X)*count;
            getsmaller(yroot,Y,count,sum);  T+=ll(Y)*count-sum;
            getbigger(yroot,Y,count,sum); T+=sum-ll(Y)*count;
            T+=(N-1)*2;
            printf("%lld\n",T);
        }else{
            scanf("%d%d%d%d%d",&i,&a1,&b1,&a2,&b2);
            x=(a1*(T%BASE)+b1)%BASE; y=(a2*(T%BASE)+b2)%BASE;
            del(xroot,p[i].fi+p[i].se); del(yroot,p[i].fi-p[i].se);
            p[i]=pii(x,y);
            add(xroot,x+y); add(yroot,x-y);
        }
    }
    //getch();
    return 0;
}
            
