#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;

int a[maxn],n,cnt,k,deg[maxn];
map<int,int> mid;
vector<int> e[maxn];
set<pii> mys;

int getid(int u){
    int res = mid[u];
    if(res) return res;
    mid[u]=++cnt;
    a[cnt] = u;
    return cnt;
}

void pushE(int u, int v){
    int a=getid(u), b=getid(v);
    e[a].pb(b);
    ++deg[b];
}

void solve(){
    for(int u=1; u<=cnt; ++u) if(deg[u]==0) mys.insert(pii(a[u],u));
    while(!mys.empty()){
        int u=mys.begin()->second; mys.erase(mys.begin());
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i];
            --deg[v];
            if(deg[v]==0) mys.insert(pii(a[v],v));
        }
        printf("%d ",a[u]);
    }
    puts("");
}

int main(){
//    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n;
    cnt=0; mid.clear(); reset(deg,0);
    for(int i=0; i<n; ++i){
        cin>>k;
        int u=-1,v;
        for(int j=0; j<k; ++j){
            cin>>v;
            if(u!=-1) pushE(u,v);
            u=v;
        }
    }
    solve();
}

