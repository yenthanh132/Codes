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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=5007;

int n,d[maxn],h[maxn],lockid,weight[maxn];
ll f[maxn][2],minval,cnt,sum;
pii e[maxn];
vector<int> a[maxn],w[maxn],id[maxn];

void dfs1(int u, int p){
    cnt++;
    int v;
    d[u]=1;
    f[u][0]=0;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p || id[u][i]==lockid) continue;
        dfs1(v,u);
        f[u][0]+=f[v][0] + 1ll*w[u][i]*d[v];
        d[u]+=d[v];
    }
}

void dfs2(int u, int p){
    minval=min(minval,f[u][0]+f[u][1]);
    sum+=f[u][0]+f[u][1];
    int v;
  
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p || id[u][i]==lockid) continue;
        f[v][1]+=f[u][1]+f[u][0]-f[v][0]+w[u][i]*(cnt-2*d[v]);
        dfs2(v,u);
    }
}    
    

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    
    scanf("%d",&n);
    int u,v;
    REP(i,n-1){
        scanf("%d%d%d",&u,&v,&weight[i]);
        a[u].pb(v); a[v].pb(u);
        w[u].pb(weight[i]); w[v].pb(weight[i]);
        id[u].pb(i); id[v].pb(i);
        e[i]=pii(u,v);
    }
    
    ll minv=oo;
    ll c1,c2,v1,v2;
    REP(i,n-1){
        reset(f,0);
        sum=0;
        lockid=i;
        
        cnt=0;
        minval=oo;
        dfs1(e[i].fi,-1);    
        c1=cnt;
        dfs2(e[i].fi,-1);
        v1=minval;
        
        cnt=0;
        minval=oo;
        dfs1(e[i].se,-1);    
        c2=cnt;
        dfs2(e[i].se,-1);
        v2=minval;
        
        minv=min(minv,sum/2 + c1*v2 + c2*v1 + c1*c2*weight[i]);
    }
    
    cout<<minv<<endl;
    
    //getch();
    return 0;
}
            
    
