#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxv=10000000;

int f[maxv+1];
ll dp[maxv+1];

ll mypow(ll base, int n){
    if(n==1) return base;
    ll t=mypow(base,n/2);
    t=t*t;
    if(n&1) return t*base;
    return t;
}

ll get(int n){
    if(dp[n]!=-1) return dp[n];
    ll &res = dp[n];
    res=1;
    while(n>1){
        ll x=f[n],c=0;
        while(n%x==0){
            n/=x;
            ++c;
        }
        if(c>1) res *= (mypow(x,2*c+1)+1)/(x+1);
        else res *= x*(x-1) + 1;
    }
    return res;
}

// f(p1^e1 * p2^e2 * ...) = p1^(e1*2+1)/(p1+1) * p2^(e2*2+1)/(p2+1) * ...

int main(){
//    freopen("input.txt","r",stdin);

    for(int i=2; i<=maxv; ++i) f[i]=1;
    for(int i=2; i*i<=maxv; ++i) if(f[i]==1){
        for(int j=i*i; j<=maxv; j+=i) if(f[j]==1) f[j]=i;
    }
    for(int i=2; i<=maxv; ++i) if(f[i]==1) f[i]=i;

    reset(dp,-1);
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%lld\n",get(n));
    }
}
