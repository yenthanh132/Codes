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

int num,k;
int dp[101][101][101];

#include <conio.h>
int main()
{
    //freopen("test.txt","r",stdin);
	scanf("%d %d", &num, &k);
	dp[0][0][0]=0;
	dp[1][0][0]=1;
	dp[1][1][0]=1;

	FOR(n,2,num){
		FOR(l,0,n) dp[n][l][n-l]=dp[l][0][0];
        FORD(total,n-1,0)
    		FOR(l,0,total){
				int m=total-l;
				int res=0;
				if(n-l-m<=k)
					res=n-m+(m-dp[m][0][0]);
				if(n-l-m<2)
					goto label;
				FOR(i,1,min(n-l-m-1, k)){
					int ans=oo;
					FOR(j,1,min(n-l-i-m, k)) ans=min(ans, dp[n][l+i][m+j]);
					res=max(res, ans);
				}
			label:
				dp[n][l][m]=res;	
			}
	}
	printf("%d\n", dp[num][0][0]);
	getch();
	return 0;
}
