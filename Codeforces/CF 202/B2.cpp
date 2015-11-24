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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;
int n,deg[maxn];
vector<int> a[maxn];
ll s[maxn],g[maxn],sum;

ll gcd(ll a, ll b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    if(a>sum || b>sum) return sum+1;
    ll v=a/gcd(a,b);
    if((v*b)/b!=v) return sum+1; else return v*b;
}

void dfs(int u, int p){
    if(s[u]){
        g[u]=1;
        return;
    }
    int v,cnt=0;
    ll mu=1;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p) continue;
        dfs(v,u);
        ++cnt;
        mu=lcm(mu,g[v]);
    }
    g[u]=0;
    ll minv=oo;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p) continue;
        minv=min(minv, s[v]-s[v]%mu);
    }
    g[u]=mu*cnt;
    s[u]=minv*cnt;
}

int main(){
    //freopen("input.txt","r",stdin);

    scanf("%d",&n);
    sum=0;
    FOR(i,1,n) scanf("%I64d",&s[i]), sum+=s[i];
    int x,y;
    reset(deg,0);
    REP(i,n-1){
        scanf("%d%d",&x,&y);
        a[x].pb(y); a[y].pb(x);
        deg[x]++; deg[y]++;
    }
    FOR(u,2,n) if(deg[u]==1 && s[u]==0){
        cout<<sum<<endl;
        return 0;
    }
    dfs(1,-1);
    cout<<sum-s[1]<<endl;
    return 0;
}

