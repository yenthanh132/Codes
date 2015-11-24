
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

vector<int> e[maxn];
int color[maxn],n;
ll f[maxn][2];

void dfs(int u, int p){
    int v;
    f[u][0]=f[u][1]=0;
    if(color[u]) f[u][1]=1; else f[u][0]=1;
    for(int i=0; i<sz(e[u]); ++i){
        v=e[u][i];
        if(v==p) continue;
        dfs(v,u);

        ll new1 = (f[u][0] * f[v][1] + f[u][1] * (f[v][0] + f[v][1])) % oo;
        ll new0 = (f[u][0] * f[v][0] + f[u][0] * f[v][1]) % oo;
        f[u][1]=new1;
        f[u][0]=new0;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<n; ++i){
        int v;
        scanf("%d",&v);
        e[v].pb(i);
        e[i].pb(v);
    }
    for(int i=0; i<n; ++i) scanf("%d",&color[i]);
    dfs(0,-1);
    cout<<f[0][1]<<endl;
}
