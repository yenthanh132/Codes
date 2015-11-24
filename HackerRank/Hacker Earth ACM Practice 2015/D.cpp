#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll dp[111][1111],val[1111];
int n,m;
int a[111111];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i){
        int c;
        scanf("%d",&c);
        for(int j=0; j<=m; ++j) dp[i][j]=dp[i-1][j],val[j]=0;
        for(int j=1; j<=c; ++j){
            scanf("%d",&a[j]);
            ll sum=0;
            for(int k=1; k<=min(m,j); ++k){
                sum+=a[j-k+1];
                val[k]=max(val[k],sum);
            }
        }
        for(int j=1; j<=m; ++j) for(int k=1; k<=j; ++k) dp[i][j]=max(dp[i][j],dp[i-1][j-k]+val[k]);
    }
    ll res=0;
    for(int j=1; j<=m; ++j) res=max(res,dp[n][j]);
    cout<<res<<endl;
}

