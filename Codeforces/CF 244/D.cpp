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

const int maxn=5007;
char a[maxn],b[maxn];
int dp[maxn][maxn],g[2][maxn],m,n;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%s",a+1); m=strlen(a+1);
    scanf("%s",b+1); n=strlen(b+1);
    
    reset(dp,0);
    FORD(i,m,1) FORD(j,m,1) 
        if(a[i]!=a[j]) dp[i][j]=0;
        else dp[i][j]=1+dp[i+1][j+1];
    FOR(i,1,m){
        g[0][i]=0;
        FOR(j,1,m) if(j!=i) g[0][i]=max(g[0][i],dp[i][j]);
    }
    
    reset(dp,0);
    FORD(i,n,1) FORD(j,n,1)
        if(b[i]!=b[j]) dp[i][j]=0;
        else dp[i][j]=1+dp[i+1][j+1];
    FOR(i,1,n){
        g[1][i]=0;
        FOR(j,1,n) if(j!=i) g[1][i]=max(g[1][i],dp[i][j]);   
    }
    
    reset(dp,0);
    FORD(i,m,1) FORD(j,n,1)
        if(a[i]!=b[j]) dp[i][j]=0;
        else dp[i][j]=1+dp[i+1][j+1];
    
    int res=oo;
    FOR(i,1,m) FOR(j,1,n)
        if(max(g[0][i],g[1][j])<dp[i][j]) res=min(res,max(g[0][i],g[1][j])+1);   
        
    if(res==oo) res=-1;
    printf("%d\n",res);
    return 0;
}
