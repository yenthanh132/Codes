#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=20007;

int n,m,low[maxn],num[maxn],com[maxn],cnt,mys[maxn],last, number;
bool free1[maxn];
vector<int> e[maxn];
vector<int> lst;

int neg(int u){
    if(u<=m) return u+m;
    return u-m;
}

void dfs(int u){
    num[u]=low[u]=++number;
    mys[++last]=u;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(!free1[v]) continue;
        if(num[v]==-1){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else
            low[u]=min(low[u],num[v]);
    }
    if(num[u]<=low[u]){
        ++cnt;
        int v;
        do{
            v=mys[last--];
            com[v]=cnt;
            free1[v]=0;
        }while(v!=u);
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u<0) u=-u+m;
        if(v<0) v=-v+m;
        e[neg(u)].pb(v);
        e[neg(v)].pb(u);
    }

    reset(free1,1);
    reset(num,-1);
    cnt=0; number=0; last=0;
    for(int u=1; u<=m*2; ++u)
        if(num[u]==-1) dfs(u);

    bool ok=1;
    for(int u=1; u<=m; ++u)
        if(com[u]==com[u+m]){
            ok=0;
            break;
        }else
            if(com[u]<com[u+m]) lst.pb(u);

    if(!ok){
        puts("NO");
        return 0;
    }

    puts("YES");
    printf("%d\n",sz(lst));
    for(int i=0; i<sz(lst); ++i) printf("%d ",lst[i]);

    return 0;

}
