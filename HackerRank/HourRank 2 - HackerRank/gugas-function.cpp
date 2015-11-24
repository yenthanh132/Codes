#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000009

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


ll dp[1111111][3],n;

// 0 : 0
// 1 : 1
// 2 : 10

int main(){
//    freopen("input.txt","r",stdin);

    dp[0][0]=1;
    int res=0;
    cin>>n;
    for(int i=1; i<=n; ++i){
        //bit 0
        dp[i][0]=dp[i-1][0];
        dp[i][2]=(dp[i-1][2] + dp[i-1][1])%oo;

        //bit 1
        dp[i][1]=(dp[i-1][2] + dp[i-1][0] + dp[i-1][1])%oo;

        res = (res*2 + dp[i-1][2])%oo;
    }
    cout<<res<<endl;
}

