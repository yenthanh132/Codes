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
//    freopen("input.txt","r",stdin);
    ll k,n,w;
    cin>>k>>n>>w;
    ll cost = 0, v = 0;
    for(int i=1; i<=w; ++i){
        v+=k;
        cost+=v;
    }
    ll res = max(cost-n,0ll);
    cout<<res<<endl;
}

