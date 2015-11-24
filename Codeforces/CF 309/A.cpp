#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll frac[2222];

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

ll C(ll n, ll k){
    return frac[n]*mypow(frac[k],oo-2)%oo*mypow(frac[n-k],oo-2)%oo;
}

int main(){
//    freopen("input.txt","r",stdin);
    frac[0]=1;
    for(int i=1; i<=2000; ++i) frac[i]=frac[i-1]*i%oo;
    ll res=1;
    ll sum=0;
    ll n,v;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>v;
        if(v>1)res=res*C(sum+v-1,v-1)%oo;
        sum+=v;
    }
    cout<<res<<endl;
}
