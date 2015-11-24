#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

vector<int> ans;

int main(){
//    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    if(n<=3) ans.pb(1);
    if(n==3) ans.pb(3);
    if(n>3){
        for(int i=2; i<=n; i+=2) ans.pb(i);
        for(int i=1; i<=n; i+=2) ans.pb(i);
    }
    cout<<sz(ans)<<endl;
    for(int i=0; i<sz(ans); ++i) cout<<ans[i]<<' ';
}
