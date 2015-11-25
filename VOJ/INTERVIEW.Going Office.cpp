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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=200001;

struct tedge{int x,y,w; bool locked;} e[maxn*2];

int n,M,m,q,mindis,start,finish,link1[maxn*2],head[maxn];
set<pii> path,bridge;
map<pii,int> ans;

void pushedge(int u, int v, int w){
    e[++M].x=u; e[M].y=v; e[M].w=w; e[M].locked=false;
    link1[M]=head[u]; head[u]=M;
    e[++M].x=v; e[M].y=u; e[M].w=w; e[M].locked=false;
    link1[M]=head[v]; head[v]=M;
}

int doi(int u){
    if(u&1) return(u+1); else return(u-1);
}

int d[maxn],trace[maxn];

int dijkstra(){
    set<pii> myset;
    fill_n(d,n,oo);
    d[start]=0;
    myset.insert(pii(0,start));
    trace[start]=0;
    int u,i,v,w;
    while (!myset.empty()){
        u=myset.begin()->se; myset.erase(myset.begin());
        if(u==finish) break;
        i=head[u];
        while(i){
            v=e[i].y; w=e[i].w;
            if(d[v]>d[u]+w){
                if(d[v]!=oo) myset.erase(myset.find(pii(d[v],v)));
                d[v]=d[u]+w;
                trace[v]=i;
                myset.insert(pii(d[v],v));
            }
            i=link1[i];
        }
    }
    i=trace[finish];
    while(i){
        path.insert(pii(e[i].x,e[i].y));
        path.insert(pii(e[i].y,e[i].x));
        i=trace[e[i].x];
    }
    return d[finish];
}

int dijkstra(pii xedge){
    set<pii> myset;
    fill_n(d,n,oo);
    d[start]=0;
    myset.insert(pii(0,start));
    int u,i,v,w;
    while (!myset.empty()){
        u=myset.begin()->se; myset.erase(myset.begin());
        if(u==finish) break;
        i=head[u];
        while(i){
            v=e[i].y; w=e[i].w;
            if(pii(e[i].x,e[i].y)!=xedge && pii(e[i].y,e[i].x)!=xedge && d[v]>d[u]+w){
                if(d[v]!=oo) myset.erase(myset.find(pii(d[v],v)));
                d[v]=d[u]+w;
                myset.insert(pii(d[v],v));
            }
            i=link1[i];
        }
    }
    return d[finish];
}

//-----------------------------------
int num[maxn],low[maxn],count1;
void dfs(int u){
    num[u]=++count1; low[u]=n+1;
    int i=head[u],v;
    while(i){
        v=e[i].y;
        if(!e[i].locked){
            e[doi(i)].locked=1;
            if(num[v]==0){
                dfs(v);
                if(num[u]<low[v]) bridge.insert(pii(u,v)), bridge.insert(pii(v,u));
                low[u]=min(low[u],low[v]);
            }else low[u]=min(low[u],num[v]);
        }
        i=link1[i];
    }
}
            
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    M=0;
    int u,v,w;
    reset(head,0);
    REP(i,m){
        scanf("%d%d%d",&u,&v,&w);
        pushedge(u,v,w);
    }
    scanf("%d%d",&start,&finish);
    mindis=dijkstra();
    reset(num,0); count1=0;
    dfs(1);
    
    scanf("%d",&q);
    REP(i,q){
        scanf("%d%d",&u,&v);
        if(path.find(pii(u,v))==path.end()) printf("%d\n",mindis);
        else if(bridge.find(pii(u,v))!=bridge.end()) printf("Infinity\n");
        else if(ans.find(pii(u,v))!=ans.end()) printf("%d\n",ans[pii(u,v)]);
        else{
            int val=dijkstra(pii(u,v));
            ans[pii(u,v)]=ans[pii(v,u)]=val;
            printf("%d\n",val);
        }
    }
    //getch();
    return 0;
}
