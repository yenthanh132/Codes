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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
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
typedef pair<pii,int> iii;

#define maxn 1007

int n,m,res,t,d[maxn],trace[maxn],trace_t[maxn],parent[maxn],mark[maxn],start,markid;
vector<int> a[maxn];
bool chutrinh,free1[maxn],free2[maxn],del[maxn][maxn];
queue<int> myqueue;

void dfs_ct(int u){
    if (chutrinh) return;
    free1[u]=false;
    free2[u]=false;
    REP(i,sz(a[u])){
        int v=a[u][i];
        if(!free1[v] && v!=parent[u]){chutrinh=true; return;}
        if(free2[v]) parent[v]=u, dfs_ct(v);
    }
    free1[u]=true;
}
    

void dfs(int u, int sum){
    bool ok=false;
    trace_t[sum]=u;
    mark[u]=markid;
    vector<int> ds;
    REP(i,sz(a[u])) if (mark[a[u][i]]!=markid && !del[u][a[u][i]]){
        ds.pb(a[u][i]);
        ok=true;
    }
    if(ok){
        int r=rand()%sz(ds);
        parent[ds[r]]=u;
        dfs(ds[r],sum+1);
    }
    if(!ok){
        if (sum>res){res=sum; FOR(i,1,res) trace[i]=trace_t[i];}
        start=u;
        
        ds.clear();
        REP(i,sz(a[u])) if(a[u][i]!=parent[u] && !del[u][a[u][i]]) ds.pb(a[u][i]);
        if(ds.empty()) return;
        int r=rand()%sz(ds);
        del[u][ds[r]]=del[ds[r]][u]=true;
        
    }
}

void dfs2(int u, int sum){
    if (n>40 && d[u]>=sum) return;
    d[u]=sum;
    trace_t[sum]=u;
    free1[u]=false;
    REP(i,sz(a[u])) if (free1[a[u][i]]) dfs2(a[u][i],sum+1);
    free1[u]=true;
    if (sum>res){res=sum; FOR(i,1,res) trace[i]=trace_t[i];}
}

void solve(int u){
    int i,v;
    d[u]=1; free1[u]=false;
    myqueue.push(u); 
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(a[u])){
            v=a[u][i];
            if(free1[v]){d[v]=d[u]+1; free1[v]=false; myqueue.push(v);}
        }
    }
        
    u=0;
    for(i=1;i<=n;i++) if(u==0 || d[u]<d[i]) u=i;
    d[u]=1; trace_t[u]=0; reset(free2,true); free2[u]=false;
    myqueue.push(u);
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(a[u])){
            v=a[u][i];
            if(free2[v]){d[v]=d[u]+1; trace_t[v]=u; free2[v]=false; myqueue.push(v);}
        }
    }
        
    vector<int> ds;
    u=0;
    for(i=1;i<=n;i++) if(u==0 || d[u]<d[i]) u=i;
    if(res<d[u]){
        res=d[u]; int t=res;
        while(u) trace[t--]=u, u=trace_t[u];
    }
}
//#include <conio.h>

int main(){
    srand(time(NULL));
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int i,u,v;
    for(i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        a[u].pb(v); a[v].pb(u);
    }
    
    chutrinh=false;
    reset(free1,true); reset(free2,true);
    for(i=1;i<=n && !chutrinh;i++) if (free2[i]) parent[i]=0, dfs_ct(i);

    if(chutrinh){
        if(40<n && n<=300){
            res=0;
            reset(del,false);
            reset(mark,0);
            start=rand()%n+1;
            for(markid=1;markid<=10000;markid++){ 
                reset(parent,0);
                dfs(start,1);
            }
        }else{
            res=0;
            for(i=1;i<=n;i++){
                reset(d,0); reset(free1,true);
                dfs2(i,1);
            }
        }
    }else{
        reset(free1,true);
        res=0;
        for(i=1;i<=n;i++) if(free1[i]) solve(i);
    }
    printf("%d\n",res);
    for(i=1;i<=res;i++) printf("%d ",trace[i]);
    
    //getch();
    return 0;
}
                
