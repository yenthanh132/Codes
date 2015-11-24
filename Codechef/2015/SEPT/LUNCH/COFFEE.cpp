#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=5007;

int n,m,k,d,a[maxn];
ll dp[maxn][maxn],s[maxn];
int myq[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&k,&d,&m);

        for(int i=1; i<=n; ++i){
            scanf("%d",&a[i]);
            s[i]=s[i-1]+a[i];
            dp[0][i]=s[i];
        }
        for(int i=1; i<=k; ++i){
            int first=1, last=0;
            for(int p=i; p<=n; ++p){
                while(first<=last && p-myq[first]>d) ++first;
                while(first<=last && dp[i-1][myq[last]-1] - s[myq[last]]*m <= dp[i-1][p-1] - s[p]*m) --last;
                myq[++last]=p;
                dp[i][p] = (s[p] - s[myq[first]])*m + dp[i-1][myq[first]-1];
                if(p>i) dp[i][p] = max(dp[i][p], a[p] + dp[i][p-1]);
            }
        }
        printf("%lld\n",dp[k][n]);
    }
}

