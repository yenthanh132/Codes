#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10007;

vector<int> e[maxn];
vector<int> ds;
int f[maxn],d[maxn],myq[maxn];
set<int> mys;
int n,r,T;


void bfs(int start){
    int first,last,u,v;
    myq[first=last=1]=start;
    for(int i=0; i<sz(ds); ++i) d[ds[i]]=-1;
    d[start]=1;
    while(first<=last){
        u=myq[first++];
        for(int i=0; i<sz(e[u]); ++i){
            v=e[u][i];
            if(d[v]!=-1) continue;
            d[v]=d[u]+1;
            myq[++last]=v;
        }
    }
    for(int i=0; i<sz(ds); ++i) f[ds[i]]=max(f[ds[i]],d[ds[i]]);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&r);
        int u,k,v;
        ds.clear();
        for(int i=0; i<n; ++i){
            scanf("%d%d",&u,&k);
            ds.pb(u);
            for(int j=0; j<k; ++j){
                scanf("%d",&v);
                e[u].pb(v);
            }
            f[u]=0;
        }
        mys.clear();
        for(int i=0; i<r; ++i){
            scanf("%d",&k);
            for(int j=0; j<k; ++j){
                scanf("%d",&v);
                mys.insert(v);
            }
        }

        for(set<int>::iterator it=mys.begin(); it!=mys.end(); ++it) bfs(*it);

        int minval=oo, minid=oo;
        for(int i=0; i<sz(ds); ++i){
            u=ds[i];
            if(f[u]<minval || (f[u]==minval && u<minid)){
                minval=f[u];
                minid=u;
            }
        }

        for(int i=0; i<sz(ds); ++i) e[ds[i]].clear();

        printf("%d %d\n",minval,minid);

    }
}

