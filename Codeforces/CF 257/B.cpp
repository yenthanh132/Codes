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
#define oo 1000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<ll,int> pii;


const int maxn=100007;

int res,n,m,k,way[maxn];
vector<pii> e[maxn];
ll d[maxn];
bool free1[maxn];
set<pii> mys;

void dijkstra(){
    reset(free1,1);
    for(int u=1; u<=n; ++u) if(d[u]!=oo){
        mys.insert(pii(d[u],u));
        way[u]=1;
    }
    while(!mys.empty()){
        int u=mys.begin()->second; mys.erase(mys.begin());
        free1[u]=0;
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i].first;
            if(free1[v] && d[v]>d[u]+e[u][i].second){
                if(d[v]!=oo) mys.erase(pii(d[v],v));
                d[v]=d[u]+e[u][i].second;
                way[v]=way[u];
                mys.insert(pii(d[v],v));
            }else
                if(d[v]==d[u]+e[u][i].second){
                   way[v]+=way[u];
                   way[v]=min(way[v],2);
                }
        }
    }
}

vector<pii> station;

int main(){
    //freopen("input.txt","r",stdin);

    int u,v,w;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<m; ++i){
        scanf("%d%d%d",&u,&v,&w);
        e[u].pb(pii(v,w));
        e[v].pb(pii(u,w));
    }

    d[1]=0;
    for(int u=2; u<=n; ++u) d[u]=oo;
    res=0;
    for(int i=0; i<k; ++i){
        scanf("%d%d",&v,&w);
        if(d[v]>w){
            if(d[v]!=oo) ++res;
            d[v]=w;
        }else
            ++res;
    }
    for(int u=2; u<=n; ++u) if(d[u]!=oo) station.pb(pii(u,d[u]));
    dijkstra();

    for(int i=0; i<sz(station); ++i){
        v=station[i].first; w=station[i].second;
        if(d[v] < w || (d[v] == w && way[v]>1)) ++res;
    }

    cout<<res<<endl;
}
