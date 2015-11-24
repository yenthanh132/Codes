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

vector<pii> e[maxn];
ll total;
int n,d[maxn];

void dfs(int u, int p){
    d[u]=1;
    int v;
    for(int i=0; i<sz(e[u]); ++i){
        v=e[u][i].first;
        if(v==p) continue;
        dfs(v,u);
        d[u]+=d[v];
    }
    for(int i=0; i<sz(e[u]); ++i){
        v=e[u][i].first;
        if(v==p) continue;
        total += 1ll*(e[u][i].second)*d[v]*(n-d[v]);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int u=1; u<=n; ++u) e[u].clear();
        int x,y,w;
        for(int i=0; i<n-1; ++i){
            scanf("%d%d%d",&x,&y,&w);
            ++x; ++y;
            e[x].pb(pii(y,w));
            e[y].pb(pii(x,w));
        }
        total=0;
        dfs(1,-1);
        printf("%0.9lf\n",2.0*total/n/(n-1));
    }
}

