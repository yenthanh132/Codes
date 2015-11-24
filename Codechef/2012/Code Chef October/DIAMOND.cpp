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

int test,n,a[maxn];
double dp[maxn][maxn],s[maxn];;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&test);
    REP(i_,test){
        scanf("%d",&n);
        s[0]=0;
        FOR(i,1,n) scanf("%d",a+i), s[i]=s[i-1]+a[i];
        int j;
        FOR(i,1,n) dp[i][i]=a[i];
        FOR(len,2,n)
            FOR(i,1,n-len+1){
                j=i+len-1; 
                dp[i][j]=(s[j]-s[i] - dp[i+1][j] + a[i] + s[j-1]-s[i-1] - dp[i][j-1] + a[j])/2;
            }
        printf("%0.3lf\n",dp[1][n]);
    }
    //getch();
    return 0;
}
                 
