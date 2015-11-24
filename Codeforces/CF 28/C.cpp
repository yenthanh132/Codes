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

const int maxn=56;

int n,m,a[maxn],b[maxn],N;
double val,res,dp[maxn][maxn][2],tohop[maxn][maxn];

double mpow(double v0, int n){
    if(n==0) return 1;
    double t=mpow(v0,n/2);
    t=t*t;
    if(n&1) return t*v0; else return t;
}

int main(){
    reset(tohop,0);
    tohop[0][0]=1;
    FOR(i,1,50){
        tohop[i][0]=1;
        FOR(j,1,i-1) tohop[i][j]=tohop[i-1][j-1]+tohop[i-1][j];
        tohop[i][i]=1;
    }
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d",&a[i]);
    val=1;
    FOR(i,1,n) val/=m;
    res=0;
    FOR(len,1,n){
        reset(dp,0);
        dp[0][0][0]=1;
        FOR(i,1,m) FOR(j,0,n){
            dp[i][j][0]=dp[i-1][j][0]; dp[i][j][1]=dp[i-1][j][1];
            FOR(k,1,j){
                if((k-1)/a[i]+1>len) break;
                else if((k-1)/a[i]+1==len) dp[i][j][1]+=(dp[i-1][j-k][0] + dp[i-1][j-k][1])*tohop[n-j+k][k];
                else{
                    dp[i][j][0]+=dp[i-1][j-k][0]*tohop[n-j+k][k];
                    dp[i][j][1]+=dp[i-1][j-k][1]*tohop[n-j+k][k];
                }
            }
        }
        //cout<<len<<' '<<dp[m][n][1]<<endl;
        res+=len*dp[m][n][1]*val;
    }
    printf("%0.20lf\n",res);
    return 0;
}
    
