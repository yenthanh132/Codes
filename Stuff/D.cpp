#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=3007;

vector<int> e[maxn];
int n,m,res;
int dp[maxn];

void solve(int u){
    reset(dp,0);
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        for(int j=0; j<sz(e[v]); ++j){
            int k=e[v][j];
            ++dp[k];
        }
    }
    for(int v=1; v<=n; ++v) if(v!=u){
        res += dp[v]*(dp[v]-1)/2;
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    int u,v;
    for(int i=0; i<m; ++i){
        cin>>u>>v;
        e[u].pb(v);

    }

    res = 0;
    for(int u=1; u<=n; ++u) solve(u);
    cout<<res<<endl;
}

