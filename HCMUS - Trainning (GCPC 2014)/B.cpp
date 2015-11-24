#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=50007;

int n;
vector<int> e[maxn],e2[maxn];
bool inDFS[maxn],visited[maxn], visited2[maxn];
bool circle;


void dfs(int u){
    inDFS[u]=1;
    visited[u]=1;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(!visited[v]) dfs(v);
        else if(inDFS[v]){
            circle=1;
        }
    }
    inDFS[u]=0;
}

void dfs2(int u){
    visited2[u]=1;
    for(int i=0; i<sz(e2[u]); ++i){
        int v=e2[u][i];
        if(!visited2[v]) dfs2(v);
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    int m,v;
    for(int u=1; u<n; ++u){
        scanf("%d",&m);
        for(int i=0; i<m; ++i){
            scanf("%d",&v);
            e[u].pb(v);
            e2[v].pb(u);
        }
    }

    circle=0;
    reset(visited,0);
    reset(inDFS,0);
    dfs(1);

    string r1,r2;
    if(circle){
        r2="UNLIMITED";
    }else{
        r2="LIMITED";
    }

    if(!visited[n]){
        r1="PRISON";
    }else{
        dfs2(n);
        r1="PARDON";
        for(int u=1; u<=n; ++u)
            if(visited[u] && !visited2[u]){
                r1="PRISON";
                break;
            }
    }
    cout<<r1<<' '<<r2<<endl;

}


