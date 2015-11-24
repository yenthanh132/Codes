#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2007;

int weight[maxn],cost[maxn],n,m,res,d[maxn],trace[maxn],number,last[maxn],arr[maxn],dp[maxn][maxn];
bool locked[maxn];
vector<int> e[maxn];
vector<int> lst;

void dfs(int u, int p){
    lst.pb(u);
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p || locked[v]) continue;
        d[v]=d[u]+1;
        trace[v]=u;
        dfs(v,u);
    }
}

void dfs2(int u, int p){
    arr[++number] = u;
    int pos = number;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p || locked[v]) continue;
        dfs2(v,u);
    }
    last[pos] = number;
}

void jump(int u){

    lst.clear();
    d[u]=0; dfs(u,-1);

    int x=u;
    for(int i=0; i<sz(lst); ++i) if(d[lst[i]]>d[x]) x=lst[i];

    lst.clear();
    d[x]=0; dfs(x,-1);

    int y=x;
    for(int i=0; i<sz(lst); ++i) if(d[lst[i]]>d[y]) y=lst[i];
    lst.clear();
    lst.pb(y);
    while(x!=y){
        y=trace[y];
        lst.pb(y);
    }

    int center = lst[sz(lst)/2];

    number=0;
    dfs2(center,-1);

    for(int i=1; i<=number; ++i) for(int v=0; v<=m; ++v) dp[i][v]=-oo;
    for(int i=1; i<=number; ++i) for(int v=0; v<=m; ++v){
        int u = arr[i];
        if(i==1){
            if(v>=weight[u]) dp[1][v]=cost[u];
        }else{
            if(v>=weight[u]) dp[i][v] = max(dp[i][v], dp[i-1][v-weight[u]] + cost[u]);
            dp[last[i]][v] = max(dp[last[i]][v], dp[i-1][v]);
        }
        res=max(res, dp[i][v]);

    }

    locked[center] = 1;
    for(int i=0; i<sz(e[center]); ++i){
        int v=e[center][i];
        if(!locked[v]) jump(v);
    }
}

int main(){
//   freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; ++i) scanf("%d",weight+i);
        for(int i=1; i<=n; ++i) scanf("%d",cost+i);
        for(int i=1; i<=n; ++i) e[i].clear();
        for(int i=0; i<n-1; ++i){
            int x,y;
            scanf("%d%d",&x,&y);
            e[x].pb(y); e[y].pb(x);
        }
        res=0;
        reset(locked,0);
        jump(1);
        printf("%d\n",res);
    }
}

