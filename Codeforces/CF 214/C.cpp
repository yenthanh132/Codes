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

int n,k,a[107],b[107];
int dp[107][2*107*107];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    scanf("%d%d",&n,&k);   
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
    FOR(i,0,20000) dp[0][i]=-oo;
    dp[0][10000]=0;
    FOR(i,1,n) FORD(v,20000,0){
        dp[i][v]=dp[i-1][v];
        if( 0<=v-(a[i]-k*b[i]) && v-(a[i]-k*b[i])<=20000 ) 
            dp[i][v]=max(dp[i][v],dp[i-1][v-(a[i]-k*b[i])] + a[i]);
    }
    if(dp[n][10000]<=0) dp[n][10000]=-1;
    printf("%d\n",dp[n][10000]);
}
