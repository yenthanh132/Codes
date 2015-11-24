#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000007ll

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

ll f[maxn];
int lst[maxn],n,m,T,cnt,val[maxn];
vector<pii> e[maxn];
bool free1[maxn];

void dfs(int u){
    int v;
    free1[u]=0;
    for(int i=0; i<sz(e[u]); ++i){
        v=e[u][i].first;
        if(free1[v]) dfs(v);
    }
    lst[cnt--]=u;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d%d",&n,&m);
        for(int u=1; u<=n; ++u) scanf("%d",&val[u]);
        for(int u=1; u<=n; ++u) e[u].clear();
        int u,v,w;
        for(int i=0; i<m; ++i){
            scanf("%d%d%d",&u,&v,&w);
            e[u].pb(pii(v,w));
        }
        cnt=n; reset(free1,1);
        dfs(1);
        f[1]=val[1];
        for(int u=2; u<=n; ++u) f[u]=-oo;
//        for(int i=1; i<=n; ++i) cout<<lst[i]<<' '; cout<<endl;
        for(int i=cnt+1; i<=n; ++i){
            u=lst[i];
            for(int j=0; j<sz(e[u]); ++j){
                v=e[u][j].first; w=e[u][j].second;
                f[v]=max(f[v],f[u]-w+val[v]);
            }
        }
        ll res = f[1];
        for(int u=1; u<=n; ++u) res=max(res,f[u]);
        cout<<res<<endl;
    }
}

