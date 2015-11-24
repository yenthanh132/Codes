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

int a,b,k;
ll dp[30][2][2];

ll f(int i, bool small1, bool small2){
    if(i<0) return 0;
    if(dp[i][small1][small2]!=-1) return dp[i][small1][small2];
    ll &res=dp[i][small1][small2];
    if((k>>i)&1){
        if(((a>>i)&1)==0 && !small1) return 0;
        if(((b>>i)&1)==0 && !small2) return 0;
        res=f(i-1,small1,small2);
        return res;
    }else{
        res=0;
        //1 - 1
        if((small1 || ((a>>i)&1)) && (small2 || ((b>>i)&1))){
            ll v=1;
            if(small1) v*=(1<<i);
            else{
                ll t=0;
                REPD(j,i) if((a>>j)&1) t|=1<<j;
                v*=(t+1);
            }
            if(small2) v*=(1<<i);
            else{
                ll t=0;
                REPD(j,i) if((b>>j)&1) t|=1<<j;
                v*=(t+1);   
            }
            res+=v;
        }
        if(small2 || ((b>>i)&1)) res+=f(i-1,small1 | ((a>>i)&1),small2);
        if(small1 || ((a>>i)&1)) res+=f(i-1,small1,small2 | ((b>>i)&1));
        res+=f(i-1,small1 | ((a>>i)&1), small2 | ((b>>i)&1));
        
        return res;
    }
}

int main(){
    freopen("B-large-practice.in","r",stdin);
    freopen("B-large-practice.out","w",stdout);
    
    int test;
    scanf("%d",&test);
    FOR(tt,1,test){
        printf("Case #%d: ",tt);
        int res=0;
        scanf("%d%d%d",&a,&b,&k);
        a--; b--; k--;
        reset(dp,-1);
        printf("%lld\n",1ll*(a+1)*(b+1)-f(29,0,0));
    }
    
    return 0;
}
