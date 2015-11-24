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

char a[maxn][maxn];
int m,n,dp[maxn][maxn];

void go(int x0, int y0){
    reset(dp,0);
    dp[x0][y0]=(a[x0][y0]=='.');
    FOR(i,1,m) FOR(j,1,n)
        if((i!=x0 || j!=y0) && a[i][j]=='.')
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%oo;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
    ll v11,v12,v21,v22;
    go(1,2);
    v11=dp[m-1][n];
    v12=dp[m][n-1];
    go(2,1);
    v21=dp[m-1][n];
    v22=dp[m][n-1];
    cout<<(((v11*v22-v12*v21)%oo)+oo)%oo<<endl;
    return 0;
}

