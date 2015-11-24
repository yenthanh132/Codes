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
int n,d[maxn],val[maxn],visited[maxn];
vector<int> e[maxn];

void dfs(int u, int p){
    bool found_unvisisted = 0;
    d[u]=0;
    val[u]=0;
    visited[u]=0;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        dfs(v,u);
        val[u] += val[v];
        if(d[v]==1){
            if(d[u]==0) d[u]=1;
            else{
                d[u]=0;
                ++val[u];
            }
            visited[u]=1;
        }
        if(!visited[v]) found_unvisisted = 1;
    }
    if(!visited[u] && found_unvisisted){
        d[u] = 1;
        visited[u]=1;
    }

}

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%d",&n);
        for(int u=1; u<=n; ++u) e[u].clear();
        int u,v;
        for(int i=0; i<n-1; ++i){
            scanf("%d%d",&u,&v);
            ++u; ++v;
            e[u].pb(v);
            e[v].pb(u);
        }

        dfs(1,-1);
        cout<<d[1]+val[1]<<endl;
    }
    return 0;
}
