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

const int maxn=2007;

int a[maxn],n,h;
ll dp[maxn][maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&h);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        a[i] = h-a[i];
        if(a[i]<0){
            cout<<0<<endl;
            return 0;
        }
    }

    reset(dp,0);
    dp[0][0]=1;
    for(int i=1; i<=n; ++i){
        dp[i][a[i]] = (dp[i-1][a[i]] + (a[i]>=1?dp[i-1][a[i]-1]:0))%oo;
        if(a[i]>0) dp[i][a[i]-1] = dp[i][a[i]] * a[i];
    }
    cout<<dp[n][0]<<endl;

    return 0;
}
