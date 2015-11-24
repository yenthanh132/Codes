#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    ll a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&a,&b);
        ll d=gcd(a,b);
        b/=d;
        while(gcd(d,b)>1){
            ll d2=gcd(d,b);
            b/=d2;
        }
        if(b>1) puts("No");
        else puts("Yes");
    }
}

