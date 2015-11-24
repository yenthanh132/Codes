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

vector<int> e[maxn],e2[maxn];
int n,m;
bool mark[maxn],free1[maxn],inDFS[maxn],foundCir;
vector<int> lst;

void dfs(int u){
    lst.pb(u);
    mark[u]=1;
    for(int i=0; i<sz(e2[u]); ++i){
        int v=e2[u][i];
        if(!mark[v]) dfs(v);
    }
}

void dfs2(int u){
    free1[u]=0;
    inDFS[u]=1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(free1[v]) dfs2(v);
        else if(inDFS[v])
            foundCir=1;
    }
    inDFS[u]=0;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=0; i<m; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e2[u].pb(v);
        e2[v].pb(u);
    }
    reset(mark,0); reset(free1,1); reset(inDFS,0);
    int res=0;
    for(int u=1; u<=n; ++u) if(!mark[u]){
        lst.clear();
        dfs(u);
        foundCir=0;
        for(int i=0; i<sz(lst); ++i){
            int x=lst[i];
            if(free1[x]) dfs2(x);
        }
        res+=sz(lst);
        if(!foundCir) res--;
    }

    cout<<res<<endl;

}

