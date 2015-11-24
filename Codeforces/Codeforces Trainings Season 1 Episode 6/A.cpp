#include <conio.h>
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

const int maxn=3007;

int dp[maxn],a[7],dp2[maxn];

int main(){
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);   
    REP(tt,T){
        FOR(i,1,6) scanf("%d",&a[i]);
        FOR(i,1,2100) dp[i]=oo;
        dp[0]=0;
        FOR(i,1,6) FOR(v,a[i],2100) if(dp[v]>dp[v-a[i]]+1) dp[v]=dp[v-a[i]]+1;
        FOR(v,1,100){
            dp2[v]=dp[v];
            FOR(v2,1,2000) dp2[v]=min(dp2[v],dp[v+v2]+dp[v2]);
        }
        int maxv=0,sum=0;
        FOR(v,1,100){
            maxv=max(maxv,dp2[v]);
            sum+=dp2[v];
        }
        printf("%0.2lf %d\n",sum/100.0,maxv);        
    }
    //getch();
    return 0;
}
