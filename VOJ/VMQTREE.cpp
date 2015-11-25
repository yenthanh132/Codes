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

const int maxn=50007;

int n,q,d[maxn],maxbot[maxn][3],trace[maxn][3],maxtop[maxn];
int p[maxn][16],maxf[maxn][16],maxg[maxn][16],f[maxn],g[maxn];
vector<int> a[maxn];
bool free1[maxn];

void dfs(int u){
    free1[u]=0;
    int v,j;
    REP(i,3) maxbot[u][i]=0, trace[u][i]=u;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(!free1[v]) continue;
        p[v][0]=u;
        d[v]=d[u]+1;
        dfs(v);
        j=0;
        while(j<3 && maxbot[u][j]>=maxbot[v][0]+1) j++;
        if(j<3){
            FORD(z,2,j+1){
                maxbot[u][z]=maxbot[u][z-1];
                trace[u][z]=trace[u][z-1];
            }
            maxbot[u][j]=maxbot[v][0]+1;
            trace[u][j]=trace[v][0];
        }
        
    }
}

void dfs2(int u){
    free1[u]=0;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(!free1[v]) continue;
        if(maxbot[v][0]+1==maxbot[u][0])
            maxtop[v]=max(maxtop[u]+1,maxbot[u][1]+1);
        else maxtop[v]=max(maxtop[u]+1,maxbot[u][0]+1);
        if(maxbot[u][0]==maxbot[v][0]+1) f[v]=d[trace[u][1]]; else f[v]=d[trace[u][0]];
        g[v]=f[v]-d[u]*2;
        p[v][0]=u;
        maxf[v][0]=f[v];
        maxg[v][0]=g[v];
        dfs2(v);
    }
}

int jump(int u, int step){
    REP(i,16) if((step>>i)&1) u=p[u][i];
    return u;
}

int lca(int u, int v){
    if(d[u]>d[v]) swap(u,v);
    v=jump(v,d[v]-d[u]);
    if(u==v) return u;
    REPD(i,16)
        if(p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    return p[u][0];
}

int getf(int u, int step){
    int res=-oo;
    REP(i,16) if((step>>i)&1){
        res=max(res,maxf[u][i]);
        u=p[u][i];
    }
    return res;
}

int getg(int u, int step){
    int res=-oo;
    REP(i,16) if((step>>i)&1){
        res=max(res,maxg[u][i]);
        u=p[u][i];
    }
    return res;
}

int getroot(int r, int u, int v){
    int c0,c1,c2;
    c0=c1=c2=0;
    if(trace[r][0]) c0=jump(trace[r][0],d[trace[r][0]]-d[r]-1);
    if(trace[r][1]) c1=jump(trace[r][1],d[trace[r][1]]-d[r]-1);
    if(trace[r][2]) c2=jump(trace[r][2],d[trace[r][2]]-d[r]-1);
    u=jump(u,d[u]-d[r]-1); v=jump(v,d[v]-d[r]-1);
    if(c0 && c0!=u && c0!=v) return maxbot[r][0];
    if(c1 && c1!=u && c1!=v) return maxbot[r][1];
    if(c2 && c2!=u && c2!=v) return maxbot[r][2];
    return 0;
}

//#include <conio.h>
int main(){
    int test,u,v,r,mid,res;
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&test);
    REP(tt,test){
        scanf("%d",&n);
        FOR(i,1,n) a[i].clear();
        REP(i,n-1){
            scanf("%d%d",&u,&v);
            a[u].pb(v);
            a[v].pb(u);
        }
        
        reset(free1,1);
        maxtop[1]=0; d[1]=0;
        dfs(1);
        reset(free1,1);
        dfs2(1);
        FOR(i,1,15) FOR(u,1,n){
            p[u][i]=p[p[u][i-1]][i-1];
            maxf[u][i]=max(maxf[u][i-1], maxf[p[u][i-1]][i-1]);
            maxg[u][i]=max(maxg[u][i-1], maxg[p[u][i-1]][i-1]);
        }
        
        scanf("%d",&q);
        REP(index,q){
            scanf("%d%d",&u,&v);
            r=lca(u,v);
            if(d[v]-d[r]>d[u]-d[r]) swap(u,v);
            mid=jump(u,(d[u]+d[v]-d[r]*2)/2);
            res=maxtop[r] + min(d[u]-d[r], d[v]-d[r]);
            if(u!=r) res=max(res, maxbot[u][0]);
            if(v!=r) res=max(res, maxbot[v][0]);
            if(mid==r){
                res=max(res,getg(u,d[u]-d[mid]-1) + d[u]);
                res=max(res,getg(v,d[v]-d[mid]-1) + d[v]);
            }else{
                if(u!=r) res=max(res,getg(u,d[u]-d[mid]) + d[u]);
                if(v!=r) res=max(res,getg(v,d[v]-d[r]-1) + d[v]);
                if(mid!=r) res=max(res,getf(mid,d[mid]-d[r]-1) + d[v] - d[r]*2);
            }
            res=max(res,getroot(r,u,v) + min(d[u]-d[r], d[v]-d[r]));
            printf("%d\n",res);
        }
    }
    
    //getch();
    return 0;
}
