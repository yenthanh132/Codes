#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll n,s,f[22];
ll inv[22];

ll C(ll n, ll k){
    if(n<k) return 0;
    ll a=1;
    for(ll i=n-k+1; i<=n; ++i) a=a*(i%oo)%oo;
    return a*inv[k]%oo;
}

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

ll res;

void go(int i, int sign, ll sum){
    if(sum<0) return;
    if(i>n){
        res = (res + sign*C(sum+n-1,n-1) + oo) %oo;
        return;
    }
    go(i+1,sign,sum);
    go(i+1,sign*-1,sum-f[i]-1);
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n>>s;
    for(int i=1; i<=n; ++i) cin>>f[i];

    ll x=1;
    inv[0]=mypow(1,oo-2);
    for(int i=1; i<=n; ++i){
        x=x*i%oo;
        inv[i]=mypow(x,oo-2);
    }
    res=0;
    go(1,1,s);
    cout<<res<<endl;

    return 0;
}
