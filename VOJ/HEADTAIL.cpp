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

const int maxs=1007;
const int maxn=57;

int dp[maxs][maxn*2],n,s;

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&s);
    dp[1][0]=1; dp[1][1]=1;
    FOR(i,2,s){
        dp[i][0]=dp[i][1]=dp[i-1][0];
        FOR(j,1,2*n-1) dp[i][j&1]+=dp[i-1][j]; 
        FOR(j,2,2*n) dp[i][j]=dp[i-1][j-1];
    }
    ll res=0;
    FOR(i,2,s) res+=dp[i][n*2];
    cout<<2<<endl;
    cout<<1<<' '<<res<<endl;
    res=4;
    REP(i,n-1) res=res*4+4;
    cout<<2<<' '<<res<<".00"<<endl;
    getch();
    return 0;
}
    
