#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll mypow(ll base, int n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

int main(){
    //freopen("input.txt","r",stdin);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==0) cout<<4<<endl;
        else{
            ll x = 2ll * (mypow(2,n) - 1 + oo)%oo;
            cout<<(4 + x)%oo<<endl;
        }
    }
}

