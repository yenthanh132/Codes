#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

vector<int> e[maxn];
int n,m,cat[maxn],res;

void dfs(int u, int p, int catCount){
    if(cat[u]){
        catCount++;
        if(catCount>m) return;
    }else{
        catCount = 0;
    }

    bool isLeaf=1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        dfs(v,u, catCount);
        isLeaf=0;
    }
    if(isLeaf) ++res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) scanf("%d",&cat[i]);
    for(int i=0,u,v; i<n-1; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(v); e[v].pb(u);
    }
    res=0;
    dfs(1,-1,0);
    printf("%d\n",res);
}

