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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

struct query{
    int t,x,y;
}q[maxn];

int d[maxn],f[maxn][17],g[maxn][17];
int n,m,par[maxn];

vector<pii> e[maxn];
int cnt,pos[maxn];

void dfs(int u){

    for(int j=0; j<sz(e[u]); ++j){
        int v=e[u][j].first, id = e[u][j].second;
        d[v]=d[u]+1;
        f[v][0]=u;
        g[v][0]=id;
        dfs(v);
    }
}

pii lca(int u, int v){
    if(d[u]>d[v]) swap(u,v);
    int val=0;
    for(int i=0; i<17; ++i) if(((d[v]-d[u])>>i)&1){
        val=max(val,g[v][i]);
        v=f[v][i];
    }
    if(u==v) return pii(u,val);
    return pii(-1,-1);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    reset(par,-1);
    for(int i=1; i<=m; ++i){
        scanf("%d%d",&q[i].t,&q[i].x);
        if(q[i].t==1){
            scanf("%d",&q[i].y);
            par[q[i].x]=q[i].y;
            e[q[i].y].pb(pii(q[i].x,i));
        }else if(q[i].t==3) scanf("%d",&q[i].y);
    }
    for(int u=1; u<=n; ++u) if(par[u]==-1){
        d[u]=1;
        dfs(u);
    }
    for(int k=1; k<17; ++k){
        for(int u=1; u<=n; ++u){
            f[u][k]=f[f[u][k-1]][k-1];
            g[u][k]=max(g[u][k-1],g[f[u][k-1]][k-1]);
        }
    }
    cnt=0;
    for(int i=1; i<=m; ++i)
        if(q[i].t==2){
            ++cnt;
            pos[cnt]=i;
        }else if(q[i].t==3){
            int p = pos[q[i].y];
            pii ans = lca(q[i].x,q[p].x);
            if(ans.first !=-1 && ans.first == q[i].x && ans.second <= p) puts("YES");
            else puts("NO");
        }
    return 0;
}
