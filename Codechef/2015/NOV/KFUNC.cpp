#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll cnt[10];

void gen(ll d, ll n, int sign){
    ll x=__gcd(d,9ll);
    ll c=9/x;
    for(int i=0; i < c; ++i) cnt[i*x] += sign*(n/c);
    n%=c;
    int it=0;
    for(int i=0; i < n; ++i){
        cnt[it] += sign;
        it = (it+d)%9;
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        ll a,d,l,r;
        cin>>a>>d>>l>>r;
        a%=9; d%=9;
        if(d==0){
            ll v=a;
            if(v==0) v=9;
            cout<<(r-l+1)*v<<endl;
        }else{
            reset(cnt,0);
            gen(d,r,1);
            gen(d,l-1,-1);
            ll res=0;
            for(int i=0; i<10; ++i){
                int v=(i+a)%9;
                if(v==0) v=9;
                res += v*cnt[i];
            }
            cout<<res<<endl;
        }
    }
}

