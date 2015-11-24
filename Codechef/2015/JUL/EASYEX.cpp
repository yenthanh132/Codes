#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int DMOD = 2003;

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t = mypow(base, n/2);
    t = t*t % DMOD;
    if(n&1) return t*base %DMOD;
    return t;
}

ll dp[11111][11111], gt[DMOD+7], invGt[DMOD+7];
int N, K, L, F;

ll frac(int n){
    if(n>=DMOD) return 0;
    return gt[n];
}

ll invFrac(int n){
    if(n>=DMOD) return 0;
    return invGt[n];
}

ll combination(ll n, ll k){
    return frac(n)*invFrac(k)%DMOD * invFrac(n-k)%DMOD;
}

int main(){
    freopen("input.txt","r",stdin);
    gt[0]=1; invGt[0]=1;
    for(int i=1; i<DMOD; ++i) gt[i] = gt[i-1]*i%DMOD, invGt[i]=mypow(gt[i],oo-2);
    int T;
    cin>>T;
    while(T--){
        cin>>N>>K>>L>>F;
        ll den = mypow(K,N);
        dp[0][0]=1;
        for(int i=0; i<L; ++i)
            for(int v=i; v<=N; ++v) if(dp[i][v]>0)
                for(int v2=1; v+v2<=N; ++v2)
                    dp[i+1][v+v2] = (dp[i+1][v+v2] + dp[i][v]*v2*combination(v+v2,v2) )%DMOD;

        ll num=dp[L][N];
        ll res = num*mypow(den,DMOD-2)%DMOD;

        cout<<num<<endl;
    }
}

