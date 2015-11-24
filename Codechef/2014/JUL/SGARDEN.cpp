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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;

int a[maxn],n,t,mul[maxn];
int cnt;

void dfs(int u){
    ++cnt;
    int v=a[u];
    a[u]=-1;
    if(a[v]!=-1) dfs(v);
}

void doFrac(int v){
    for(int i=2; i*i<=v; ++i) if(v%i==0){
        int c=0;
        while(v%i==0) v/=i, ++c;
        mul[i]=max(mul[i],c);
    }
    if(v>1) mul[v]=max(mul[v],1);
}

ll mypow(ll base, int n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

int main(){
    //freopen("input.txt","r",stdin);

    scanf("%d",&t);
    REP(tt,t){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",&a[i]);
        reset(mul,0);
        FOR(u,1,n) if(a[u]!=-1){
            cnt=0;
            dfs(u);
            doFrac(cnt);
        }
        ll res=1;
        FOR(v,2,n) if(mul[v]) res=res*mypow(v,mul[v])%oo;

        cout<<res<<endl;
    }

    return 0;
}

