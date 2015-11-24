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
bool free1[maxn][2];
vector<pii> e[maxn];

void dfs(int u, int t, int &val){
    free1[u][t]=0;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i].first, w=e[u][i].second;
        int t2=t;
        if(w>val) ++t2;
        if(t2<2 && free1[v][t2]) dfs(v,t2,val);
    }

}

bool check(int val){
    reset(free1,1);
    dfs(1,0,val);
    return !free1[n][0] || !free1[n][1];
}

void gen( int id ){
    stringstream ss;
    ss<<id;
    string spath=ss.str();
    freopen((spath+".in").c_str(),"r",stdin);
    freopen((spath+".out").c_str(),"w",stdout);
    scanf("%d%d",&n,&m);
    int x,y,w;
    for(int i=1; i<=n; ++i) e[i].clear();
    for(int i=0; i<m; ++i){
        scanf("%d%d%d",&x,&y,&w);
        e[x].pb(pii(y,w));
        e[y].pb(pii(x,w));
    }

    int l=0, r=oo, mid, res=oo;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    if(res==oo) puts("-1");
    else printf("%d\n",res);
}

int main(){
    for(int i=0; i<30; ++i) gen(i);
}


