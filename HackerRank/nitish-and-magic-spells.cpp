#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10007;
const int maxk=307;

int T,n,m,k,c[maxn];
vector<int> e[maxn];
ll res;
bool free1[maxn];

ll dp[maxn][maxk];

void dfs(int u){
    free1[u]=0;
    dp[u][0]=c[u];
    dp[u][1]=c[u]*m;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(free1[v]) dfs(v);
        for(int j=0; j<=k; ++j){
            dp[u][j]=max(dp[u][j],dp[v][j]+c[u]);
            if(j>0)
                dp[u][j]=max(dp[u][j],dp[v][j-1]+c[u]*m);
        }
    }

}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1; i<=n; ++i) scanf("%d",&c[i]), e[i].clear();

        for(int i=0; i<n-1; ++i){
            int u,v;
            scanf("%d%d",&u,&v);
            ++u; ++v;
            e[u].pb(v);
        }
        reset(free1,1);
        reset(dp,128);
        res = -oo;
        for(int i=1; i<=n; ++i) if(free1[i]) dfs(i);
        for(int i=1; i<=n; ++i) for(int j=0; j<=k; ++j){
            res=max(res,dp[i][j]);
        }
        printf("%lld\n",res);
    }
}

