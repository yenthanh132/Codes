#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=3006;

int a[maxn],n,b[maxn];
vector<pii> ans;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=1; i<=n; ++i){
        int u=i;
        for(int j=i+1; j<=n; ++j) if(a[j]<a[u]) u=j;
        if(u!=i){
            ans.pb(pii(i-1,u-1));
            swap(a[u],a[i]);
        }
    }
    cout<<sz(ans)<<endl;
    for(int i=0; i<sz(ans); ++i) cout<<ans[i].first<<' '<<ans[i].second<<endl;
}

