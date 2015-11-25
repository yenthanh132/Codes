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

const int maxn=20;

int a[maxn][maxn],dp[1<<maxn],n;
ll dem[1<<maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n;
    REP(i,n) REP(j,n) cin>>a[i][j];
    dp[0]=0; dem[0]=1;
    int c;
    FOR(i,1,(1<<n)-1){
        c=0; REP(j,n) if((i>>j)&1) c++;
        dp[i]=-1;
        REP(j,n) if((i>>j)&1)
            if(dp[i]<dp[i-(1<<j)]+a[c-1][j]){
                dp[i]=dp[i-(1<<j)]+a[c-1][j];
                dem[i]=dem[i-(1<<j)];
            }else if(dp[i]==dp[i-(1<<j)]+a[c-1][j]) 
                dem[i]+=dem[i-(1<<j)];
    }
    cout<<dp[(1<<n)-1]<<' '<<dem[(1<<n)-1];
    //getch();
    return 0;
}
