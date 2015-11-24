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

int f[17][maxn],n,r,d[maxn],q;
vector<int> e[maxn];

void dfs(int u, int p){
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        d[v]=d[u]+1;
        f[0][v]=u;
        dfs(v,u);
    }
}

int lca(int u, int v){
    if(d[u]>d[v]) swap(u,v);
    for(int i=0; i<17; ++i)
        if((d[v]-d[u])>>i&1) v=f[i][v];
    if(u==v) return u;
    for(int i=16; i>=0; --i)
        if(f[i][u]!=f[i][v]){
            u=f[i][u];
            v=f[i][v];
        }
    return f[0][u];
}

int dis(int u, int v){
    int r=lca(u,v);
    return d[u]+d[v]-2*d[r];
}

bool check(int u, int r, int x, int y){
    return dis(x,y)==dis(r,x) + dis(r,y) - dis(u,r)*2;
}

int query(int x, int y){
    int u=lca(x,y);
    if(check(u,r,x,y)) return u;
    u=lca(x,r);
    if(check(u,r,x,y)) return u;
    u=lca(y,r);
    if(check(u,r,x,y)) return u;
    return -1;
}

int main(){
//    freopen("input.txt","r",stdin);
    while(scanf("%d",&n),n){
        for(int u=1; u<=n; ++u){
            e[u].clear();
            for(int i=0; i<17; ++i) f[i][u]=0;
        }

        for(int i=0,u,v; i<n-1; ++i){
            scanf("%d%d",&u,&v);
            e[u].pb(v); e[v].pb(u);
        }
        dfs(1,-1);
        r=1;
        for(int i=1; i<17; ++i) for(int u=1; u<=n; ++u)
            f[i][u]=f[i-1][f[i-1][u]];

        char s[5];
        scanf("%d",&q);
        for(int i=0,u,v; i<q; ++i){
            scanf("%s",s);
            if(s[0]=='!'){
                scanf("%d",&u);
                r=u;
            }else{
                scanf("%d%d",&u,&v);
                printf("%d\n",query(u,v));
            }
        }
    }
}

