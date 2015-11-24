#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;

int a[maxn],n,mys[maxn],last;
vector<int> pos[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n); for(int i=1; i<=n; ++i) scanf("%d",&a[i]), pos[a[i]].pb(i);
    ll res = 0;
    last = 0;
    mys[0]=0;
    for(int i=1; i<=n; ++i){
        while(last>0 && a[mys[last]] <= a[i]) --last;
        int pre = mys[last];
        mys[++last] = i;
        int val = upper_bound(pos[a[i]].begin(), pos[a[i]].end(), i-1) - lower_bound(pos[a[i]].begin(),pos[a[i]].end(), pre+1);
        res += val;
    }
    cout<<res*2<<endl;
}

