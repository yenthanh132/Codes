#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


int main(){
    ll n;
    cin>>n;
    int res=0;
    for(ll i=1; i*2+3*i*(i-1)/2 <= n; ++i){
        if((n-i*2-3*i*(i-1)/2)%3==0) ++res;
    }
    cout<<res<<endl;
}
