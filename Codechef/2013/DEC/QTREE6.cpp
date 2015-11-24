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

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}


//=====================================

const int maxn=100007;

struct node{
    int v,size;
    node *left, *right, *parent;   
} *nilT, *tree[maxn];

int color[maxn],n,m,num[maxn],num2[maxn],cnt, parent[maxn];
vector<int> a[maxn];

//splay tree

void setlink(node *x, node *y, bool inleft){
    y->parent=x;
    if(inleft) x->left=y; else x->right=y;
}   

void update_node(node *x){
    x->size = x->left->size + x->right->size + 1;   
}

void uptree(node *x){
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
    update_node(y);
    update_node(x);
}

void splay(node *x){
    node *y, *z;
    while(1){
        y=x->parent; if(y==nilT) return;
        z=y->parent;
        if(z!=nilT)
            if((x==y->left) == (y==z->left)) uptree(y);
            uptree(x);
        uptree(x);   
    }
}   

node *find(node *&r, int v){
    node *x=r;
    while(x!=nilT && x->v != v)
        if(v < x->v) x=x->left; else x=x->right;
    return x;
}

node *find_least(node *&r, int v){
    node *x=r, *res=nilT;   
    while(x!=nilT)
        if(x->v <= v){
            res=x;
            x=x->right;
        }else x=x->left;
    return res;
}

node* join(node *x, node *y){
    if(x==nilT) return y;
    if(y==nilT) return x;
    splay(x); splay(y);
    while(x->right!=nilT) x=x->right;
    splay(x);
    setlink(x,y,0);
    update_node(x);
    return x;   
}

void split(node *&x, node *&y, int v){
    y=find(x,v);
    splay(y);
    
    x=y->left;
    x->parent=nilT;
    y->left=nilT;
    update_node(y);
}

void insert(node *x, node *p){
    node *y;
    while(x!=nilT){
        y=x;
        if(p->v < x->v) x=x->left; else x=x->right;   
    }   
    setlink(y,p,p->v < y->v);
    while(y!=nilT){
        update_node(y);
        y=y->parent;   
    }
}

//==========================================

node * new_node(int v){
    node * p = new node;
    p->v=v;
    p->size=1;
    p->left = p->right = p->parent = nilT;
    return p;   
}

void dfs(int u){
    num[u]=++cnt;
    tree[u]=new_node(num[u]);
    if(u!=1) join(tree[1],tree[u]);   
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(!num[v]){
            parent[v]=u;
            dfs(v);
        }
    }
    num2[u]=cnt;
}

void toggle(int u){
    int v;
    node *r = tree[u], *t1, *t2; 
    splay(r);
    if(parent[u]!=0 && color[parent[u]]==color[u]){
        r=find_least(r, num2[u]);
        splay(r);
        t2=r->right;
        t2->parent=nilT;
        r->right=nilT;
        update_node(r);
        
        r=find(r, num[u]);
        splay(r);
        t1=r->left;
        t1->parent=nilT;
        r->left=nilT;
        update_node(r);
        join(t1,t2);
    }
    REPD(i,sz(a[u])){
        v=a[u][i];
        if(v==parent[u]) continue;
        if(color[u] == color[v])
            split(r,tree[v],num[v]); 
    }   
    color[u]^=1;
    REP(i,sz(a[u])){
        v=a[u][i];   
        if(v==parent[u]) continue;
        if(color[u] == color[v])
            r=join(r,tree[v]);            
    }
    if(parent[u]!=0 && color[parent[u]]==color[u]){
        node *p = tree[parent[u]];
        splay(p);
        insert(p,r);
    }
}

int count(int u){
    node *p=tree[u];
    splay(p);
    return p->size;   
}

int main(){
    freopen("input.txt","r",stdin);   
    freopen("output.txt","w",stdout);

    int u,v;
    
    read(n);
    REP(i,n-1){
        read(u); read(v);
        a[u].pb(v);
        a[v].pb(u);   
    }
    
    reset(num,0); reset(color,0);
    nilT = new node;
    nilT->v=0; nilT->size=0;
    FOR(i,1,n) tree[i]=nilT;
    cnt=0; parent[1]=0; dfs(1);
    
    
    
    scanf("%d",&m);
    REP(tt,m){
        read(u); read(v);
        /*
        if(tt==15){
            cout<<"ABC"<<endl;
        }
        */
        if(u==0) printf("%d\n",count(v));
        else toggle(v);
    }
}
