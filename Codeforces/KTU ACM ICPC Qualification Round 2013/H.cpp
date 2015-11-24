#include <bits/stdc++.h>

#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> iii;
typedef long long ll;

const int maxn=10007;

vector<int> e[maxn];
int cnt,weight[maxn],com[maxn],T,n,m;
bool free1[maxn];

void dfs(int u){
    free1[u]=0;
    com[u]=cnt;
    ++weight[cnt];
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(free1[v]) dfs(v);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        printf("Case #%d:\n",tt);
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; ++i) free1[i]=1, e[i].clear();
        int u,v;
        for(int i=0; i<m; ++i){
            scanf("%d%d",&u,&v);
            e[u].pb(v);
            e[v].pb(u);
        }
        cnt=0;
        for(int u=1; u<=n; ++u) if(free1[u]){
            ++cnt;
            weight[cnt]=0;
            dfs(u);
        }
        for(int i=1; i<n; ++i){
            printf("%d ",weight[com[i]]-1);
        }
        printf("%d\n",weight[com[n]]-1);
    }
    return 0;
}


