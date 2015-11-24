#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

int mx[maxn],my[maxn],dis[maxn],myq[maxn];
int n,m;
vector<int> e[maxn];

bool findpath(){
    int first=1,last=0;
    for(int u=1; u<=n; ++u) if(mx[u]==0){
        myq[++last]=u;
        dis[u]=0;
    }else dis[u]=oo;
    dis[0]=oo;
    while(first<=last){
        int u=myq[first++];
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i];
            if(dis[my[v]]==oo){
                dis[my[v]] = dis[u] + 1;
                if(my[v]) myq[++last] = my[v];
            }
        }
    }
    return dis[0]!=oo;
}

bool dfs(int u){
    if(u==0) return 1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(dis[my[v]]==dis[u]+1 && dfs(my[v])){
            mx[u]=v;
            my[v]=u;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}


int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        reset(mx,0); reset(my,0);
        for(int u=1; u<=n; ++u) e[u].clear();
        for(int i=0; i<m; ++i){
            int u,v;
            scanf("%d%d",&u,&v);
            if(u!=v) e[u].pb(v);
        }
        int res=0;
        while(findpath()){
            for(int u=1; u<=n; ++u)
                if(mx[u]==0 && dfs(u)) ++res;
        }
        res=n-res;
        printf("%d\n",res);
    }
}

