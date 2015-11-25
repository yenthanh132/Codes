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
#define oo 100000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=507;

int a[maxn][maxn],n,k;
ll s[maxn][maxn],dp[maxn][maxn],sum;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    sum=0;
    FOR(i,1,n) FOR(j,1,n) scanf("%d",&a[i][j]), sum+=a[i][j];
    FOR(i,1,n){
        s[i][i]=a[i][i];
        FOR(j,i+1,n) s[i][j]=s[i][j-1]+a[i][j]+a[j][i];
    }
    FOR(i,0,n) FOR(j,0,k) dp[i][j]=oo;
    dp[0][0]=0;
    FOR(i,1,n){
        dp[i][0]=dp[i-1][0];
        FOR(j,1,i-1) dp[i][0]+=a[j][i]+a[i][j];
    }
    ll t;
    FOR(i,1,n) FOR(j,1,k){
        dp[i][j]=dp[i-1][j-1];
        t=0;
        FORD(z,i-1,j){
            t+=s[z][i];
            dp[i][j]=min(dp[i][j],dp[z-1][j-1]+t);
        }
    }
    printf("%lld\n",sum-dp[n][k]);
    
    //getch();
    return 0;
}
