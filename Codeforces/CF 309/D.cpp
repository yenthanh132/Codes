#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef pair<double,int> pdi;
typedef long long ll;

const int maxn=100007;

bool locked[maxn],del[maxn];
int n,m,deg[maxn],k;
double vdeg[maxn];
set<pdi> mys;
vector<int> e[maxn];
vector<int> ans;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    reset(locked,0);
    int u,v;
    for(int i=0; i<k; ++i){
        scanf("%d",&v);
        locked[v]=1;
    }
    for(int i=0; i<m; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    reset(del,0);

    for(int u=1; u<=n; ++u) if(!locked[u]){
        deg[u]=0;
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i];
            if(!locked[v]) ++deg[u];
        }
        vdeg[u]=1.0*deg[u]/sz(e[u]);
        mys.insert(pdi(vdeg[u],u));
    }

    double res=-1;
    while(!mys.empty()){
        pdi val = *mys.begin(); mys.erase(mys.begin());
        int u=val.second;
        if(del[u]) continue;
        res = max(res, val.first);
        del[u]=1;
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i];
            if(!locked[v] && !del[v]){
                --deg[v];
                vdeg[v]=1.0*deg[v]/sz(e[v]);
                mys.insert(pdi(vdeg[v],v));
            }
        }
    }

    //do again
    mys.clear();
    reset(del,0);

    for(int u=1; u<=n; ++u) if(!locked[u]){
        deg[u]=0;
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i];
            if(!locked[v]) ++deg[u];
        }
        vdeg[u]=1.0*deg[u]/sz(e[u]);
        mys.insert(pdi(vdeg[u],u));
    }

    while(!mys.empty()){
        pdi val = *mys.begin(); mys.erase(mys.begin());
        int u=val.second;
        if(del[u]) continue;
        if(fabs(res - val.first)<1e-9){
            ans.clear();
            for(int u=1; u<=n; ++u) if(!del[u] && !locked[u]) ans.pb(u);
            printf("%d\n",sz(ans));
            for(int i=0; i<sz(ans); ++i) printf("%d ",ans[i]);
            puts("");
            return 0;
        }
        del[u]=1;
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i];
            if(!locked[v] && !del[v]){
                --deg[v];
                vdeg[v]=1.0*deg[v]/sz(e[v]);
                mys.insert(pdi(vdeg[v],v));
            }
        }
    }

    puts("OH NO!!!!");
}

