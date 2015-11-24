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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100;

int dp[maxn][maxn],a[maxn],e,r,n;

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%d%d%d",&e,&r,&n);
        FOR(i,1,n) scanf("%d",&a[i]);
        reset(dp,0);
        dp[1][e]=1;
        FOR(i,1,n-1) FOR(v,0,e) if(dp[i][v])
            FOR(t,0,v)
                dp[i+1][min(v-t+r,e)]=max(dp[i+1][min(v-t+r,e)], dp[i][v] + a[i]*t);
        int res=-1;
        FOR(v,0,e) res=max(res,dp[n][v]+v*a[n]);
        printf("Case #%d: %d\n",tt,res-1);
    }
    return 0;
}
