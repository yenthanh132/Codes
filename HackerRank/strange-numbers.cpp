#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<ll> ds;
map<ll,bool> mark;

int len(ll x){
    if(x==0) return 1;
    int r=0;
    while(x){
        ++r;
        x/=10;
    }
    return r;
}

int main(){
    //freopen("input.txt","r",stdin);
    for(int i=0; i<=9; ++i) ds.pb(i), mark[i]=1;
    for(int i=1; i<sz(ds); ++i){
        ll v=ds[i];
        int x=len(v);
        for(int l=x; l<=18; ++l){
            if((v*l)/l==v && v*l<=1000000000000000000ll && len(v*l)==l && !mark[v*l]){
                mark[v*l]=1;
                ds.pb(v*l);
            }
        }
    }
    sort(ds.begin(),ds.end());
    ll T,l,r;
    cin>>T;
    for(int i=0; i<T; ++i){
        cin>>l>>r;
        cout<<upper_bound(ds.begin(),ds.end(),r) - lower_bound(ds.begin(),ds.end(),l)<<endl;
    }
}

