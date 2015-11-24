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

struct node{
    int v,sz,priority;
    node *left, *right, *parent;
} *nilT, *bit[maxn];

void init(){
    nilT = new node;
    nilT->sz = 0;
    nilT->priority = -1;
    for(int i=1; i<=200000; ++i) bit[i]=nilT;
}

node *new_node(int v){
    node *p = new node;
    p->v = v;
    p->sz = 1;
    p->left = p->right = p->parent = nilT;
    p->priority = rand();
    return p;
}

void setlink(node *x, node *y, bool inleft){
    y->parent = x;
    if(inleft) x->left = y; else x->right = y;
}

void uptree(node *&root, node *x){
    node *y=x->parent;
    if(y==nilT) return;
    node *z=y->parent;
    if(x==y->left){
        setlink(y,x->right,1);
        setlink(x,y,0);
    }else{
        setlink(y,x->left,0);
        setlink(x,y,1);
    }
    setlink(z,x,y==z->left);
    if(y==root) root=x;
    y->sz = y->left->sz + y->right->sz + 1;
    x->sz = x->left->sz + x->right->sz + 1;
}

void add_node(node *&root, int v){
    if(root==nilT) root = new_node(v);
    else{
        node *y = nilT, *x = root;
        while(x!=nilT){
            y=x;
            if(v < x-> v) x=x->left; else x=x->right;
        }
        x = new_node(v);
        setlink(y,x,v < y->v);
        while(y!=nilT){
            ++y->sz;
            y=y->parent;
        }
        while(x->parent!=nilT && x->parent->priority < x->priority) uptree(root,x);
    }
}

int count_node(node *&root, int v){
    int res = 0;
    node *x = root;
    while(x!=nilT){
        if( x->v < v ){
            res+=x->left->sz + 1;
            x=x->right;
        }else if( x->v == v) break;
        else{
            x=x->left;
        }
    }
    return res;
}

struct team{
    int a,b,c;
}arr[maxn];

int n;

bool cmp(const team &a, const team &b){
    return a.a<b.a;
}

void updateBIT(int i, int v){
    for(;i<=n; i+=i&(-i)) add_node(bit[i],v);
}

int getBIT(int i, int v){
    int res=0;
    for(;i; i-=i&(-i)) res += count_node(bit[i],v);
    return res;
}



int main(){
    //freopen("input.txt","r",stdin);
    init();
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
    sort(arr+1,arr+n+1,cmp);
    ll res = 0;
    for(int i=1; i<=n; ++i){
        res += getBIT(arr[i].b-1,arr[i].c);
        updateBIT(arr[i].b,arr[i].c);
    }
    res = 1ll*n*(n-1)/2 - res;
    cout<<res<<endl;
}

