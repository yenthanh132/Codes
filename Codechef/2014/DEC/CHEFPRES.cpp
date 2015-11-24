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
const int maxk=107;
int n,f[maxn],k,Q,B,dp[maxn][maxk],dep[maxn],par[maxn][14];
vector<int> e[maxn];

void gmin(int &a, int b){
    if(b==-1) return;
    if(a==-1 || a>b) a=b;
}

void dfs(int u, int p){
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        par[v][0]=u;
        dep[v]=dep[u]+1;
        dfs(v,u);
        for(int c=1; c<=k; ++c) gmin(dp[u][c],dp[v][c]);
    }
    gmin(dp[u][f[u]],u);
}

int get_parent(int u, int step){
    for(int i=0; i<14; ++i) if(step>>i&1) u=par[u][i];
    return u;
}

int cal(int root, int c){
    int l=0, r=dep[root], mid, res=-1;
    while(l<=r){
        mid=(l+r)/2;
        int u=get_parent(root,mid);
        if(dp[u][c]!=-1){
            res=dp[u][c];
            r=mid-1;
        }else l=mid+1;
    }
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&k,&B);
    int u,v;
    for(int i=0; i<n-1; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(v); e[v].pb(u);
    }
    for(int i=1; i<=n; ++i) scanf("%d",&f[i]);
    reset(dp,-1); dep[B]=0;
    dfs(B,-1);
    for(int i=1; i<14; ++i) for(int u=1; u<=n; ++u) par[u][i]=par[par[u][i-1]][i-1];

    scanf("%d",&Q);
    for(int i=0; i<Q; ++i){
        scanf("%d%d",&u,&v);
        printf("%d\n",cal(u,v));
    }
}

