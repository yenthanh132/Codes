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
int T,n,b[maxn],dp[maxn][2];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
        dp[1][0]=dp[1][1]=0;
        for(int i=2; i<=n; ++i){
            dp[i][0]=max(dp[i-1][1] + (b[i-1]-1), dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0] + (b[i] - 1), dp[i-1][1] + abs(b[i-1] - b[i]));
        }
        printf("%d\n", max(dp[n][0], dp[n][1]));
    }
    return 0;
}
