#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10000007;
int T,m,n,l,r;

ll dp[maxn];

ll mypow(ll base, int n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

ll calc(int m){
    if(dp[m]!=-1) return dp[m];
    ll &res = dp[m]; res = mypow(m,n);
    for(int v=2,vr, left,right,mid; v<=m; ){
        vr=v;
        left=v+1; right=m; mid;
        while(left<=right){
            mid=(left+right)/2;
            if(m/mid == m/v){
                vr = mid;
                left=mid+1;
            }else right = mid-1;
        }
        res -= calc(m/v)*(vr-v+1);
        v=vr+1;
    }

    res = (res%oo + oo)%oo;
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>T;
    while(T--){
        cin>>n>>m>>l>>r;
        dp[0]=0;
        for(int i=1; i<=m; ++i) dp[i]=-1;
        ll res = 0;
        for(int x=l; x<=r; ++x) res = (res + calc(m/x))%oo;
        cout<<res<<endl;
    }
}

