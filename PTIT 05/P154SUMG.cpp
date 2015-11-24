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
    return gcd(b, a%b);
}

int main(){
//    freopen("input.txt","r",stdin);
    ll l,r;
    cin>>l>>r;
    for(ll a=l; a<=r; ++a)
        for(ll b=a+1; b<=r; ++b)
            for(ll c=b+1; c<=r; ++c)
                if(gcd(a,b)==1 && gcd(b,c)==1 && gcd(a,c)>1){
                    cout<<a<<' '<<b<<' '<<c<<endl;
                    return 0;
                }
    cout<<-1<<endl;
}

