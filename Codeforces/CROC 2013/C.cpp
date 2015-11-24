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

int gcd(int a, int b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

vector<int> e[maxn], e2[maxn];
int num[maxn];
bool free1[maxn];
int n,m,res;

void dfs(int u, int d){
    if(!free1[u]){
        res=gcd(res,abs(d-num[u]));
        return;
    }
    num[u]=d;
    free1[u]=0;
    for(int i=0; i<sz(e[u]); ++i) dfs(e[u][i],d+1);
    for(int i=0; i<sz(e2[u]); ++i) dfs(e2[u][i],d-1);
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=0; i<m; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e2[v].pb(u);
    }

    res=0;
    reset(free1,1);
    for(int u=1; u<=n; ++u) if(free1[u]) dfs(u,1);
    if(res==0) res=n;
    cout<<res<<endl;
}
