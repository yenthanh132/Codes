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

int a[maxn],n,sbit[maxn][32],dp[maxn][32][2];
bool ok[32];

int solve(){
    reset(dp,0); reset(sbit,0); reset(ok,0);

    dp[0][0][0]=1;
    FOR(i,1,n)
        REP(j,30){
            sbit[i][j]=sbit[i-1][j];
            if((a[i]>>j)&1) sbit[i][j]^=1;
        }

    ok[30]=1;
    REPD(j,30)
        if(ok[j+1] && sbit[n][j]==0) ok[j]=1;
        else break;

    //considering number from 1..n, bits 0..j affected, bit j-th has value x.
    // the result has bits in range 0..j-1 had value 0 and are free bits
    FOR(i,1,n) REP(j,30) REP(x,2) if(dp[i-1][j][x]){
        // if j2-th bit of a[i] is 1 then we can decrease it to 0, bit from 0..j2-1 will become free
        REP(j2,30) if((a[i]>>j2)&1){
            int freebit=min(j,j2);
            int newj=max(j,j2);
            int newx;
            if(j<j2) //if j2 is higher bit then newx will depend on j2-th bits of i-1 first numbers
                newx=sbit[i-1][j2];
            else if(j==j2)
                newx=x;
            else  //j>j2, newx will be xor with j-th bit of a[i]
                newx=x^((a[i]>>j)&1);

            //we can have any value for <freebit> bits below min(j,j2)-th bit without worry it will
            // affect the result because for each 'state' of <freebit> bits in the a[i] number, there
            // will be a set of bit values from previous i-1 numbers which makes those bits become 0 again
            dp[i][newj][newx] = (dp[i][newj][newx] + 1ll * dp[i-1][j][x] * (1<<freebit)) % oo;
        }
    }

    int res=0;
    REPD(j,30)
        if(ok[j+1]) res = (res + dp[n][j][0])%oo;
        else break;
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]), ++a[i];
    int res=solve();
    FOR(i,1,n) --a[i];
    res=(res-solve()+oo)%oo;
    cout<<res<<endl;

    return 0;
}
