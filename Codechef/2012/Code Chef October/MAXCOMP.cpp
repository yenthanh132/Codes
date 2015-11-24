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

const int maxn = 2007;

vector<pii> p[49];
int test,n,dp[49];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&test);
    int s,f,c;
    REP(i_,test){
        scanf("%d",&n);
        FOR(i,1,48) p[i].clear();
        REP(i,n){
            scanf("%d%d%d",&s,&f,&c);
            p[f].pb(pii(s,c));
        }
        dp[0]=0;
        FOR(i,1,48){
            dp[i]=dp[i-1];
            REP(j,sz(p[i])) dp[i]=max(dp[i],dp[p[i][j].fi]+p[i][j].se);
        }
        printf("%d\n",dp[48]);
    }
    //getch();
    return 0;
}
