#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

int T,n,ans[111111];
vector<pii> p;
vector<pli> arr;

ll area2(vector<pii> &p){
    int n=sz(p);
    ll A=0,B=0;
    p.pb(p[0]);
    for(int i=0; i<n; ++i){
        A += 1ll*p[i].first*p[i+1].second;
        B += 1ll*p[i+1].first*p[i].second;
    }
    p.pop_back();
    return abs(A-B);
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>T;
    while(T--){
        cin>>n;
        int m,x,y;
        arr.clear();
        for(int i=0; i<n; ++i){
            cin>>m; p.clear();
            for(int j=0; j<m; ++j){
                cin>>x>>y;
                p.pb(pii(x,y));
            }
            arr.pb(pli(area2(p), i));
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; ++i) ans[arr[i].second]=i;
        for(int i=0; i<n; ++i) cout<<ans[i]<<' '; cout<<endl;
    }
}

