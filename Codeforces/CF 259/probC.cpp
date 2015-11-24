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

const int maxn=100007;

int visit[maxn],n,m,res[maxn*4],k,x[maxn];
vector<int> e[maxn];

void dfs(int u, int p){
    res[++k]=u;
    x[u]^=1;
    visit[u]=1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(visit[v]) continue;
        dfs(v,u);
        res[++k]=u;
        x[u]^=1;
    }
    if(x[u] && p!=-1){
        x[u]^=1; x[p]^=1;
        res[++k] = p;
        res[++k] = u;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    int u,v;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(v); e[v].pb(u);
    }
    for(int i=1; i<=n; ++i) scanf("%d",&x[i]);
    reset(visit,0); k = 0;
    for(int i=1; i<=n; ++i) if(x[i]==1){
        dfs(i,-1);
        int s=1;
        if(x[i]) ++s, x[i]^=1;
        for(int j=1; j<=n; ++j) if(x[j]){
            puts("-1");
            return 0;
        }
        printf("%d\n",k-s+1);
        for(;s<=k; ++s) printf("%d ",res[s]);
        return 0;
    }
    puts("0");
}
