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

const int maxn  = 207;

int n,h[maxn],a,b,dp[maxn][2],cost[2];

int main(){
	freopen("test.txt","r",stdin);
	cin>>n>>cost[0]>>cost[1];
	FOR(i,1,n) cin>>h[i];
	int v;
	h[0]=0;
	dp[0][0]=dp[0][1]=0;
	FOR(i,1,n)
		REP(k,2){
			dp[i][k]=oo;
			v=h[i];
			FORD(j,i-1,0){
				if(v>cost[k]) break;
				dp[i][k]=min(dp[i][k],dp[j][1-k]+min(h[j],h[j+1]));
				v+=h[j];
			}
		}
	if(min(dp[n][0],dp[n][1])==oo) cout<<-1; else cout<<min(dp[n][0],dp[n][1])<<endl;
	return 0;
}
			
			
	
