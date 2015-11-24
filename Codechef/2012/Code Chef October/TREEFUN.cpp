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

const int maxn  = 50007;

int n,m,f[maxn][16],d[maxn],T, cnt[maxn];
vector<int> a[maxn],list;
int x,y,k,root;
bool ok, mark[maxn];

void DFS(int u, int p){
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v!=p){
            f[v][0]=u;
            d[v]=d[u]+1;
            DFS(v,u);
        }
    }
}

int lca(int u, int v){
    if(d[u]>d[v]) swap(u,v);
    REPD(i,16)
        if(((d[v]-d[u])>>i)&1) v=f[v][i];
    if(u==v) return u;
    REPD(i,16) if(f[u][i]!=f[v][i]){
        u=f[u][i];
        v=f[v][i];
    }
    return f[u][0];
}

int dis(int u, int v){
    int r=lca(u,v);
    return d[u]+d[v]-d[r]*2;
}

//---------------------------------------------
//FOR k>300

void DFS2(int u, int p){
    if(ok) return;
    int v;
    bool check=1;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p) continue;
        DFS2(v,u);
        if(cnt[v]>1) check=0;
        cnt[u]+=cnt[v];
    }
    if(k-cnt[u]>1) check=0;
    if(check && !mark[u]) ok=1;
}

//-------------------------

int main(){
   freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(index,T){
        scanf("%d%d",&n,&m);
        
        FOR(i,1,n) a[i].clear();
        FOR(i,1,n-1){
            scanf("%d%d",&x,&y);
            a[x].pb(y);
            a[y].pb(x);
        }
        reset(f,0); d[1]=0;
        DFS(1,0);
        FOR(i,1,16)
            FOR(u,1,n) f[u][i]=f[f[u][i-1]][i-1];
            
        FOR(i,1,m){
            scanf("%d",&k);
            if(k==2){
                scanf("%d%d",&x,&y);
                printf("%d\n",dis(x,y)-1);
            }else{
                list.clear();
                REP(i,k){
                    scanf("%d",&x);
                    list.pb(x);
                }
                if(k<=300){
                    root=lca(list[0],list[1]);
                    ok=1;
                    REP(i,k-1) if(ok) FOR(j,i+1,k-1) if(lca(list[i],list[j])!=root){
                        ok=0;
                        break;
                    }
                    printf("%d\n",ok);
                }else{
                    reset(cnt,0); reset(mark,0);
                    REP(i,k) cnt[list[i]]=mark[list[i]]=1;
                    ok=0;
                    DFS2(1,0);
                    printf("%d\n",ok);
                }
            }
        }                
    }
    return 0;
}
