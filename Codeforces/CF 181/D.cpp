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

const int maxk=1007;
const int dmod=7340033;
ll dp[32][maxk],a[maxk];

void init(){
    dp[0][0]=1;
    FOR(i,1,29){
        dp[i][0]=1;
        reset(a,0);
        FOR(x,0,1000) FOR(y,0,1000) if(x+y<=1000) a[x+y]+=dp[i-1][x]*dp[i-1][y];
        FOR(x,0,1000) a[x]%=dmod;
        FOR(x,0,1000) FOR(y,0,1000) if(x+y+1<=1000) dp[i][x+y+1]+=a[x]*a[y];
        FOR(x,0,1000) dp[i][x]%=dmod;
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    init();
    int q,n,k;
    scanf("%d",&q);
    REP(i,q){
        scanf("%d%d",&n,&k);
        int d=0;
        while(n>=3 && n&1){
            n>>=1;
            d++;
        }
        printf("%d\n",dp[d][k]);
    }
    //getch();
    return 0;
}
