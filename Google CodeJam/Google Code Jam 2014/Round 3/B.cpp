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

const int maxn=207;
const int maxv=2007;

int T,p,q,h[maxn],g[maxn],n;
int dp[maxn][maxv];
int cost[maxn];

int calc(int v){
    int c=0;
    while(v-q>0){
        ++c;
        v-=q;
    }
    return (v-1)/p + 1 - c;
}

void dmin(int &a, int b){
    if(a>b) a=b;
}

int solve(){
    reset(dp,0);
    int sum=0;
    FOR(i,1,n) sum+=g[i];
    FOR(i,0,n) FOR(v,0,1000) dp[i][v]=oo;
    dp[n][0]=0;
    FORD(i,n,1) FOR(v,0,1000) if(dp[i][v]!=oo){
        dmin( dp[i-1][max(0,v - ((h[i]-1)/q+1))], dp[i][v] + g[i]);
        dmin( dp[i-1][max(0,v + cost[i])], dp[i][v]);
    }

    return sum-min(dp[0][0],dp[0][1]);
}

int main(){
//    freopen("input.txt","r",stdin);
    freopen("B-large-practice.in","r",stdin);
    freopen("B-large-practice.out","w",stdout);
    cin>>T;
    FOR(tt,1,T){
        printf("Case #%d: ",tt);
        cin>>p>>q>>n;
        FOR(i,1,n) cin>>h[i]>>g[i];
        FOR(i,1,n) cost[i]=calc(h[i]);
        int res=solve();
        printf("%d\n",res);
    }
}
