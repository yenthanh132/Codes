#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=5007;
const int maxk=31;

ll dp[maxn][maxk];
int n,m,k;
bool inDFS[maxn],free1[maxn];
int cycle[maxn],cycleCnt,trace[maxn];
vector<int> cycleVecList[maxn];
vector<int> e[maxn];

void dfs(int u){
    free1[u]=0;
    inDFS[u]=1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(free1[v]){
            trace[v]=u;
            dfs(v);
        }else if(inDFS[v] && trace[u]!=v){
            ++cycleCnt;
            cycleVecList[cycleCnt].clear();

            cycle[v]=cycleCnt;
            cycleVecList[cycleCnt].pb(v);

            int t=u;
            while(t!=v){
                cycle[t]=cycleCnt;
                cycleVecList[cycleCnt].pb(t);
                t=trace[t];
            }
        }
    }
    inDFS[u]=0;
}

ll res;

void calc(int u);

void calcNode(int u){
    dp[u][1]=1;
    ll f[maxk];
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(!free1[v]) continue;
        if(cycle[u] && cycle[u]==cycle[v]) continue;
        calc(v);
        reset(f,0);
        for(int val=0; val<=k; ++val) if(dp[u][val]){
            for(int val2=0; val2+val<=k; ++val2) if(dp[v][val2]){
                f[val+val2] += dp[u][val]*dp[v][val2];
                f[val+val2] %= oo;
            }
        }
        for(int val=0; val<=k; ++val) dp[u][val]=(dp[u][val]+f[val])%oo;
    }
    for(int val=1; val<=k; ++val) res=(res+dp[u][val])%oo;
}

void calc(int u){
    free1[u]=0;
    if(!cycle[u]){
        calcNode(u);
        return;
    }

    int id=cycle[u];
    for(int i=0; i<sz(cycleVecList[id]); ++i){
        int v=cycleVecList[id][i];
        free1[v]=0;
        calcNode(v);
    }

    int len=sz(cycleVecList[id]);
    ll f[maxk],g[maxk];
    ll root[maxk];
    reset(root,0);
    for(int i=0; i<len; ++i){
        reset(f,0);
        f[0]=1;
        for(int j=0; j<len; ++j){
            if(j==len-1 && i>0) break;
            reset(g,0);
            int v=cycleVecList[id][(i+j)%len];
            for(int val=1; val<=k; ++val) if(dp[v][val])
                for(int val2=0; val2+val<=k; ++val2) if(f[val2]){
                    g[val+val2] += dp[v][val]*f[val2];
                    g[val+val2] %= oo;
                }

            for(int val=0; val<=k; ++val) f[val]=g[val];

            if(j>0){
                for(int val=1; val<=k; ++val) res=(res+f[val])%oo;
                if(i==0 || i+j>=len){
                    for(int val=1; val<=k; ++val) root[val]=(root[val]+f[val])%oo;
                }
            }

        }

    }
    for(int val=1; val<=k; ++val) dp[u][val]=(dp[u][val]+root[val])%oo;
}

int main(){
//    freopen("input.txt","r",stdin);

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        for(int u=1; u<=n; ++u) e[u].clear();
        for(int i=0,u,v; i<m; ++i){
            scanf("%d%d",&u,&v);
            e[u].pb(v);
            e[v].pb(u);
        }
        cycleCnt=0;
        reset(free1,1);
        reset(inDFS,0);
        reset(cycle,0);
        reset(dp,0);
        dfs(1);
        reset(free1,1);
        res=0;
        calc(1);
        printf("%lld\n",res);
    }
}

