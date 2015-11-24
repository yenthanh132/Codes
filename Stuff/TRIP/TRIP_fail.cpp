#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii, int> iii;
typedef long long ll;

const int maxn=100007;

int n,m;
pii d[maxn];
vector<pii> e[maxn];
bool free1[maxn];
set<iii> mys;

pii get(pii x, int v){
    if(v > x.second){
        x.first = x.second;
        x.second = v;
    }else if(v > x.first)
        x.first = v;
    return x;
}

int main(){
    //freopen("5.in","r",stdin);
//    freopen("0.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x,y,w;
    for(int i=0; i<m; ++i){
        scanf("%d%d%d",&x,&y,&w);
        e[x].pb(pii(y,w));
        e[y].pb(pii(x,w));
    }

    for(int i=1; i<=n; ++i) d[i]=pii(oo,oo);
    d[1]=pii(0,0);
    reset(free1,1);
    mys.insert(iii(d[1],1));
    while(!mys.empty()){
        int u=mys.begin()->second; mys.erase(mys.begin());
        free1[u]=0;
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i].first, w=e[u][i].second;
            pii newD = get(d[u],w);
            if(free1[v] && d[v] > newD){
                if(d[v]!=pii(oo,oo)) mys.erase(iii(d[v],v));
                d[v]=newD;
                mys.insert(iii(d[v],v));
            }
        }
    }
    if(d[n].first==oo) puts("-1");
    else printf("%d\n",d[n].first);
}
