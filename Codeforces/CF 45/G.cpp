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

const int maxn=400007;

int n,list[maxn],list2[maxn],m;
ll f[maxn],ans[maxn];
vector<pii> a[maxn];
pii trace[maxn];
bool inDFS[maxn],mark[maxn],in_circle[maxn];
int deg[maxn],sum[maxn],cnt[maxn];
bool found;

void DFS(int u, int parent){
    if(found) return;
    mark[u]=1;
    inDFS[u]=1;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i].fi;
        if(!mark[v]){
            trace[v]=pii(u,a[u][i].se);
            DFS(v,u);
            
        }else if(v!=parent && inDFS[v]){
            found=1;
            list[m=1]=u;
            int t=u;
            in_circle[u]=1;
            while(t!=v){
                list2[m]=trace[t].se;
                list[++m]=trace[t].fi;
                t=trace[t].fi;
                in_circle[t]=1;
            }
            list2[m]=a[u][i].se;
        }
    }
    inDFS[u]=0;
}

void DFS2(int u, ll s, ll c){
    sum[u]+=s;
    cnt[u]+=c;  
    if(in_circle[u]) return; 
    int v;
    mark[u]=1;
    REP(i,sz(a[u])){
        v=a[u][i].fi;
        if(!mark[v]) DFS2(v,s+a[u][i].se*(c+1),c+1);
    }
}

#include <conio.h>

int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int u,v,t;
    reset(deg,0);
    FOR(i,1,n){
        scanf("%d%d%d",&u,&v,&t);
        a[u].pb(pii(v,t));
        a[v].pb(pii(u,t));
        deg[u]++; deg[v]++;
    }
    
    found=0;
    reset(mark,0); reset(inDFS,0); reset(in_circle,0);
    DFS(1,-1);
    
    reset(mark,0); reset(sum,0); reset(cnt,0);
    FOR(i,1,n) if(!mark[i] && deg[i]==1) DFS2(i,0,0);
    
    FOR(i,n+1,n*2) list[i]=list[i-n], list2[i]=list2[i-n];
    
    int pos=1;
    ll sumL,sumR,valL,valR,cntL,cntR;
    sumR=0; valR=0; cntR=0;
    FORD(i,n,1){
        sumR+=list2[i];
        valR+=sumR*cnt[list[i]]+sum[list[i]]+sumR;
        cntR+=cnt[list[i]]+1;
    }
    sumL=0; valL=0; cntL=0;
    FOR(i,1,n) f[i]=0;
    FOR(i,1,n){
        u=list[i];
        while(sumL+list2[pos]<=sumR-list2[pos]){
            v=list[pos];
            sumL+=list2[pos];
            valL+=sumL*(cnt[v]+1)+sum[v];
            cntL+=cnt[v]+1;
            valR-=sumR*(cnt[v]+1)+sum[v];
            sumR-=list2[pos];            
            cntR-=cnt[v]+1;
            
            pos++;
        }
        v=list[pos];
        
        f[u]=valL + valR - (sumR*cnt[v]+sum[v]+sumR);
        v=list[i+1];
        valL-=list2[i]*cntL + sum[v];        
        cntL-=cnt[u]+1;
        sumL-=list2[i];
        
        cntR+=cnt[u]+1;
        valR+=list2[i]*cntR + sum[u];
        sumR+=list2[i];
    }
    FOR(i,1,n) cout<<f[i]<<' '; cout<<endl;
    FOR(i,1,n) printf("%I64d ",f[i]+sum[i]);
        
    getch();
    return 0;
}
        
