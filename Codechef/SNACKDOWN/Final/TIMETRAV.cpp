#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;

int depth[maxn],n,val[maxn],cnt,k,a[maxn],dp[maxn];
vector<int> e[maxn];
vector<int> layerVec[maxn];
int Next[maxn];

void dfs(int u, int d, int par){
    val[u] = 1;
    layerVec[d].pb(u);
    depth[u] = d;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==par) continue;
        dfs(v,d+1,u);
        val[u] += val[v];
        depth[u] = max(depth[u], depth[v]);
    }

}

int cal(int pos){
    if(pos>cnt) return 0;
    int d = Next[pos];
    if(d==oo) return 0;
    if(dp[d]!=-1) return dp[d];
    int &res = dp[d]; res=oo;
    for(int i=0; i<sz(layerVec[d]); ++i){
        int u = layerVec[d][i];
        int cost = val[u];
        res = min(res, cost + cal(depth[u]+1));
    }
    return res;
}

int main(){

//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int u=1; u<=n; ++u) e[u].clear();
        int u,v;
        for(int i=0; i<n-1; ++i){
            scanf("%d%d",&u,&v);
            e[u].pb(v);
            e[v].pb(u);
        }
        scanf("%d",&k);
        for(int i=1; i<=k; ++i) scanf("%d",&a[i]);
        sort(a+1,a+k+1);


        dfs(1,1,-1);
        cnt = depth[1];

        int toRight = oo, it=k;
        for(int i=cnt; i>=1; --i){
            if(it>0 && a[it]==i){
                toRight = i;
                --it;
            }
            Next[i] = toRight;
        }

        for(int i=1; i<=cnt; ++i) dp[i]=-1;
        cout<<cal(1)<<endl;

        //clean
        for(int i=1; i<=cnt; ++i) layerVec[i].clear();
    }
}

