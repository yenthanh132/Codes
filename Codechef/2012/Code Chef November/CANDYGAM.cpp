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
typedef pair<ll, ll> pll;
int test,m,n,a[52][52];
ll dp[52][52][52][52][2],srow[52][52],scol[52][52], totalsum,res;


ll getrow(int x, int y1, int y2){
    return srow[x][y2]-srow[x][y1-1];
}

ll getcol(int y, int x1, int x2){
    return scol[x2][y]-scol[x1-1][y];
}

//#include <conio.h>
int main(){
//    freopen("test.txt","r",stdin);
    scanf("%d",&test);
    REP(index,test){
        scanf("%d%d",&m,&n);
        FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]);
        totalsum=0;
        FOR(i,1,m) FOR(j,1,n){
            srow[i][j]=srow[i][j-1]+a[i][j];
            scol[i][j]=scol[i-1][j]+a[i][j];
            totalsum+=a[i][j];
        }
        int x2,y2;
        pll t[4]; 
        ll minv;
        FOR(h,1,m) FOR(w,1,n)
            FOR(x1,1,m-h+1) FOR(y1,1,n-w+1){
                x2=x1+h-1; y2=y1+w-1;
                t[0]=pll(getrow(x1,y1,y2),dp[x1+1][y1][x2][y2][0]);
                t[1]=pll(getrow(x2,y1,y2),dp[x1][y1][x2-1][y2][0]);
                t[2]=pll(getcol(y1,x1,x2),dp[x1][y1+1][x2][y2][0]);
                t[3]=pll(getcol(y2,x1,x2),dp[x1][y1][x2][y2-1][0]);
                
                dp[x1][y1][x2][y2][0]=dp[x1][y1][x2][y2][1]=0;
                
                dp[x1][y1][x2][y2][0]=max(dp[x1][y1][x2][y2][0],dp[x1+1][y1][x2][y2][1] + t[0].fi);
                dp[x1][y1][x2][y2][0]=max(dp[x1][y1][x2][y2][0],dp[x1][y1][x2-1][y2][1] + t[1].fi);
                dp[x1][y1][x2][y2][0]=max(dp[x1][y1][x2][y2][0],dp[x1][y1+1][x2][y2][1] + t[2].fi);
                dp[x1][y1][x2][y2][0]=max(dp[x1][y1][x2][y2][0],dp[x1][y1][x2][y2-1][1] + t[3].fi);
                
                minv=t[0].fi;
                dp[x1][y1][x2][y2][1]=t[0].se;
                FOR(i,1,3) if(minv>t[i].fi){
                    dp[x1][y1][x2][y2][1]=t[i].se;
                    minv=t[i].fi;
                }
            }
        if(dp[1][1][m][n][1]*2>totalsum) res=dp[1][1][m][n][1]; 
        else if(dp[1][1][m][n][1]*2==totalsum) res=totalsum;
        else res=totalsum-dp[1][1][m][n][1];
        printf("%lld\n",res);
    }
//    getch();
    return 0;
}
