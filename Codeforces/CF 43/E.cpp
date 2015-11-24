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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=1507;

int a[maxn][maxn],s[maxn][maxn];
ll dp[maxn][maxn];
int m,n;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&m,&n);
    FOR(i,1,m) FOR(j,1,n) scanf("%d",&a[i][j]), s[i][j]=s[i][j-1]+a[i][j];
    FOR(j,1,n) dp[1][j]=s[1][j];
    FOR(i,2,m)
        if(i&1){
            ll maxv=dp[i-1][1];
            dp[i][1]=-oo;
            FOR(j,2,n){
                dp[i][j]=s[i][j]+maxv;
                maxv=max(maxv,dp[i-1][j]);
            }
        }else{
            ll maxv=dp[i-1][n];
            dp[i][n]=-oo;
            FORD(j,n-1,1){
                dp[i][j]=s[i][j]+maxv;
                maxv=max(maxv,dp[i-1][j]);
            }
        }
    ll res=-oo;
    FOR(j,1,n) res=max(res,dp[m][j]);
    cout<<res<<endl;
    //getch();
    return 0;
}
