#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000009

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll frac[222222];

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

int main(){
//    freopen("input.txt","r",stdin);
    frac[0]=1;
    for(int i=1; i<=200000; ++i) frac[i]=frac[i-1]*i%oo;
    int n;
    cin >> n;
    cout << frac[n*2] * mypow(frac[n],oo-2) %oo * mypow(frac[n+1],oo-2)%oo;

}

