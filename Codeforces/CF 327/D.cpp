#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=155;

int dp[2][maxn][maxn*maxn],n,k,s,a[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&k,&s);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    if(n*(n-1)/2 <= s){
        int res=0;
        sort(a+1,a+n+1);
        for(int i=1; i<=k; ++i) res+=a[i];
        printf("%d\n",res);
    }else{
        reset(dp,63);
        dp[0][0][0]=0;
        int flag=0;
        for(int i=1; i<=n; ++i){
            flag^=1;
            reset(dp[flag],63);
            for(int j=0; j<=k; ++j) for(int v=0; v<=s; ++v) if(dp[flag^1][j][v]<oo){
                dp[flag][j][v] = min(dp[flag][j][v], dp[flag^1][j][v]);
                if(j<k){
                    int v2=v+i-j-1;
                    if(v2<=s) dp[flag][j+1][v2] = min(dp[flag][j+1][v2], dp[flag^1][j][v] + a[i]);
                }
            }
        }
        int res=oo;
        for(int v=0; v<=s; ++v) res=min(res,dp[flag][k][v]);
        printf("%d\n",res);
    }
}

