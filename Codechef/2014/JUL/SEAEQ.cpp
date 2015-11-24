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

const int maxn=507;
const int maxt=100007;

int dp[maxn][maxn*(maxn-1)/2];
int sdp[maxn][maxn*(maxn-1)/2];
ll frac[maxn],C[maxn][maxn];
vector<pii> q[maxn];
int ans[maxt];

int main(){
    //freopen("input.txt","r",stdin);

    //Init====================
    dp[0][0]=1;
    FOR(i,1,500){
        int sum=0;
        FOR(j,0,i*(i-1)/2){
            sum=sum+dp[i-1][j];
            if(sum>=oo) sum-=oo;
            if(j>=i){
                sum=(sum-dp[i-1][j-i]);
                if(sum<0) sum+=oo;
            }
            dp[i][j]=sum;
            sdp[i][j]=dp[i][j];
            if(j>0) sdp[i][j]=(sdp[i][j-1]+sdp[i][j])%oo;
        }
    }

    frac[0]=1;
    FOR(i,1,500) frac[i]=frac[i-1]*i%oo;

    C[0][0]=1;
    FOR(i,1,500){
        C[i][0]=1;
        FOR(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%oo;
    }

    //========================
    int T,n,e;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&e);
        ll res=0;
        FOR(len,1,n){
            res += sdp[len][min(e,len*(len-1)/2)] * C[n][len]%oo * C[n][len]%oo * frac[n-len]%oo * frac[n-len]%oo * (n-len+1)%oo;
            res%=oo;
        }
        printf("%lld\n",res);
    }

    return 0;
}
