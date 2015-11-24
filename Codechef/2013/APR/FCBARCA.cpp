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

const int maxn=1007;
const int maxk=17;

int dp[maxk][maxn][maxk];

int main(){
    FOR(k,1,10){
        dp[k][0][k+1]=1;
        FOR(i,1,1000)
            FOR(j,1,k+1)
                FOR(z,1,k+1) if(z!=j) dp[k][i][j]=(dp[k][i][j]+dp[k][i-1][z])%oo;
    }
    
    int test,n,k;
    scanf("%d",&test);
    REP(i,test){
        scanf("%d%d",&n,&k);
        printf("%d\n",dp[k][n][k+1]);
    }
    return 0;
}
