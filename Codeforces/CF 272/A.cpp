#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll a,b;

int main(){
    //freopen("input.txt","r",stdin);
    cin>>a>>b;
    ll v=(a*(a+1)/2) % oo;
    ll rs = b*(b-1)/2; rs%=oo;
    ll res = 0;
    for(ll i=1; i<=a; ++i) res=(res+rs*(i*b%oo+1)%oo)%oo;
    cout<<res<<endl;
}

