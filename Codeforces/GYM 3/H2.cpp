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

int dp[maxn][maxn][maxn];
int n,m;

int f(int n, int x, int y){
    if(n<=m) return n;
    if(dp[n][x][y]!=-1) return dp[n][x][y];
    int &res=dp[n][x][y];
    if(x+y==n) return (res=f(x,0,0));
    int left=n-x-y;

    res=0;    
    if(left<=m) res=n-y+(y-f(y,0,0));
    FOR(i,1,min(left-1,m)){
        int ans=oo;
        FOR(j,1,min(left-i,m))
            ans=min(ans,f(n,x+i,y+j));
        res=max(res,ans);
    }
    return res;
}

#include <conio.h>
int main(){
    reset(dp,-1);
    cin>>n>>m;
    cout<<f(n,0,0);
    //getch();
    return 0;   
}
