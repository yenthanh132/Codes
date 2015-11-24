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

const int maxn=507;

int f[maxn][maxn],cnt[maxn],dis[maxn];
vector<pii> a[maxn];
int m,n;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf("%d%d",&n,&m);
    FOR(u,1,n) FOR(v,1,n) if(u==v) f[u][v]=0; else f[u][v]=oo;
    
    int u,v,w;
    REP(i,m){
        scanf("%d%d%d",&u,&v,&w);
        f[u][v]=min(f[u][v],w);
        f[v][u]=min(f[v][u],w);
        a[u].pb(pii(v,w)); a[v].pb(pii(u,w));
    }
    
    FOR(k,1,n) FOR(u,1,n) FOR(v,1,n) f[u][v]=min(f[u][v],f[u][k]+f[k][v]);
    FOR(u,1,n-1){
        FOR(v,1,n) dis[v]=oo;
        dis[u]=0; cnt[u]=0;
        int k;
        FOR(v,1,n){
            REP(i,sz(a[v])){
                k=a[v][i].fi;
                if(dis[v] > f[u][k] + a[v][i].se){
                    dis[v] = f[u][k] + a[v][i].se;
                    cnt[v]=1;   
                }else if(dis[v] == f[u][k] + a[v][i].se)
                    ++cnt[v];
            }
        }   
        FOR(v,u+1,n){
            int res=0;
            if(f[u][v]!=oo)
                FOR(k,1,n) if(dis[k]+f[k][v]==f[u][v]) res+=cnt[k];
            printf("%d ",res);
        }
    }
    return 0;
}
