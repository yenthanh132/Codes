#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=500007;

vector<pii> e[maxn];
int n,k;
ll len[maxn],maxd[maxn],res1[maxn],res2[maxn];
bool mark[maxn];

void dfs(int u, int p){
    len[u]=0;
    maxd[u]=0;
    int v,w;
    for(int i=0; i<sz(e[u]); ++i){
        v=e[u][i].first; w=e[u][i].second;
        if(v==p) continue;
        dfs(v,u);
        if(mark[v] || len[v]>0) len[u]+=len[v]+w;
        if(mark[v] || maxd[v]>0) maxd[u]=max(maxd[u],maxd[v]+w);
    }
}

void update(ll &v1, ll &v2, ll newv){
    if(newv>v1){
        v2=v1;
        v1=newv;
    }else if(newv>v2){
        v2=newv;
    }
}

void dfs2(int u, int p, ll sumlen, ll maxdis){
    res1[u]=sumlen+len[u];
    res2[u]=max(maxdis, maxd[u]);
    ll v1max, v2max,_sumlen,_maxdis,vdis,vlen;
    int v,w;
    v1max=v2max=0;
    for(int i=0; i<sz(e[u]); ++i){
        v=e[u][i].first; w=e[u][i].second;
        if(v==p) continue;
        vdis=0;
        if(mark[v] || maxd[v]>0 ) vdis = maxd[v]+w;
        update(v1max,v2max,vdis);
    }

    for(int i=0; i<sz(e[u]); ++i){
        v=e[u][i].first; w=e[u][i].second;
        if(v==p) continue;
        _sumlen = sumlen + len[u];
        vlen=0;
        if(mark[v] || len[v]) vlen=len[v]+w;
        _sumlen -= vlen;
        if(mark[u] || _sumlen > 0) _sumlen += w;

        _maxdis = maxdis;
        vdis = 0;
        if(mark[v] || maxd[v]>0) vdis = maxd[v]+w;
        if(vdis==v1max) _maxdis = max(_maxdis, v2max);
        else _maxdis = max(_maxdis, v1max);
        if(mark[u] || _maxdis > 0) _maxdis += w;

        dfs2(v,u,_sumlen,_maxdis);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    reset(mark,0);
    scanf("%d%d",&n,&k);
    int x,y,w;
    for(int i=0; i<n-1; ++i){
        scanf("%d%d%d",&x,&y,&w);
        e[x].pb(pii(y,w));
        e[y].pb(pii(x,w));
    }
    for(int i=0; i<k; ++i){
        scanf("%d",&x);
        mark[x]=1;
    }
    reset(res1,0); reset(res2,0);
    dfs(1,-1);
    dfs2(1,-1,0,0);

//    for(int i=1; i<=n; ++i) cout<<res1[i]<<' '<<res2[i]<<endl;
    for(int i=1; i<=n; ++i) printf("%lld\n",res1[i]*2-res2[i]);
    return 0;
}

