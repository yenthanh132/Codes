#include <bits/stdc++.h>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

ll sqr(ll v){
    v%=oo;
    return v*v%oo;
}

pii get(ll x, ll y, ll left, ll right){
    if(y<left || right<x) return pii(-oo,0);
    if(left<=x && y<=right)
        return pii(y-x,sqr(y-x+1));
    ll m = (x+y)/2;
    pii rx = get(x,m,left,right);
    pii ry = get(m+1,y,left,right);
    ll len = m-x+1;
    if(rx.first==len-1){
        if(right>m && left<=x){
            //extend to the right
            rx.first = y-x;
            rx.second = rx.second * mypow(len%oo,oo-2)%oo * (min(len, right-m)*2%oo) %oo;
        }
    }
    if(ry.first==len-1){
        if(left<=m && y<=right){
            //extend to the top
            ry.first = y-x;
            ry.second = ry.second * mypow(len%oo,oo-2)%oo * (min(len, m-left+1)*2%oo) %oo;
        }
    }
    if(rx.first<ry.first) rx=ry;
    else if(rx.first==ry.first) rx.second = (rx.second + ry.second)%oo;
    return rx;
}

int main(){
//    freopen("input.txt","r",stdin);
    ll T,L,R;
    cin>>T;
    while(T--){
        cin>>L>>R;
        pii ret = get(0,(1ll<<60)-1,L,R);
        cout<<ret.first<<' '<<ret.second%oo<<endl;
    }
}
