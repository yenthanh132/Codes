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

pii a[maxn];
int n;
ll dp[maxn];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
    sort(a+1,a+n+1);
    dp[n+1]=0;
    FORD(i,n,1){
        dp[i]=dp[i+1];
        ll sum=0;
        FOR(j,i+1,n){
            sum+=a[j].fi-a[i].fi;
            dp[i]=min(dp[i],sum+dp[j+1]);
        }
        dp[i]+=a[i].se;
    }
    cout<<dp[1]<<endl;
    //getch();
    return 0;
}
