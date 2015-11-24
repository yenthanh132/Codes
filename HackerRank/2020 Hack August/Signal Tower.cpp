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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// Splay Tree
struct node{
    int v,size;
    ll sum;
    node *left, *right, *parent;
} *nilT, *root;

void init(){
    nilT=new node();
    nilT->v=0; nilT->size=0;
    nilT->sum=0;
    root = nilT;   
}

void dfsDelete(node *p){
    if(p==nilT) return;
    if(p->left!=nilT) dfsDelete(p->left);
    if(p->right!=nilT) dfsDelete(p->right);
    delete(p);
}

void deleteAll(){
    dfsDelete(root);
    root=nilT;
}

void setlink(node *x, node *y, bool inleft){
    y->parent=x;
    if(inleft) x->left=y; else x->right=y;
}

node * newnode(int v){
    node *p = new node();
    p->v=v; p->sum=v;
    p->size=1;
    p->left = p->right = p->parent = nilT;
    return p;   
}

void update(node *x){
    x->sum = x->v + x->left->sum + x->right->sum;
    x->size = 1 + x->left->size + x->right->size;
}

void uptree(node *x){
    node *y=x->parent;
    node *z=y->parent;
    if(x==y->left){
        setlink(y,x->right,1);
        setlink(x,y,0);
    }else{
        setlink(y,x->left,0);
        setlink(x,y,1);
    }
    if(y!=nilT) setlink(z,x,y==z->left);   
    update(y);update(x);
}

void splay(node *x){
    while(1){
        node *y=x->parent;
        if(y==nilT) return;
        node *z=y->parent;
        if(z!=nilT){
            if((z->left==y) == (y->left==x)) uptree(y); 
            else uptree(x);
        }
        uptree(x);
    }   
}

node *getnode(node *r, int k){
    while(1){
        if(r->left->size+1 == k) return r;
        else if(r->left->size >= k) r=r->left;
        else{
            k-=r->left->size+1;
            r=r->right;
        }   
    }   
}

int getnode(node *r, int k, ll &sum){
    sum=0;
    while(1){
        if(r->left->size+1 == k){
            sum+=r->v;
            return r->v;
        }else if(r->left->size >= k) r=r->left;
        else{
            k-=r->left->size+1;
            sum+=r->left->sum + r->v;
            r=r->right;
        }   
    }    
}

void split(node *r, node *&x, node *&y, int k){
    if(k==0){
        x=nilT;
        y=r;
        return;
    }
    if(k==r->size){
        x=r;
        y=nilT;
        return;   
    }
    x = getnode(r,k);
    splay(x);
    y=x->right; y->parent=nilT;
    x->right = nilT;
    update(x);
}

node *join(node *x, node *y){
    if(x==nilT) return y;
    if(y==nilT) return x;
    while(x->right!=nilT) x=x->right;
    splay(x);
    setlink(x,y,0);
    update(x);
    return x;
}

void add(node *&r, int v){
    if(r==nilT){
        r=newnode(v);
        return;
    }
    node *y = r, *x;
    while(y->right!=nilT) y=y->right;
    x=newnode(v);
    setlink(y,x,0);
    while(y!=nilT){
        update(y);
        y=y->parent;
    }
    splay(x);
    r=x;
}

//====================================================

const int maxn=100007;

int a[maxn],b[maxn],x[maxn],y[maxn],n,q,lquery[maxn],rquery[maxn];
ll res[maxn],sum[maxn];

ll query(int L, int R){
    node *x, *y, *z;
    split(root,y,z,R);
    split(y,x,y,L-1);
    int c = (R-L+2)/2;
    ll small_sum,big_sum;
    ll v=getnode(y,c,small_sum);
    big_sum = sum[R] - sum[L-1] - small_sum;
    root = join(x,y); root = join(root,z);
    return (v * c - small_sum) + (big_sum - v *(R-L+1 - c));
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
    FOR(i,1,q) scanf("%d%d",&lquery[i],&rquery[i]);
    
    //init
    FOR(i,1,n){
        x[i]=a[i]+b[i];
        y[i]=a[i]-b[i];
    }
    sum[0]=0;
    
    //For X
    init();
    deleteAll();
    FOR(i,1,n) add(root,x[i]), sum[i]=sum[i-1]+x[i];
    FOR(i,1,q) res[i]=query(lquery[i],rquery[i]);
    deleteAll();
    FOR(i,1,n) add(root,y[i]), sum[i]=sum[i-1]+y[i];
    FOR(i,1,q){
        res[i]+=query(lquery[i],rquery[i]);
        printf("%d",res[i]/2);
        if(res[i]&1) puts(".5"); else puts(".0");
    }
    
    getch();
    return 0;
}    
