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

int n,x[maxn],y[maxn];
ll C[1007][maxn],dp[maxn][1007];
bool val[maxn][1007];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    C[0][0]=1;
    FOR(i,1,1000){
        C[i][0]=1;
        FOR(j,1,min(i,100)) C[i][j]=(C[i-1][j-1]+C[i-1][j])%oo;
    }
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&x[i]);
    FOR(i,1,n) scanf("%d",&y[i]);
    dp[0][0]=1; val[0][0]=1;
    int xsum=0;
    FOR(i,0,n){
        xsum+=x[i];
        FOR(j,0,1000) if(val[i][j]){
            FOR(z,0,min(j,y[i])){
                ll &v=dp[i+1][x[i+1]+j-z];
                v=(v + dp[i][j]*C[j][z]%oo*C[xsum+x[i+1]][x[i+1]])%oo;
                val[i+1][x[i+1]+j-z]=1;
            }
        }
    }
    FOR(i,1,n) xsum+=x[i];
    ll res=dp[n+1][0];
    printf("%d\n",res);
    //getch();
    return 0;
}
