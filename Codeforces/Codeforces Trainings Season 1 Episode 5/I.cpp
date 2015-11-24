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

const double eps=1e-9;

double dp[207][207],err[207][207];
double x[207];
int n,k;


#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&k);
        FOR(i,1,n) scanf("%lf",&x[i]);
        FOR(i,0,n) FOR(j,0,k) dp[i][j]=oo;
        dp[1][1]=0;
        FOR(i,1,n) FOR(j,i,n){
            err[i][j]=0;
            FOR(k,i+1,j-1) err[i][j]+=fabs(x[i]+(x[j]-x[i]) * 1.0 * (k-i)/(j-i) - x[k]);
        }
        FOR(j,2,k) FOR(i,2,n){
            dp[i][j]=oo;
            FOR(z,1,i-1) dp[i][j]=min(dp[i][j],dp[z][j-1]+err[z][i]);
        }
        printf("%0.4lf\n",dp[n][k]/n);
    }
    //getch();
    return 0;
}
