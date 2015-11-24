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

const int maxn=107;

double dp[maxn][maxn*maxn],p[maxn];
int T,n,a[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d",&n);
        int minv=0;
        FOR(i,1,n) scanf("%d",&a[i]), minv+=a[i];
        minv=(minv+1)/2;
        FOR(i,1,n) scanf("%lf",&p[i]),p[i]/=100;
        dp[0][0]=1;
        FOR(i,1,n){
            FOR(v,0,10000) dp[i][v]=0;
            FOR(v,0,10000) if(dp[i-1][v]>0){
                dp[i][v+a[i]]+=dp[i-1][v]*p[i];
                dp[i][v]+=dp[i-1][v]*(1-p[i]);
            }
        }
        double res=0;
        FOR(v,minv,10000) res+=dp[n][v];
        printf("%0.12lf\n",res);
    }
    //getch();
    return 0;
}
        
