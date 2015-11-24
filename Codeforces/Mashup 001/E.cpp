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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=300007;

int parent[maxn], belong[maxn], idx[maxn], lsize[maxn], vsize[maxn], d[maxn], n, m;
vector<int> e[maxn];
vector<ll> bit[maxn], bit2[maxn];

void dfs(int u){
    vsize[u]=1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        d[v]=d[u]+1;
        dfs(v);
        vsize[u]+=vsize[v];
    }
}

void dfs2(int u){
    if(belong[u]==-1){
        belong[u] = ++m;
        idx[u] = 1;
        lsize[m] = 1;
    }
    int vmax=-1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(vmax==-1 || vsize[vmax] < vsize[v]) vmax=v;
    }

    if(vmax==-1) return;

    parent[vmax]=parent[u];
    idx[vmax] = idx[u]+1;
    belong[vmax]=belong[u];
    ++lsize[belong[u]];
    dfs2(vmax);

    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==vmax) continue;
        parent[v]=u;
        dfs2(v);
    }
}

void update(vector<ll> &bit, int n, int p, int v){
    for(;p<=n; p+=p&(-p)) bit[p] = (bit[p]+v)%oo;
}

ll get(vector<ll> &bit, int n, int p){
    ll res=0;
    for(;p; p-=p&(-p)) res=(res+bit[p])%oo;
    return res;
}

void query1(int v, int x, int k){
    int com = belong[v];
    int p = idx[v];
    update(bit[com],lsize[com],p,(1ll*k*d[v] + x)%oo);
    update(bit2[com],lsize[com],p,-k);
}

ll query2(int v){
    ll res1 = 0, res2 = 0;
    int u=v;
    while(v!=0){
        int p=idx[v];
        int com=belong[v];
        res1 = (res1 + get(bit[com], lsize[com], p))%oo;
        res2 = (res2 + get(bit2[com], lsize[com], p))%oo;
        v=parent[v];
    }
    ll ans = (d[u]*res2+res1)%oo;
    return (ans+oo)%oo;
}



int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int v=2; v<=n; ++v){
        int u;
        scanf("%d",&u);
        e[u].pb(v);
    }
    d[1]=1; parent[1]=0; idx[1]=1; lsize[1]=1;
    dfs(1);
    reset(belong,-1);
    m=1;
    belong[1]=1;
    dfs2(1);
    for(int i=1; i<=m; ++i){
        bit[i].resize(lsize[i]+5,0);
        bit2[i].resize(lsize[i]+5,0);
    }

    int q,v,x,k,tmp;
    scanf("%d",&q);
    for(int i=0; i<q; ++i){
        scanf("%d",&tmp);
        if(tmp==1) {
            scanf("%d%d%d",&v,&x,&k);
            query1(v,x,k);
        }else{
            scanf("%d",&v);
            printf("%I64d\n",query2(v));
        }
    }

    return 0;
}
