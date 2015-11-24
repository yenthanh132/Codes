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

const int maxn=100005;

ll mypow(ll base, int n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

int n,k,m,pos[maxn];
ll s[maxn],frac[maxn],a[maxn];
multiset<ll> mys;

void scan(int i, int n, int k, ll sum){
    if(i>k){
        mys.erase(mys.find(sum));
        return;
    }
    for(int j=pos[i-1]; j<=n; ++j){
        pos[i]=j;
        scan(i+1,n,k,sum+a[j]);
    }
}

void eraseAll(int n, int k){
    pos[0]=1;
    scan(1,n,k-1,a[n]);
}

int main(){
    //freopen("input.txt","r",stdin);

    frac[0]=1;
    for(int i=1; i<=100000; ++i) frac[i]=frac[i-1]*i%oo;
    int T;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d%d",&n,&k);
        m=frac[n+k-1]*mypow(frac[k],oo-2)%oo *mypow(frac[n-1],oo-2)%oo;
        mys.clear();
        for(int i=1; i<=m; ++i) scanf("%lld",&s[i]), mys.insert(s[i]);
        a[1]=*mys.begin()/k;
        for(int i=2; i<=n; ++i){
            eraseAll(i-1,k);
            a[i]=*mys.begin()-1ll*a[1]*(k-1);
        }
        for(int i=1; i<=n; ++i) printf("%lld ",a[i]);
        puts("");
    }

    return 0;
}
