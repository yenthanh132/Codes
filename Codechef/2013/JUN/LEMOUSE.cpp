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
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int m,n,t,dp[maxn][maxn][2],val[maxn][maxn];
char a[maxn][maxn];

//#include <conio.h>
int main(){
    int it,jt;
    
    //freopen("test.txt","r",stdin);
    scanf("%d",&t);
    
    REP(tt,t){
        scanf("%d%d",&m,&n);
        FOR(i,1,m) scanf("%s",a[i]+1);
        
        reset(val,0);
        reset(dp,0);
        FOR(i,2,100) REP(k,2) dp[0][i][k]=dp[i][0][k]=oo;
        if(a[1][1]=='1') dp[0][1][0]=dp[1][0][0]=dp[0][1][1]=dp[1][0][1]=1;
        FOR(i,1,m) FOR(j,1,n) if(a[i][j]=='1')
            REP(k,4){
                it=i+dx[k]; jt=j+dy[k];
                if(it<1 || it>m || jt<1 || jt>n) continue;
                val[it][jt]++;
            }
      
        FOR(i,1,m) FOR(j,1,n){
            dp[i][j][0]=min(dp[i-1][j][0]-(a[i-1][j]=='1'),dp[i-1][j][1]-(a[i][j-1]=='1')-(a[i-1][j]=='1'))+val[i][j];
            dp[i][j][1]=min(dp[i][j-1][1]-(a[i][j-1]=='1'),dp[i][j-1][0]-(a[i-1][j]=='1')-(a[i][j-1]=='1'))+val[i][j];
        }
        printf("%d\n",min(dp[m][n][0], dp[m][n][1]));
    }
    
    //getch();
    return 0;
}
