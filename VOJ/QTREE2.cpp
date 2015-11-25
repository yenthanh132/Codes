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

const int maxn=10007;

int f[maxn][14],d[maxn],n,dis[maxn];
vector<pii> a[maxn];

void dfs(int u){
    int v;
    REP(i,sz(a[u])){
        v=a[u][i].fi;
        if(!d[v]){
            dis[v]=dis[u]+a[u][i].se;
            d[v]=d[u]+1;
            f[v][0]=u;
            dfs(v);
        }
    }
}

int lca(int u, int v){
    if(d[u]>d[v]) swap(u,v);
    REPD(i,14) if(((d[v]-d[u])>>i)&1) v=f[v][i];
    if(v==u) return v;
    REPD(i,14) if(f[u][i]!=f[v][i]){
        u=f[u][i]; v=f[v][i];
    }
    return f[u][0];
}

int dist(int u, int v){
    int r=lca(u,v);
    return dis[u]+dis[v]-dis[r]*2;
}

int jump(int u, int len){
    REP(i,14) if((len>>i)&1) u=f[u][i];
    return u;
}

int kth(int u, int v, int k){
    int r=lca(u,v);
    if(d[u]-d[r]+1>=k) return jump(u,k-1); else return jump(v,d[u]+d[v]-d[r]*2-k+1);
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int test,u,v,w,k;
    char buf[7];;
    
    scanf("%d",&test);
    REP(index,test){
        scanf("%d",&n);
        FOR(i,1,n) a[i].clear();
        
        FOR(i,1,n-1){
            scanf("%d%d%d",&u,&v,&w);
            a[u].pb(pii(v,w));
            a[v].pb(pii(u,w));
        }
        reset(d,0);
        d[1]=1; dis[1]=0;
        dfs(1);
        FOR(i,1,13) FOR(u,1,n) f[u][i]=f[f[u][i-1]][i-1];
        scanf("%s",buf);
        while(buf[1]!='O'){
            if(buf[0]=='D'){
                scanf("%d%d",&u,&v);
                printf("%d\n",dist(u,v));
            }else{
                scanf("%d%d%d",&u,&v,&k);
                printf("%d\n",kth(u,v,k));
            }
            scanf("%s",buf);
        }
        puts("");
    }
    
    //getch();
    return 0;
}
