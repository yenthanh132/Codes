#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=500007;

int a[maxn],n;
ll sl[maxn],sr[maxn];
map<ll,ll>cnt;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    reset(sl,0); reset(sr,0);
    for(int i=1; i<=n; ++i) sl[i]=sl[i-1]+a[i];
    for(int i=n; i>=1; --i) sr[i]=sr[i+1]+a[i];
    ll res = 0;
    for(int i=n-1; i>=2; --i){
        if(sr[i+1]*2 == sl[i]) ++cnt[sr[i+1]];
        res += cnt[sl[i-1]];
    }
    cout<<res<<endl;
}
