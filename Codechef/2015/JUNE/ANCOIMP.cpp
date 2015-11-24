#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1007;
int T,n;
vector<int> e[maxn];
int color[maxn],y[maxn];
vector<int> cnt1,cnt2;
vector< vector<int> > a1, a2;
bool fail;

const int base=1000;
int dp[maxn][maxn*2];


void dfs(int u, int c){
    if(fail) return;
    color[u]=c;
    if(c==1) cnt1.pb(u); else cnt2.pb(u);
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(!color[v]) dfs(v,3-c);
        else if(color[v]==c){
            fail=1;
            return;
        }
    }
}

bool doColor(int u){
    cnt1.clear(); cnt2.clear();
    fail = 0;
    dfs(u,1);
    return !fail;
}

int main(){

//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){

        scanf("%d",&n);
        for(int i=1; i<=n; ++i) e[i].clear();
        int v;
        for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j){
            scanf("%d",&v);
            if(v==1) e[i].pb(j);
        }

        a1.clear(); a2.clear();
        reset(color,0);
        bool ok=1;
        for(int i=1; i<=n; ++i) if(!color[i]){
            if(!doColor(i)){
                ok=0;
                break;
            }
            a1.pb(cnt1); a2.pb(cnt2);
        }

        //dp to divide equally
        if(ok){
            int cnt=sz(a1);
            for(int i=0; i<=cnt; ++i) for(int j=base-n; j<=base+n; ++j) dp[i][j]=0;
            dp[0][base]=1;
            for(int i=0; i<cnt; ++i) for(int j=base-n; j<=base+n; ++j) if(dp[i][j]){
                int diff = sz(a1[i])-sz(a2[i]);
                if(0<=j+diff && j+diff<=base*2) dp[i+1][j+diff] = 1;
                if(0<=j-diff && j-diff<=base*2) dp[i+1][j-diff] = 1;
            }

            int best = 0;
            for(int j=base-n; j<=base+n; ++j) if(dp[cnt][j] && abs(base-j) < abs(base-best)) best=j;

            for(int i=cnt-1; i>=0; --i){
                int diff = sz(a1[i])-sz(a2[i]);
                if(0<=best-diff && best-diff<=base*2 && dp[i][best - diff]){
                    best -= diff;
                    for(int j=0; j<sz(a1[i]); ++j) y[a1[i][j]]=1;
                    for(int j=0; j<sz(a2[i]); ++j) y[a2[i][j]]=0;
                }else{
                    best += diff;
                    for(int j=0; j<sz(a1[i]); ++j) y[a1[i][j]]=0;
                    for(int j=0; j<sz(a2[i]); ++j) y[a2[i][j]]=1;
                }
            }


            for(int i=1; i<n; ++i) printf("%d ",y[i]);
            printf("%d\n",y[n]);
        }else
            puts("-1");
    }
}

