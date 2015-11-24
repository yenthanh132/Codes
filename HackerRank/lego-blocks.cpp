#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

const int maxn=1007;
const int oo = 1000000007;
int f[maxn], dp[maxn], dp2[maxn];

long long mypow(int base, int n){
    if(n==0) return 1;
    long long t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

int solve(int m, int n){
    dp[1]=dp2[1]=1;
    for(int i=2; i<=n; ++i){
        dp[i] = dp2[i] = mypow(f[i], m);
        for(int j=1; j<i; ++j) dp[i] = (dp[i] - 1ll*dp[j]*dp2[i-j]%oo + oo)%oo;
    }
    return dp[n];
}

int main(){
    //freopen("input.txt","r",stdin);
    f[0]=1;
    for(int i=1; i<=1000; ++i){
        f[i]=0;
        for(int j=1; j<=4 && i-j>=0; ++j) f[i] = (f[i] + f[i-j])%oo;
    }
    int T,m,n;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%d",&m,&n);
        printf("%d\n",solve(m,n));
    }
    return 0;
}
