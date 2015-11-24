#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll dp[333][111][111];
ll gt[333],invGt[333];
int x,y,z,n;

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

ll cc(int x, int y, int z){
    return gt[x+y+z]*invGt[x]%oo *invGt[y]%oo *invGt[z]%oo;
}

int main(){
//    freopen("input.txt","r",stdin);

    cin>>x>>y>>z;
    n = x+y+z;
    gt[0]=1; invGt[0]=1;
    for(int i=1; i<=n; ++i) gt[i]=gt[i-1]*i%oo, invGt[i]=mypow(gt[i], oo-2);

    dp[0][0][0] = 0;
    ll p10=1;
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=x && j<=i; ++j) for(int k=0; k<=y && k+j<=i; ++k){
            int l=i-j-k;
            if(l>z) continue;
            dp[i][j][k]=0;
            if(j>0) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-1][k] + p10*4*cc(j-1,k,l))%oo;
            if(k>0) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1] + p10*5*cc(j,k-1,l))%oo;
            if(l>0) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]   + p10*6*cc(j,k,l-1))%oo;
        }
        p10=p10*10%oo;
    }
    ll res = 0;
    for(int i=0; i<=x; ++i) for(int j=0; j<=y; ++j) for(int k=0; k<=z; ++k) res = (res + dp[i+j+k][i][j])%oo;
    cout<<res<<endl;
}

