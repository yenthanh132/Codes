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
#define oo 1e20;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const double pi = 3.141592654;
const int maxn=10007;
const int maxm=21;

int n,m,s[maxn],l[maxn];
double dp[maxn][maxm];

double sqr(double v){return v*v;}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",l+i);
    FOR(i,1,n) scanf("%d",s+i);
    
    FOR(j,1,m) dp[0][j]=0;
    double r;
    FOR(i,1,n) 
        if(l[i]){
            FOR(j,1,m){
                if(l[i]==1) r=s[i]+5+(j-1)*10; else r=s[i]+5+(m-j)*10;
                dp[i][j]=dp[i-1][j]+r*pi/2;
            }
        }else{
            FOR(j,1,m){
                dp[i][j]=oo;
                FOR(k,max(1,j-(s[i]/100)),min(m,j+(s[i]/100))) 
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+sqrt(sqr(abs(k-j)*10) + sqr(s[i])));
            }
        }
    double res=dp[n][1];
    FOR(i,2,m) res=min(res,dp[n][i]);
    printf("%0.2lf\n",res);
    
    //getch();
    return 0;
}
                    
                
