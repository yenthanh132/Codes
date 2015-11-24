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

const int maxn=100007;
const int maxk=27;
const int oo=1000000009;

typedef long long ll;

ll C[maxk][maxk];
ll f[maxn][maxk], kpow[maxk][maxn], g[maxn][maxk];
ll dp[maxn][maxk];
int T,n,k;

//f[i][j] = number of string with len i using at most j different first characters, which doesn't have any proper suffix and prefix matched
//g[i][j] = number of string with len i using at most j different first characters, which has at least 1 proper suffix and prefix matched
//dp[i][j] = number of string with len i using exactly j different first characters, which has at least 1 proper suffix and prefix matched

int main(){
    C[0][0]=1;
    for(int i=1; i<=26; ++i){
        C[i][0]=1;
        for(int j=1; j<=i; ++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%oo;
    }
    for(int k=1; k<=26; ++k){
        kpow[k][0]=1;
        for(int i=1; i<=100000; ++i) kpow[k][i]=kpow[k][i-1]*k%oo;
    }

    for(int k=1; k<=26; ++k){
        f[0][k]=1;
        for(int i=1; i<=100000; ++i){
            f[i][k] = f[i-1][k] * k % oo;
            if(i%2==0) f[i][k] = ( f[i][k] - f[i/2][k] + oo ) % oo;
            g[i][k] = ( kpow[k][i] - f[i][k] + oo ) % oo;
            dp[i][k]=g[i][k];
            for(int x=1; x<k; ++x)
                dp[i][k] = (dp[i][k] - dp[i][x]*C[k][x]%oo + oo)%oo;

        }
    }

    //freopen("input.txt","r",stdin);

    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%d",&n,&k);
        printf("%lld\n",dp[n][k]*C[26][k]%oo);
    }

    return 0;
}

