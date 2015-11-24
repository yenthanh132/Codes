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

const int maxn=1007;
const int maxc=107;



int dis[maxn][maxc],n,m,q,p[maxn];
bool free1[maxn][maxc];

struct node{
    int v,c,cost;
    node (int _v, int _c, int _cost){
        v=_v;
        c=_c;
        cost=_cost;
    }
    bool operator < (const node &a) const{
        return cost>a.cost;
    }
};

vector<pii> e[maxn];

void solve(int cap, int s, int f){
    FOR(i,1,n) FOR(j,0,cap) dis[i][j]=oo, free1[i][j]=1;
    dis[s][0]=0;
    priority_queue<node> myq;
    myq.push(node(s,0,0));
    int u,v,c,d,cost;
    while(!myq.empty()){
        node t=myq.top(); myq.pop();
        u=t.v; c=t.c; cost=t.cost;
        if(u==f){
            printf("%d\n",cost);
            return;
        }
        free1[u][c]=0;
        if(c<cap && free1[u][c+1] && dis[u][c+1]>cost+p[u]){
            dis[u][c+1]=cost+p[u];
            myq.push(node(u,c+1,dis[u][c+1]));
        }
        REP(i,sz(e[u])){
            v=e[u][i].fi; d=e[u][i].se;
            if(c<d) continue;
            if(free1[v][c-d] && dis[v][c-d]>cost){
                dis[v][c-d]=cost; 
                myq.push(node(v,c-d,dis[v][c-d]));
            }
        }
    }
    puts("impossible");
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    
    while(scanf("%d%d",&n,&m)!=EOF){
        FOR(i,1,n) e[i].clear();
        
        FOR(i,1,n) scanf("%d",&p[i]);
        int u,v,c;
        REP(i,m){
            scanf("%d%d%d",&u,&v,&c);
            u++; v++;
            e[u].pb(pii(v,c));
            e[v].pb(pii(u,c));
        }
        scanf("%d",&q);
        REP(i,q){
            scanf("%d%d%d",&c,&u,&v);
            u++; v++;
            solve(c,u,v);
        }
    }
    
    //getch();
    return 0;
}
