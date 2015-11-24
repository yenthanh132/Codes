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

int n,m,p,q,com[maxn],fu[maxn],cnt;
int val[maxn];
int x[maxn],y[maxn],w[maxn];
vector<int> e[maxn];
bool free1[maxn];
set<pii> mys;

void dfs(int u){
    free1[u]=0;
    com[u]=cnt;
    fu[cnt]=u;
    int v;
    REP(i,sz(e[u])){
        v=e[u][i];
        if(free1[v]) dfs(v);
    }
}

vector<pii> res;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&p,&q);
    REP(i,m){
        scanf("%d%d%d",&x[i],&y[i],&w[i]);
        e[x[i]].pb(y[i]);
        e[y[i]].pb(x[i]);
    }
    reset(free1,1);
    cnt=0;
    FOR(u,1,n) if(free1[u]){
        ++cnt;
        dfs(u);
    }
    REP(i,m) val[com[x[i]]]=min(val[com[x[i]]]+w[i],1000000000);

    if(cnt < q){
        puts("NO");
        return 0;
    }

    FOR(i,1,cnt) mys.insert(pii(val[i],i));
    while(sz(mys)>q && p>0){
        pii u=*mys.begin(); mys.erase(mys.begin());
        pii v=*mys.begin(); mys.erase(mys.begin());
        ll val=u.fi+v.fi+min(u.fi+v.fi+1,1000000000);
        int val2;
        if(val>1000000000) val2=1000000000; else val2=val;
        mys.insert(pii(val2,u.se));
        res.pb(pii(fu[u.se],fu[v.se]));
        --p;
    }

    if(sz(mys)!=q || (p>0 && m==0 && sz(res)==0)){
        puts("NO");
        return 0;
    }
    puts("YES");
    REP(i,sz(res)) printf("%d %d\n",res[i].fi,res[i].se);
    REP(i,p){
        int u,v;
        if(m>0) u=x[0],v=y[0];
        else u=res[0].fi, v=res[0].se;
        printf("%d %d\n",u,v);
    }

    return 0;
}

