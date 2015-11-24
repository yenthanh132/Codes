#include <bits/stdc++.h>

#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> iii;
typedef long long ll;

int T,n,a[111];
set<iii> mys;

int main() {
    //freopen("input.txt", "r", stdin);
    cin>>T;
    for(int tt=1; tt<=T; ++tt){
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>a[i];
        sort(a+1,a+n+1);
        mys.clear();
        for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) for(int k=j+1; k<=n; ++k){
            int x=a[i], y=a[j], z=a[k];
            if(x+y>z && x+z>y && y+z>x){
                mys.insert(iii(x,pii(y,z)));
            }
        }
        printf("Case #%d: %d\n",tt,sz(mys));
    }
    return 0;
}

