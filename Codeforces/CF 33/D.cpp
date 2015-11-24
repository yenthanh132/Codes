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

const int maxn=1007;

int n,m,k,d[maxn],pos[maxn],f[maxn][10],list[maxn],cnt;
struct point{ll x,y;} a[maxn];
struct cir{ll x,y,r;} b[maxn];
vector<int> link[maxn],link2[maxn];
bool free1[maxn];

bool inside(const cir &a, const cir &b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) <= b.r*b.r && a.r<b.r;
}

bool inside(const point &a, const cir &b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) <= b.r*b.r;
}



void dfs(int u){
    int v;
    REP(i,sz(link2[u])){
        v=link2[u][i];
        d[v]=d[u]+1;
        f[v][0]=u;
        dfs(v);
    }
}

int lca(int u, int v){
    if(d[u]>d[v]) swap(u,v);
    REPD(i,10) if(((d[v]-d[u])>>i)&1) v=f[v][i];
    if(u==v) return u;
    REPD(i,10)
        if(f[u][i]!=f[v][i]){
            u=f[u][i];
            v=f[v][i];
        }
    return f[u][0];
}

int dis(int u, int v){
    int r=lca(u,v);
    return d[u]+d[v]-d[r]*2;
}

//dfs2 rebuild the tree
void dfs2(int u){
    free1[u]=0;
    int v;
    REP(i,sz(link[u])){
        v=link[u][i];
        if(!free1[v]) continue;
        dfs2(v);
    }
    list[cnt--]=u;
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int maxd,x,y;
    
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%I64d%I64d",&a[i].x,&a[i].y);
    FOR(i,1,m) scanf("%I64d%I64d%I64d",&b[i].r,&b[i].x,&b[i].y);
    reset(d,0);
    FOR(i,1,m) FOR(j,1,m) if(i!=j && inside(b[i],b[j])){
        link[j].pb(i);
        d[i]++;
    }
    FOR(i,1,m) if(d[i]==0) link[m+1].pb(i);
    m++;
    
    //build tree
    cnt=m; reset(free1,1);
    dfs2(m);
    reset(free1,1);
    FORD(i,m,1){
        x=list[i];
        REP(j,sz(link[x])){
            y=link[x][j];
            if(free1[y]){
                link2[x].pb(y);
                free1[y]=0;
            }
        }
    }
    //------
    
    d[m]=0;
    dfs(m);
    FOR(i,1,9) FOR(j,1,m) f[j][i]=f[f[j][i-1]][i-1];
    
    FOR(i,1,n){
        pos[i]=m;
        maxd=0;
        FOR(j,1,m) if(inside(a[i],b[j]) && maxd<d[j]){
            maxd=d[j];
            pos[i]=j;
        }
    }
    
    REP(i,k){
        scanf("%d%d",&x,&y);
        printf("%d\n",dis(pos[x],pos[y]));
    }
    
    return 0;
}
    
