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

const int maxn=1000007;

int dp[maxn];

ll getvalue(ll v);
ll cal(ll v);

#include <conio.h>

int main(){
    dp[0]=0;
    FOR(i,1,1000000){
        dp[i]=oo;
        stringstream ss;
        int v=i;
        while(v){
            dp[i]=min(dp[i],dp[i-v%10]+1);
            v/=10;
        }
    }
    ll n;
    cout<<dp[1000]<<' '<<dp[660]<<endl;
    cout<<dp[700]<<' '<<dp[100]<<' '<<dp[600]<<endl;
    cin>>n;
    cout<<getvalue(n)<<' '<<dp[n]<<endl;
    getch();
    return 0;
}

ll getvalue(ll v){
    if(v<=100) return dp[v];
    ll mul=1;
    ll res=0;
    while(v){
        res+=getvalue((v%10)*mul - (v%10)) + ((v%10)!=0);
        mul*=10;
        v/=10;
    }
    return res;
}
