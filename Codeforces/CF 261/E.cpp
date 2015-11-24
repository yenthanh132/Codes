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

const int maxn=300007;

struct edge{
    int u,v,w;
}e[maxn];

bool cmp(const edge &a, const edge &b){
    return a.w<b.w;
}

int n,m,dp[maxn],f[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; ++i) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    sort(e+1,e+m+1,cmp);
    reset(dp,0);
    for(int i=1,j;i<=m; i=j+1){
        j=i;
        while(j+1<=m && e[j+1].w==e[i].w) ++j;
        for(int x=i; x<=j; ++x) f[e[x].u]=dp[e[x].u], f[e[x].v]=dp[e[x].v];
        for(int x=i; x<=j; ++x){
            int u = e[x].u, v = e[x].v;
            f[v] = max(f[v], dp[u] + 1);
        }
        for(int x=i; x<=j; ++x) dp[e[x].u] = f[e[x].u], dp[e[x].v] = f[e[x].v];
    }
    int res = 0;
    for(int i=1; i<=n; ++i) res = max(res,dp[i]);
    cout<<res<<endl;

    return 0;
}
