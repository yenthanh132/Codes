#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int dmod=998244353;

int n,p,m;
int dp[1007][55][55];

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>p>>m;
    dp[0][0][0]=1;
    ll mul=1;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<p; ++j) for(int k=0; k<=m; ++k) if(dp[i-1][j][k])
            for(int x=0; x<=9 && x+k<=m; ++x)
                dp[i][(j+x*mul)%p][k+x] = (dp[i][(j+x*mul)%p][k+x] + dp[i-1][j][k])%dmod;
        mul=mul*10%p;
    }
    ll res=0;
    for(int k=0; k<=m; ++k){
        res = (res+dp[n][0][k])%dmod;
        cout<<res<<' ';
    }
}

