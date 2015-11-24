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

const int maxn=307;

int n,m,k;
ll a[maxn][maxn];
ll dp[maxn][maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    int u,v,c;
    FOR(i,1,n) FOR(j,1,n) a[i][j]=oo;
    FOR(i,1,m){
        scanf("%d%d%d",&u,&v,&c);
        a[u][v]=min(a[u][v],c*1ll);
    }
    FOR(j,1,n)
        FOR(i,2,j) a[i][j]=min(a[i][j],a[i-1][j]);
    FOR(i,0,n) FOR(v,0,n) dp[i][v]=oo;
    dp[0][0]=0;
    FOR(i,1,n) FOR(v,0,i){
        dp[i][v]=dp[i-1][v];
        FOR(t,1,v) if(dp[i-t][v-t]!=oo) dp[i][v]=min(dp[i][v],dp[i-t][v-t]+a[i-t+1][i]);
    }
    if(dp[n][k]==oo) dp[n][k]=-1;
    cout<<dp[n][k]<<endl;
    //getch();
    return 0;
}
    
