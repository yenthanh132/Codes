#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll dp[222][222];

int main(){
//    freopen("input.txt","r",stdin);
    dp[0][0]=1;
    for(int i=1; i<=200; ++i){
        for(int j=0; j<=200; ++j){
            dp[i][j]=dp[i-1][j]; //add 0
            if(j>=i) dp[i][j]+=dp[i][j-i]; //inc 1 for all
        }
    }

    int T,n,k;
    cin>>T;
    while(T--){
        cin>>n>>k;
        ll res=0;
        for(int v=1; v*k<=n; ++v){
            res += dp[v][n-v*k];
        }
        cout<<res<<endl;
    }
}

