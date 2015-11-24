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

int parent[17][maxn],n,m,q,height[maxn];
vector<int> minId[17][maxn];
vector<int> e[maxn];

void reduce(vector<int> &top10){
    if(sz(top10)>10) top10.resize(10);
    sort(top10.begin(),top10.end());
}

void join(vector<int> s1, vector<int> s2, vector<int> &sf){
    vector<int>::iterator i1 = s1.begin();
    vector<int>::iterator i2 = s2.begin();
    sf.clear();
    for(int k=0; k<10; ++k){
        if(i1 == s1.end() && i2 == s2.end()) break;
        if(i2 == s2.end() || (i1 != s1.end() && *i1 < *i2)){
            sf.pb(*i1);
            ++i1;
        }else{
            sf.pb(*i2);
            ++i2;
        }
    }
}

void dfs(int u, int p){
    for(int i=1; (1<<i)<=height[u]; ++i){
        parent[i][u] = parent[i-1][parent[i-1][u]];
        join(minId[i-1][u], minId[i-1][parent[i-1][u]], minId[i][u]);
    }
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(v==p) continue;
        height[v]=height[u]+1;
        parent[0][v]=u;
        dfs(v,u);
    }
}

vector<int> getResult(int u, int v){
    vector<int> mys;
    if(height[u] > height[v]) swap(u,v);
    for(int i=0; i<17; ++i) if( (height[v] - height[u])>>i&1 ){
        join(minId[i][v], mys, mys);
        v = parent[i][v];
    }
    if(v==u){
        join(minId[0][u], mys, mys);
        return mys;
    }
    for(int i=16; i>=0; --i) if(parent[i][u]!=parent[i][v]){
        join(minId[i][u], mys, mys);
        join(minId[i][v], mys, mys);
        u = parent[i][u];
        v = parent[i][v];
    }
    join(minId[1][u], mys, mys);
    join(minId[0][v], mys, mys);
    return mys;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1; i<n; ++i){
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }

    for(int i=1; i<=m; ++i){
        int u;
        scanf("%d",&u);
        minId[0][u].pb(i);
        reduce(minId[0][u]);
    }

    height[1]=1;
    dfs(1,-1);

    for(int i=0; i<q; ++i){
        int u,v,a;
        scanf("%d%d%d",&u,&v,&a);

        vector<int> mys = getResult(u,v);
        printf("%d", min(sz(mys),a));
        for(vector<int>::iterator it = mys.begin(); it != mys.end(); ++it){
            printf(" %d",*it);
            --a;
            if(a==0) break;
        }
        puts("");
    }
}

