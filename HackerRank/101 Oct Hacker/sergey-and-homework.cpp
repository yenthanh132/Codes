#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,int> pli;
const int maxn=100007;

int n,k;
ll a[maxn],b[maxn];

ll calc(ll y){
    ll res=0;
    for(int i=1; i<=n; ++i){
        ll v=a[i]*b[i];
        if(v <= y) continue;
        v -= y;
        res += (v-1)/b[i] + 1;
    }
    return res;
}

set<pli> mys;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
    for(int i=1; i<=n; ++i) scanf("%lld",&b[i]);
    ll l=0, r=ll(1e18), mid, pos=r;
    while(l<=r){
        mid=(l+r)/2;
        if(calc(mid) < k){
            r = mid-1;
            pos = mid;
        }else{
            l = mid+1;
        }
    }

    k -= calc(pos);
    for(int i=1; i<=n; ++i){
        ll v = a[i]*b[i];
        if(v <= pos) continue;
        v -= pos;
        a[i] -= (v-1)/b[i]+1;
    }

    for(int i=1; i<=n; ++i) if(a[i]>0) mys.insert(pli(-a[i]*b[i],i));
    while(k>0){
        if(mys.empty()) break;
        pli p = *mys.begin(); mys.erase(mys.begin());
        int i=p.second;
        --a[i];
        --k;
        if(a[i]>0) mys.insert(pli(-a[i]*b[i],i));
    }
    for(int i=1; i<=n; ++i) printf("%lld ",a[i]);
}

