#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;


int toR[maxn];
int v[maxn],a[maxn],n,cnt,k;
ll sum[maxn],dp[2][maxn];
vector<int> e[maxn];

void dfs(int u, int p){
    a[++cnt]=v[u];
    sum[cnt]=sum[cnt-1]+a[cnt];
    int sc=cnt;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        dfs(v,u);
    }
    toR[sc]=cnt;
}


int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i) scanf("%d",&v[i]);
    int u,v;
    for(int i=1; i<n; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(v); e[v].pb(u);
    }
    cnt=0; sum[0]=0;
    dfs(1,-1);

    ll res=sum[n];
    for(int i=n; i>=1; --i) dp[0][i]=sum[n]-sum[i-1];
    for(int flag=1, j=1; j<=k; ++j, flag^=1){
        for(int i=n; i>=1; --i){
            dp[flag][i]=dp[flag][i+1]+a[i];
            dp[flag][i]=max(dp[flag][i],dp[1^flag][toR[i]+1]);
        }
        res=max(res,dp[flag][1]);
    }
    cout<<res<<endl;
}

