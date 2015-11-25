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
const int maxm=200007;

struct edge{int x,y,w;} e[maxm];
int n,m,lab[maxn],f[maxn][17],maxv[maxn][17],d[maxn],sum,res;
vector<pii> a[maxn];
bool mark[maxn];

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void dsu(int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

void dfs(int u, int p){
    int v;
    REP(i,sz(a[u])) if(p!=a[u][i].fi){
        v=a[u][i].fi;
        f[v][0]=u;
        maxv[v][0]=a[u][i].se;
        d[v]=d[u]+1;
        dfs(v,u);
    }
}

int getmax(int u, int v){
    if(d[u]>d[v]) swap(u,v);
    int res=-oo;
    REPD(i,17) if(((d[v]-d[u])>>i)&1){
        res=max(res,maxv[v][i]);
        v=f[v][i];
    }
    if(u==v) return res;
    REPD(i,17) if(f[u][i]!=f[v][i]){
        res=max(res,max(maxv[u][i],maxv[v][i]));
        u=f[u][i]; v=f[v][i];
    }
    res=max(res,max(maxv[u][0],maxv[v][0]));
    return res;
}

bool mycmp(const edge &a, const edge &b){return a.w<b.w;}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) lab[i]=-1;
    FOR(i,1,m) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
    sort(e+1,e+m+1,mycmp);
    int c=n;
    sum=0;
    FOR(i,1,m){
        int r1=getroot(e[i].x), r2=getroot(e[i].y);
        if(r1!=r2){
            mark[i]=1;
            c--;
            sum+=e[i].w;
            dsu(r1,r2);
            a[e[i].x].pb(pii(e[i].y,e[i].w));
            a[e[i].y].pb(pii(e[i].x,e[i].w));
            if(c==1) break;
        }
    }
    
    d[1]=0;
    dfs(1,0);
    FOR(i,1,16)
        FOR(u,1,n){
            f[u][i]=f[f[u][i-1]][i-1];
            maxv[u][i]=max(maxv[u][i-1],maxv[f[u][i-1]][i-1]);
        }
    
    res=oo;
    FOR(i,1,m) if(!mark[i]) res = min(res, sum - getmax(e[i].x,e[i].y) + e[i].w);
    
    if(res==oo) puts("-1"); else printf("%d\n",res);
    
    getch();
    return 0;
}
        
    
    
        
