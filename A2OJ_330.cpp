#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=57;
const int maxv=5007;
int s,n,v[maxn],c[maxn];
ll dp[2][maxv];

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        printf("Case %d: ",tt);
        scanf("%d%d",&s,&n);
        for(int i=1; i<=n; ++i) scanf("%d%d",&v[i],&c[i]);
        ll res=0;
        for(int cnt=1; cnt<=s; ++cnt) if(s%cnt==0){
            int s2=s/cnt;
            for(int i=0; i<=s2; ++i)
                dp[0][i]=dp[1][i]=0;
            dp[0][0]=1;
            int flag=0;
            for(int i=1; i<=n; ++i) if(c[i]>=cnt){
                flag^=1;
                for(int j=0; j<=s2; ++j){
                    dp[flag][j]=dp[flag^1][j];
                    if(j>=v[i]) dp[flag][j]+=dp[flag^1][j-v[i]];
                }
            }
            res += dp[flag][s2];
        }
        printf("%lld\n",res);
    }
}

