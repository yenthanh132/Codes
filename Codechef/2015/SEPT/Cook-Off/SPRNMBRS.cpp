#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll phi(ll n){
    ll t=n;
    for(ll i=2; i*i<=n; ++i) if(n%i==0){
        t=t*(i-1)/i;
        while(n%i==0) n/=i;
    }
    if(n>1) t=t*(n-1)/n;
    return t;
}
//
//void gen(int n){
//    for(int i=2; i*i<=n; ++i){
//        while(n%i==0){
//            cout<<i<<'.';
//            n/=i;
//        }
//    }
//    if(n>1) cout<<n<<'.';
//    cout<<endl;
//}

int main(){
//    freopen("input.txt","r",stdin);
    vector<ll> lst;
    ll p2=2;
    while(p2<=(ll)(1e18)){
        ll t=p2;
        while(t<=(ll)(1e18)){
            lst.pb(t);
            t*=3;
        }
        p2*=2;
    }
    lst.pb(1);
    sort(lst.begin(),lst.end());
//    for(int i=0; i<sz(lst); ++i)
//        if(lst[i]%phi(lst[i])==0){
//            cout<<lst[i]<<endl;
//        }
    int T;
    ll L,R;
    cin>>T;
    while(T--){
        cin>>L>>R;
        cout<<upper_bound(lst.begin(),lst.end(),R)-lower_bound(lst.begin(),lst.end(),L)<<endl;
    }
}

