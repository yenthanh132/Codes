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

#define maxn 100007

int n,k,countcom,ans[maxn],l[maxn][17],d[maxn],con[maxn],com[maxn],parent[maxn],size[maxn],pos[maxn];
vector<int> a[maxn],IT[maxn];
vector<pii> ds;
bool free1[maxn];

void dfs1(int u){
    free1[u]=false; 
    vector<int>::iterator it;
    int v, m=int(log(d[u])/log(2));
    for(int i=1;i<=m;i++) l[u][i]=l[l[u][i-1]][i-1];
    con[u]=1;
    for(it=a[u].begin();it<a[u].end();it++){
        v=*it;
        if (free1[v]){
            d[v]=d[u]+1; l[v][0]=u;
            dfs1(v);
            con[u]+=con[v];
        }
    }
}

int lca(int u,int v){
    if(d[u]>d[v]) swap(u,v);
    int i;
    for(i=16;i>=0;i--) if(((d[v]-d[u]) >> i ) & 1) v=l[v][i];
    if(u==v) return u;
    for(i=16;i>=0;i--) if(l[u][i]!=l[v][i]) u=l[u][i], v=l[v][i];
    return l[u][0];
}

void dfs2(int u){
    free1[u]=false;
    if (com[u]==0){
        com[u]=++countcom;
        size[countcom]=1;
        pos[u]=1;
    }
    int v,maxc=0,x=0;
    vector<int>::iterator it;
    for(it=a[u].begin(); it<a[u].end(); it++){
        v=*it;
        if(free1[v] && maxc<con[v]){
            maxc=con[v];
            x=v;
        }
    }
    if(x) parent[x]=parent[u], com[x]=com[u], pos[x]=pos[u]+1, size[com[u]]++;
    for(it=a[u].begin(); it<a[u].end(); it++){
        v=*it;
        if(free1[v]){
            if (v!=x) parent[v]=u;
            dfs2(v);
        }
    }
} 

// For IT

void IncIT(int& id, int i, int l, int r, int& s, int& f){
    if(r<s || l>f) return;
    if(s<=l && r<=f){IT[id][i]++; return;}
    int mid=(l+r)/2;
    IncIT(id,i*2,l,mid,s,f); IncIT(id,i*2+1,mid+1,r,s,f);
}

int ITres;

void GetIT(int& id, int i, int l, int r, int& p){
    if(p<l || p>r) return;
    ITres+=IT[id][i];
    if(l==r) return;
    int mid=(l+r)/2;
    GetIT(id,i*2,l,mid,p); GetIT(id,i*2+1,mid+1,r,p);
}

void Add(int id, int l, int r){
    if(l>r) return;
    IncIT(id,1,1,size[id],l,r);
}

int GetIT(int id, int p){
    ITres=0;
    GetIT(id,1,1,size[id],p);
    return ITres;
}

///////////////////////////////////////////  

void AddSeg(int u, int v){
    int i;
    while(com[v]!=com[u]){ 
        Add(com[v],1,pos[v]);
        v=parent[v];
    }
    Add(com[u],pos[u]+1,pos[v]);
}

int GetVal(int u, int v){
    if (d[u]>d[v]) swap(u,v);
    if(com[u]==com[v]) return GetIT(com[u],pos[u]+1);
    else return GetIT(com[v],1);
}
//#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    int u,v,i,root;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        a[u].pb(v); a[v].pb(u);
        ds.pb(pii(u,v));
    }
    
    reset(free1,true); reset(con,0);
    d[1]=0; dfs1(1);
    
    countcom=0;
    reset(free1,true); reset(com,0); reset(parent,0); reset(size,0);
    dfs2(1);
    
    for(i=1;i<=countcom;i++) IT[i].resize((size[i]+1)*4,0);
    
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        scanf("%d%d",&u,&v);
        root=lca(u,v);
        AddSeg(root,u); AddSeg(root,v);
    }
    
    for(i=0;i<ds.size();i++) printf("%d ",GetVal(ds[i].fi,ds[i].se));
    printf("\n");
    
    //getch();
    return 0;
}
