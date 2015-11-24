#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll get_div(ll v){
    ll res = 1;
    for(int i=2; i*i<=v; ++i){
        int c=1;
        while(v%i==0){
            v/=i;
            ++c;
        }
        res*=c;
    }
    if(v>1) res*=2;
    return res;
}

ll f(ll i){
    ll j=i+1;
    if(i&1) j/=2; else i/=2;
    return get_div(i)*get_div(j);
}

int main(){
//    freopen("input.txt","r",stdin);
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        ll res,i;
        for(i=1; f(i)<=n;i++);
        res=i*(i+1)/2;
        cout<<res<<endl;
    }
}

