#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=4096;

ll dp[maxn][maxn];

int main(){
//    freopen("input.txt","r",stdin);
    dp[0][0]=1;
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; ++i) for(int v=0; v<maxn; ++v) if(dp[i-1][v]){
        dp[i][v] = (dp[i][v] + dp[i-1][v]) % (m*2);
        dp[i][v^i] = (dp[i][v^i] + dp[i-1][v]*2) % (m*2);
    }
    ll total = 1;
    for(int i=1; i<=n; ++i) total = total*3 % (m*2);
    ll cnt = dp[n][0];
    ll res = ((total - cnt + 2*m)/2 + cnt)%m;
    cout<<res<<endl;
}

