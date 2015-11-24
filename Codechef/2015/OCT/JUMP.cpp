#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=300007;

int p[maxn],a[maxn],h[maxn],n;
ll dp[maxn];

dp[i] = dp[j] + h[i]^2 -2*h[i]*h[j] + h[j]^2

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",p+i);
    for(int i=1; i<=n; ++i) scanf("%d",a+i);
    for(int i=1; i<=n; ++i) scanf("%d",h+i);

    dp[1]=a[1];
    for(int i=2; i<=n; ++i){
        dp[i]=dp[1]+sqr(h[i]-h[1]);
        for(int j=2; j<i; ++j) if(p[j]<p[i] && dp[i]>dp[j]+sqr(h[i]-h[j]))
            dp[i] = dp[j] + sqr(h[i]-h[j]);
        dp[i]+=a[i];
    }

    printf("%lld\n",dp[n]);
}

