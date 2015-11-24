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

const int maxn = 100007;

int p[maxn][17],d[maxn],BIT[maxn],n,m,c,first[maxn],last[maxn],res[maxn];
vector<int> a[maxn],list[maxn];
vector<pii> query[maxn];

void update(int i, int v){
    while(i<=c){
        BIT[i]+=v;
        i+=i&(-i);
    }
}

int get(int i){
    int v=0;
    while(i>0){
        v+=BIT[i];
        i-=i&(-i);
    }
    return v;
}
    
void dfs(int u){
    list[d[u]].pb(u);
    first[u]=++c;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        d[v]=d[u]+1;
        dfs(v);
    }
    last[u]=c;
}

void initLCA(){
    FOR(i,1,16)
        FOR(j,1,n)
            if(p[j][i-1]==0) p[j][i]=0;
            else p[j][i]=p[p[j][i-1]][i-1];
}
    
int jump(int u, int i){
    if(i==0) return u;
    REP(j,17) if((i>>j)&1){
        u=p[u][j];
        if(u==0) return 0;
    }
    return u;
}

void solve(){
    int u,v,id;
    FOR(i,1,n) if(!list[i].empty()){
        REP(j,sz(list[i])) update(first[list[i][j]],1);
        REP(j,sz(query[i])){
            u=query[i][j].fi; id=query[i][j].se;
            v=get(last[u])-get(first[u]-1);
            res[id]=v-1;
        }
        REP(j,sz(list[i])) update(first[list[i][j]],-1);
    }
}

#include <conio.h>
int main(){
    int u,v,r;
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&v);
        p[i][0]=v;
        if(v!=0) a[v].pb(i);
    }
    
    c=0;
    FOR(i,1,n) if(p[i][0]==0){
        d[i]=1;
        dfs(i);
    }
    initLCA();
    
    scanf("%d",&m);
    reset(res,0);
    FOR(i,1,m){
        scanf("%d%d",&u,&v);
        r=jump(u,v);
        if(r!=0) query[d[u]].pb(pii(r,i));
    }
      
    solve();
    FOR(i,1,m) printf("%d ",res[i]);
    //getch();
    return 0;
}
