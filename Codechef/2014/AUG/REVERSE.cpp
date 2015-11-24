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

vector<pii> e[maxn];
int n,m,dis[maxn];
bool free1[maxn];
set<pii> mys;

int dijkstra(){
    for(int i=1; i<=n; ++i) dis[i]=oo;
    dis[1]=0;
    mys.insert(pii(0,1));
    reset(free1,1);
    while(!mys.empty()){
        int u=mys.begin()->second; mys.erase(mys.begin());
        free1[u]=0;
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i].first, w=e[u][i].second;
            if(free1[v] && dis[v] > dis[u] + w){
                if(dis[v]!=oo) mys.erase(pii(dis[v],v));
                dis[v] = dis[u] + w;
                mys.insert(pii(dis[v],v));
            }
        }
    }
    if(dis[n]==oo) return -1;
    return dis[n];
}

int main(){
    //freopen("input.txt","r",stdin);
    int u,v;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(pii(v,0));
        e[v].pb(pii(u,1));
    }
    printf("%d\n",dijkstra());
}
