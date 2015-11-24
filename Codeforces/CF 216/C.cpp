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

int d[maxn],n;
vector<pii> e[maxn];
vector<int> list;

void dfs(int u, int p){
    d[u]=0; 
    int v;
    REP(i,sz(e[u])){
        v=e[u][i].fi;
        if(v==p) continue;
        dfs(v,u);
        if(e[u][i].se) d[u]++;
    }
}

void dfs2(int u, int p, int t){
    if(d[u]==0 && u!=1 && t==2){
        list.pb(u);   
        return;
    }
    int v;
    REP(i,sz(e[u])){
        v=e[u][i].fi;
        if(v==p) continue;
        dfs2(v,u,e[u][i].se);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);   
    scanf("%d",&n);
    int u,v,t;
    FOR(i,1,n-1){
        scanf("%d%d%d",&u,&v,&t);
        e[u].pb(pii(v,t));
        e[v].pb(pii(u,t));   
    }
    
    dfs(1,-1);
    dfs2(1,-1,1);
    printf("%d\n",sz(list));
    REP(i,sz(list)) printf("%d ",list[i]);
}
