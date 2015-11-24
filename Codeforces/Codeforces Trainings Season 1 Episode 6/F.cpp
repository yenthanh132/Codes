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

const int maxn=107;

int n,a[maxn],p[maxn],dp[maxn];

int main(){
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d%d",&a[i],&p[i]);
        dp[0]=0;
        FOR(i,1,n){
            dp[i]=dp[i-1]+(a[i]+10)*p[i];
            int sum=a[i]+10;
            FORD(j,i-1,1){
                sum+=a[j];
                dp[i]=min(dp[i],dp[j-1]+sum*p[i]);   
            }   
        }   
        printf("%d\n",dp[n]);
    }
    //getch();
    return 0;
}
