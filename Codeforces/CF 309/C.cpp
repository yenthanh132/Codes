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

int n,m,cnt,num[maxn],cntgroup,color[maxn];
vector<pii> e1, e0;
vector<int> ed[maxn],ed0[maxn];
bool fillColorOk;

void dfs(int u){
    num[u]=cnt;
    for(int i=0; i<sz(ed[u]); ++i){
        int v=ed[u][i];
        if(!num[v]) dfs(v);
    }
}

void dfsColor(int u, int col){
    if(!fillColorOk) return;
    color[u]=col;
    for(int i=0; i<sz(ed0[u]); ++i){
        int v=ed0[u][i];
        if(!color[v]) dfsColor(v,3-col);
        else{
            if(color[v]==color[u]){
                fillColorOk = 0;
                return;
            }
        }
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0,u,v,c; i<m; ++i){
        scanf("%d%d%d",&u,&v,&c);
        if(c==1){
            ed[u].pb(v);
            ed[v].pb(u);
            e1.pb(pii(u,v));
        }else{
            e0.pb(pii(u,v));
        }
    }

    reset(num,0);
    cnt=0;
    for(int u=1; u<=n; ++u) if(!num[u]){
        ++cnt;
        dfs(u);
    }

    for(int i=0; i<sz(e0); ++i){
        int u=e0[i].first, v=e0[i].second;
        if(num[u]==num[v]){
            puts("0");
            return 0;
        }

        ed0[num[u]].pb(num[v]);
        ed0[num[v]].pb(num[u]);
    }

    cntgroup=0;
    reset(color,0);
    fillColorOk=1;
    for(int u=1; u<=cnt; ++u)
        if(!color[u]){
            ++cntgroup;
            dfsColor(u,1);
            if(!fillColorOk){
                puts("0");
                return 0;
            }
        }

    ll res=1;
    for(int i=0; i<cntgroup-1; ++i) res=res*2%oo;

    cout<<res<<endl;
}

