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

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t = mypow(base,n/2)
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

int main(){
    freopen("input.txt","r",stdin);
    for(int i=1; i<=180; ++i){
        dp[i][0]=1;
        for(int j=1; j<=i; ++j){
            int x=i-j;
            dp[i][j]=dp[i][j-1]*mypow(2,x);
        }
    }
}

