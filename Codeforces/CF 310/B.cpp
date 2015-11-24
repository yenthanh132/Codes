#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> iii;
const int maxn=200007;

ll l[maxn],r[maxn];
int n,m,ans[maxn];
vector<iii> b;
set<pii> a;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i){
        scanf("%I64d%I64d",&l[i],&r[i]);

        if(i>1){
            ll x=l[i]-r[i-1];
            ll y=r[i]-l[i-1];
            b.pb( iii( pii(y,x), i-1) );
        }
    }

    for(int i=1; i<=m; ++i){
        ll v;
        scanf("%I64d",&v);
        a.insert(pii(v,i));
    }

    reset(ans,-1);
    sort(b.begin(),b.end());
    for(int i=0; i<sz(b); ++i){
        iii obj = b[i];
        set<pii>::iterator it = a.lower_bound(pii(obj.first.second,0));
        if(it==a.end()) break;
        if(it->first > obj.first.first) break;
        //can match
        ans[obj.second] = it->second;
        a.erase(it);
    }

    bool ok=1;
    for(int i=1; i<n; ++i) if(ans[i]==-1) ok=0;
    if(!ok) puts("No");
    else{
        puts("Yes");
        for(int i=1; i<n; ++i) printf("%d ",ans[i]);
    }
}

