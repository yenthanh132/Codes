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
typedef pair<int, pii> iii;
const int maxn=10007;

iii operator+(iii a, iii b){
    return iii(a.fi+b.fi,pii(a.se.fi+b.se.fi,a.se.se+b.se.se));
}

iii dp[maxn];

int main(){
    int n;
    cin>>n;
    dp[1]=iii(2,pii(1,1));
    FOR(i,2,n){
        dp[i]=iii(i+1,pii(1,1));
        for(int j=2; j*j<=i; j++) if(i%j==0) dp[i]=min(dp[i],iii(j+i/j,pii(j,1)));
        for(int j=1; j*2<=i; j++) dp[i]=min(dp[i],dp[j]+dp[i-j]);
    }
    
    cout<<dp[n].fi<<' '<<dp[n].se.fi<<' '<<dp[n].se.se<<endl;
    return 0;
}
                
        
