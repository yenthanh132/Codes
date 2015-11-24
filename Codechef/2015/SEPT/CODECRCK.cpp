#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


long double calc(ll i, ll k, ll s, long double a, long double b){
    ll n=k-i;
    long double v=(a+b);

    if(abs(n)&1){
        s-=(n-1)*2;
        v=2*(sqrt(2)*a + sqrt(6)*b);
    }else{
        s-=n*2;
    }

    if(abs(s)>100) v=0;
    else{
        for(ll i=1; i<=s; ++i) v/=2;
        for(ll i=-1; i>=s; --i) v*=2;
    }
    return v;
}

int main(){
//    freopen("input.txt","r",stdin);
    long double a,b;
    ll s,i,k;
    cin>>i>>k>>s>>a>>b;
    cout.precision(2);
    cout<<fixed<<calc(i,k,s,a,b)<<endl;

}

