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

int p[maxn],c[maxn],t[maxn],w,n,T,dp[maxn][maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&w);
        FOR(i,1,n) scanf("%d%d%d",&c[i],&p[i],&t[i]), p[i]*=c[i];
        FOR(j,0,w) dp[0][j]=0;
        FOR(i,1,n) FOR(j,0,w){
            dp[i][j]=dp[i-1][j];
            if(j>=t[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-t[i]]+p[i]);   
        }
        cout<<dp[n][w]<<endl;
    }
    //getch();
    return 0;
}
