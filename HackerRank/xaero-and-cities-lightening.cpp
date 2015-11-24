#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=500007;

int n,val[maxn];
vector<int> e[maxn];
int dp[maxn][2];

void dfs(int u, int p){
    int cost=!val[u];
    dp[u][0]=0;
    dp[u][1]=cost;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        dfs(v,u);
        dp[u][0]+=dp[v][1];
        dp[u][1]+=min(dp[v][0],dp[v][1]);
    }
}

int solve(){
    dfs(1,-1);
    return min(dp[1][0],dp[1][1]);
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int u=1; u<=n; ++u) e[u].clear();
        for(int u=1; u<=n; ++u) scanf("%d",&val[u]);
        for(int i=0; i<n-1; ++i){
            int u,v;
            scanf("%d%d",&u,&v);
            e[u].pb(v); e[v].pb(u);
        }
        int res=solve();
        printf("%d\n",res);
    }
}

