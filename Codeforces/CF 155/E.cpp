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

const int maxn=407;

int dp[maxn][maxn],n,v,m,a[maxn];
vector<pii> list[maxn];
pii trace[maxn][maxn];
vector<int> ans[maxn];

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf("%d%d",&n,&v);
    FOR(i,1,n) scanf("%d",&a[i]);
    
    int l,r,f;
    scanf("%d",&m);
    FOR(i,1,m){
        scanf("%d%d%d",&l,&r,&f);
        FOR(j,l,r) list[j].pb(pii(f,i));
    }
    FOR(i,1,n) sort(list[i].begin(),list[i].end());
    
    FOR(i,1,n) FOR(j,0,400) dp[i][j]=-oo;
    dp[1][a[1]-v]=0;
    trace[1][a[1]-v]=pii(0,0);
    int s=0;
    REP(j,sz(list[1])){
        s+=list[1][j].fi;
        if(a[1]-v-s>=0){
            dp[1][a[1]-v-s]=j+1; 
            trace[1][a[1]-v-s]=pii(j+1,0);
        }else break;
    }
    
    FOR(i,2,n)
        FOR(x,0,400)
            if(dp[i-1][x]!=-oo){
                if(x>=v){
                    if(dp[i][a[i]]<dp[i-1][x]){;
                        dp[i][a[i]]=dp[i-1][x];
                        trace[i][a[i]]=pii(0,x);
                    }
                }else{
                    if(dp[i][a[i]+x-v]<dp[i-1][x]){
                        dp[i][a[i]+x-v]=dp[i-1][x];
                        trace[i][a[i]+x-v]=pii(0,x);
                    }
                }
                s=0;
                REP(j,sz(list[i])){
                    s+=list[i][j].fi;
                    if(a[i]+x-v-s>=0){
                        if(x>=v+s){
                            if(dp[i][a[i]]<dp[i-1][x]+j+1){
                                dp[i][a[i]]=dp[i-1][x]+j+1;
                                trace[i][a[i]]=pii(j+1,x);
                            }
                        }else{
                            if(dp[i][a[i]+x-v-s]<dp[i-1][x]+j+1){
                                dp[i][a[i]+x-v-s]=dp[i-1][x]+j+1;
                                trace[i][a[i]+x-v-s]=pii(j+1,x);
                            }
                        }
                    }else break;
                }
            }
              
    int res=-oo,u;
    FOR(x,0,400) if(res<dp[n][x]){
        res=dp[n][x];
        u=x;
    }
    
    FORD(i,n,1){
        REP(j,trace[i][u].fi) ans[i].pb(list[i][j].se);
        u=trace[i][u].se;
    }
    
    
    printf("%d\n",res);
    FOR(i,1,n){
        printf("%d",sz(ans[i]));
        REP(j,sz(ans[i])) printf(" %d",ans[i][j]);
        puts("");
    }
    return 0;
}
         
