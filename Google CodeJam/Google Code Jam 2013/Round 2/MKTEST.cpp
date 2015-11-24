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

int main(){
    freopen("test2.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int dp[25];
    int n,a[25];
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    dp[1]=1;
    FOR(i,2,n){
        dp[i]=1;
         FORD(j,i-1,1) if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
        }
    cout<<n<<endl;
    FOR(i,1,n) cout<<dp[i]<<' '; cout<<endl;
    dp[n]=1;
    FORD(i,n-1,1){
        dp[i]=1;
        FOR(j,i+1,n) if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
    }
    FOR(i,1,n) cout<<dp[i]<<' '; cout<<endl;
    return 0;
}
