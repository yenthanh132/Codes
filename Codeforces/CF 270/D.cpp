#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2007;

int lab[maxn],n,d[maxn][maxn],f[maxn][maxn],m;
vector<pii> e[maxn];

struct edge{
    int x,y,w;
}arr[maxn*maxn];

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void dsu(int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

bool cmp(const edge &e1, const edge &e2){
    return e1.w<e2.w;
}

void dfs(int u, int p, int r){
    int v;
    for(int i=0; i<sz(e[u]); ++i){
        v=e[u][i].first;
        if(v==p) continue;
        f[r][v]=f[r][u]+e[u][i].second;
        dfs(v,u,r);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) scanf("%d",&d[i][j]);
    m=0;
    for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j){
        ++m;
        arr[m].x=i; arr[m].y=j;
        arr[m].w=d[i][j];
    }
    sort(arr+1,arr+m+1,cmp);
    for(int u=1; u<=n; ++u) lab[u]=-1;
    int cnt=0;
    for(int i=1; i<=m; ++i){
        int r1=getroot(arr[i].x), r2=getroot(arr[i].y);
        if(r1!=r2 && arr[i].w>0){
            dsu(r1,r2);
            ++cnt;
            e[arr[i].x].pb(pii(arr[i].y,arr[i].w));
            e[arr[i].y].pb(pii(arr[i].x,arr[i].w));
        }
    }
    if(cnt!=n-1) {
        puts("NO");
        return 0;
    }
    for(int u=1; u<=n; ++u){
        f[u][u]=0;
        dfs(u,-1,u);
    }
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(f[i][j]!=d[i][j]){
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}

