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

int n,m,k,t;
double f[2][maxn];
vector<int> e[maxn];

int myround(double v){
    return int(round(v)+1e-9);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int u=1; u<=n; ++u) e[u].clear();
        int x,y;
        for(int i=0; i<m; ++i){
            scanf("%d%d",&x,&y); ++x; ++y;
            e[x].pb(y); e[y].pb(x);
        }
        for(int u=1; u<=n; ++u) scanf("%lf",&f[0][u]);
        int flag=0;
        for(int i=0; i<k; ++i){
            flag^=1;
            for(int u=1; u<=n; ++u){
                double t=0;
                for(int i=0; i<sz(e[u]); ++i){
                    int v=e[u][i];
                    t+=f[1^flag][v]/sz(e[v]);
                }
                f[flag][u]=t;
            }
            bool ok=1;
            for(int u=1; u<=n; ++u) if(myround(f[flag][u])!=myround(f[1^flag][u])){
                ok=0;
                break;
            }
            if(ok) break;
        }
        sort(f[flag]+1,f[flag]+n+1,greater<double>());
        for(int i=1; i<=5; ++i) printf("%d ",myround(f[flag][i]));
        puts("");
    }
}

