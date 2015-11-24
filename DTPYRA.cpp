#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef unsigned long long ll;

ll cal(ll n){
    return n*(n+1)*(2*n+1)/6;
}

bool solve(ll a, ll b, ll c, ll &x){
    ll delta = b*b-4*a*c;
    if(delta<0) return 0;
    ll rdelta = ll(sqrt(delta));
    while(rdelta*rdelta<delta) ++rdelta;
    if(rdelta*rdelta!=delta) return 0;

    x = -b + rdelta;
    if(x&1) return 0;
    x/=2*a;
    return 1;
}

void solve(ll N){
    N*=6;
    for(ll len=1; len*(len+1)*(2*len+1)<=N; ++len){
        if(N%len==0){
            ll n=len;
            ll x;
            if(solve(6,(n+1)*6,(n+1)*(2*n+1) - N/len,x)) if(x>=0){
                ll y=x+len;
                printf("YES\n");
                printf("%lld %lld\n",y,x);
                return;
            }
        }
    }
    puts("NO");

}


int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n,T;
    cin>>T;
    while(T--){
        cin>>n;
        solve(n);
    }
}

