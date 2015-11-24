#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

int n,a[maxn];
ll f[maxn][maxn];

ll cal(int l, int r){
    if(l>=r) return 1;
    if(f[l][r]!=-1) return f[l][r];
    ll dp[maxn];
    dp[l-1]=1;
    for(int i=l; i<=r; ++i){
        dp[i]=dp[i-1];
        if(a[i]>0){
            for(int j=i-1; j>=l; --j) if(a[j]+a[i]==0)
                dp[i] = (dp[i] + cal(j+1,i-1)*dp[j-1])%oo;
        }
    }
    f[l][r]=dp[r];
    return dp[r];
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    reset(f,-1);
    cout<<cal(1,n)<<endl;

}

