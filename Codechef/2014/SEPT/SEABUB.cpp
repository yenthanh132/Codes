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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

double dp[maxn][maxn*maxn];
int T,n,a[maxn];
ll k;

int main(){

    dp[0][0]=1;
    for(int i=1; i<=100; ++i){
        for(int j=0; j<=i*(i-1)/2; ++j){
            dp[i][j]=0;
            for(int v=0; v<i; ++v) dp[i][j] += dp[i-1][j-v]/i;
        }
    }

    freopen("input.txt","r",stdin);
    scanf("%d",&T);

    for(int tt=0; tt<T; ++tt){
        scanf("%d%lld",&n,&k);
        int inv = 0;
        double res, res2;

        for(int i=1; i<=n; ++i){
            scanf("%d",&a[i]);
            for(int j=1; j<i; ++j) if(a[j]>a[i]) ++inv;
        }
        if(inv <= k){
            res = 0;
        }else if(k==0){
            res = inv;
        }else{
            res = inv - k;
            res2 = 0;
            for(int j=0; j<=n*(n-1)/2; ++j)
                res2 += dp[n][j]*max(0ll, j-(k-1));
            res = min(res, res2);
        }
        printf("%0.9lf\n",res);
    }

    return 0;
}
