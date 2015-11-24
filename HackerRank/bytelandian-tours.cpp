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

int n,deg[maxn],deg2[maxn];
ll fac[maxn];
vector<int> e[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    fac[0]=1;
    for(int i=1; i<=10000; ++i) fac[i]=fac[i-1]*i%oo;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) e[i].clear();
        if(n==2){
            puts("1");
            continue;
        }

        reset(deg,0); reset(deg2,0);
        for(int i=0; i<n-1; ++i){
            int u,v;
            scanf("%d%d",&u,&v); ++u; ++v;
            ++deg[u]; ++deg[v];
            e[u].pb(v); e[v].pb(u);
        }

        int found=-1;
        for(int i=1; i<=n; ++i) if(deg[i]>1){
            if(found==-1) found=deg[i];
            else found=0;
        }
        if(found>0){
            printf("%lld\n",fac[found]);
            continue;
        }

        ll res=2;
        for(int i=1; i<=n; ++i) if(deg[i]>1){
            int cnt=0;
            for(int j=0; j<sz(e[i]); ++j){
                int v=e[i][j];
                if(deg[v]>1) ++cnt;
            }
            if(cnt>2) res=0;
            else res = res * fac[deg[i]-cnt]%oo;
        }
        printf("%lld\n",res);
    }
}

