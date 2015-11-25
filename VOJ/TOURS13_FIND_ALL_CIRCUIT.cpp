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

int ans[maxn],n,m,num[maxn],low[maxn],cnt,com[maxn],cntcom,mys[maxn],last,res[maxn],sum[maxn];
bool free1[maxn],lock[maxn];
vector<int> list[maxn];
vector<pii> a[maxn];
set<int> b[maxn];

void dfs(int u){
    int v;
    num[u]=low[u]=++cnt;
    mys[++last]=u;
    REP(i,sz(a[u])){
        v=a[u][i].fi;
        if(!free1[v]) continue;
        if(num[v]==0){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else low[u]=min(low[u],num[v]);
    }
    if(num[u]==low[u]){
        ++cntcom;
        list[cntcom].clear();
        do{
            v=mys[last--];
            free1[v]=0;
            com[v]=cntcom;
            list[cntcom].pb(v);
        }while(v!=u);
    }
}

void unlock(int u){
    lock[u]=0;
    int v;
    while(!b[u].empty()){
        v=*b[u].begin();
        b[u].erase(b[u].begin());
        unlock(v);
    }
}
int abc;
bool dfs2(int r, int u){
    int v;
    bool f=0;
    mys[++last]=u;
    
    lock[u]=1;
    REP(i,sz(a[u])){
        v=a[u][i].fi;
        if(v<r || com[v]!=com[r]) continue;
        if(v==r){
            FOR(j,1,last){
                res[mys[j]]=min(res[mys[j]],sum[u]+a[u][i].se);
            }
            f=1;
        }else if(!lock[v]){
            sum[v]=sum[u]+a[u][i].se;
            if(dfs2(r,v)) f=1;
        }
    }
    if(f) unlock(u);
    else 
        REP(i,sz(a[u])){
            v=a[u][i].fi;
            if(v<r || com[v]!=com[r]) continue;
            b[v].insert(u);
        }
    
    last--;
    return f;
}

#include <conio.h>
int main(){
    abc=0;
    freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,u,v,c;
    scanf("%d",&test);
    REP(index,test){
        scanf("%d%d",&n,&m);
        FOR(i,1,n) a[i].clear();
        REP(i,m){
            scanf("%d%d%d",&u,&v,&c);
            a[u].pb(pii(v,c));
        }
        reset(num,0);
        last=0;
        reset(free1,1); reset(com,0);
        cnt=cntcom=0;
        FOR(i,1,n) if(!num[i]) dfs(i);
        FOR(i,1,n) res[i]=oo;
        FOR(i,1,cntcom){
            sort(list[i].begin(),list[i].end());
            REP(j,sz(list[i])){
                last=0;
                sum[list[i][j]]=0;
                FOR(i,1,n) b[i].clear();
                reset(lock,0);
                dfs2(list[i][j],list[i][j]);
            }
        }
        
        FOR(i,1,n) if(res[i]==oo) puts("-1"); else printf("%d\n",res[i]);
        
    }
    //getch();
    return 0;
}
