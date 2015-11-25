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

const int maxn = 5007;
bool mark1[maxn], mark2[maxn];
int n,d,m,dp[maxn][2];

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&d),n){
        int v;
        reset(mark1,0); reset(mark2,0);
        REP(i,m){
            scanf("%d",&v);
            mark1[v]=1;
        }
        REP(i,d){
            scanf("%d",&v);
            mark2[v]=1;
        }
        
        dp[0][0]=dp[0][1]=0;
        FOR(i,1,n){
            dp[i][1]=oo;
            if(mark2[i]) dp[i][0]=oo; else dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
            if(mark1[i]){
                FORD(j,i,1) if(mark2[j]) dp[i][1]=min(dp[i][1],min(dp[j-1][0],dp[j-1][1])+(i-j+1));
            }
            if(mark2[i]){
                FORD(j,i,1) if(mark1[j]) dp[i][1]=min(dp[i][1],min(dp[j][1]+(i-j), dp[j][0]+(i-j+1)));
            }
        }
        printf("%d\n",min(dp[n][1],dp[n][0]));
    }
    getch();
    return 0;
}
