#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

vector<pii> ans1,ans2;
int main(){
//    freopen("input.txt","r",stdin);
    ll x;
    cin>>x;
    ll s1 = 0, s2 = 0;
    vector<pii> ans;
    for(ll i=1; ; ++i){
        s1 += i;
        s2 += i*i;
        if(s2 > x) break;
        if((x-s2)%s1==0){
            ans1.pb(pii(i,(x-s2)/s1+i));
            if((x-s2)/s1>0) ans2.pb(pii((x-s2)/s1+i,i));
        }
    }
    printf("%d\n",sz(ans1)+sz(ans2));
    for(int i=0; i<sz(ans1); ++i) printf("%I64d %I64d\n",ans1[i].first,ans1[i].second);
    for(int i=sz(ans2)-1; i>=0; --i) printf("%I64d %I64d\n",ans2[i].first,ans2[i].second);

}

