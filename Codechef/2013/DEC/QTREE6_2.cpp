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
} *nilT, *tree[maxn], *white[maxn], *black[maxn];

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

void split(node *r, node *&x, node *&y, node *&z, int v1, int v2){
    x=find_least(r, v2);
    splay(x);
    z=x->right;
    z->parent=nilT;
    x->right=nilT;
    update_node(r);
    
    y=find(x, v1);
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

int group[maxn],prev[maxn],pos[maxn],d[maxn],size[maxn];
vector<int> list[maxn];
int *BIT[maxn];

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
    d[u]=0;
    white[u]=new_node(num[u]);
    black[u]=new_node(num[u]);
    tree[u]=white[u];
    if(u!=1) join(tree[1],tree[u]);   
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(!num[v]){
            parent[v]=u;
            dfs(v);
            d[u]=max(d[u],d[v]);
        }
    }
    ++d[u];
    num2[u]=cnt;
}

void constructDFS(int u, int p){
    if(group[u]==0){
        group[u]=++cnt;
        list[cnt].clear();
        list[cnt].pb(u);
        size[cnt]=1;
        pos[u]=1;   
    }
    int v,v2=0;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p) continue;
        if(v2==0 || d[v2]<d[v]) v2=v;   
    }
    
    if(v2!=0){
        group[v2]=group[u];
        pos[v2]=pos[u]+1;
        prev[v2]=prev[u];
        ++size[group[u]];
        list[group[u]].pb(v2);
        constructDFS(v2,u);   
    }
    
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p || v==v2) continue;
        prev[v]=u;
        constructDFS(v,u);   
    }
}

// For BIT

void update(int *BIT, int n, int p, int v){
    for(int i=p; i<=n; i+=i&(-i)) BIT[i]+=v;   
}

int get(int *BIT, int n, int p, int color){
    int res=0;
    for(int i=p; i; i-=i&(-i)) res+=BIT[i];
    if(color==1) return res; else return p-res;
}

//-------------------

void toggle(int u){
    int v;
    node *r = tree[u], *t1, *t2; 
    splay(r);
    
    if(parent[u]!=0){
        split(r,t1,tree[u],t2,num[u],num2[u]);
        join(t1,t2);
    }
    color[u]^=1;
    if(color[u]==1) tree[u]=black[u]; else tree[u]=white[u];
    
    update(BIT[group[u]],size[group[u]],pos[u], (color[u]?1:-1) );
    
    r=tree[u];
    splay(r);
    if(parent[u]!=0){
        node *p;
        if(color[u]==0) p=white[parent[u]]; else p=black[parent[u]];
        splay(p);
        insert(p,r);
    }
}

pii traceback[maxn];
int last;

int find_parent(int u){
    last=0;
    int v=u,g;
    int s=0, s2=0;
    while(v!=0){
        g=group[v];
        traceback[++last]=pii(g, v);
        s+=get(BIT[g], size[g], pos[v], color[u]^1);
        v=prev[v];
    }
    int x,y;
    FORD(i,last,1){
        g=traceback[i].fi;
        s2=get(BIT[g], size[g], pos[traceback[i].se], color[u]^1);
        if(s2==s){
            x=g;
            y=traceback[i].se;
            if(i==1) v=u;
            else v=list[traceback[i-1].fi][0];   
            break;      
        }else s-=s2;
    }
    int left=1,right = pos[y], mid;
    while(left<=right){
        mid=(left+right)/2;
        s2 = get(BIT[x], size[x], mid-1, color[u]^1);
        if(s2==s){
            v=list[x][mid-1];
            right=mid-1;      
        }else left=mid+1;
    }
    
    return v;
}

int count(int u){
    node *p=tree[u], *x, *y, *z;
    splay(p);
    int r=find_parent(u);
    split(p,x,y,z,num[r],num2[r]);
    int res=y->size;
    join(x,y); join(x,z);
    return res;   
}

int main(){
    //freopen("input.txt","r",stdin);   
    //freopen("output2.txt","w",stdout);

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
    cnt=0; parent[1]=0; prev[1]=0; dfs(1);
    
    //construct heavy-light tree
    cnt=0; constructDFS(1,-1);
    FOR(i,1,cnt){
        BIT[i]=new int[size[i]+1];
        FOR(j,1,size[i]) BIT[i][j]=0;
    }
    
    scanf("%d",&m);
    
    REP(tt,m){
        //cout<<"Proccessing..."<<tt+1<<endl;
        read(u); read(v);
        if(u==0) printf("%d\n",count(v));
        else toggle(v);
    }
}
