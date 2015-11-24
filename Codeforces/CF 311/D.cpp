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

bool colorOk;
int color[maxn];
vector<int> e[maxn];
int x[maxn],y[maxn],n,m;
int cnt0, cnt1;

void dfs(int u, int c){
    if(!colorOk) return;
    if(c==0) ++cnt0; else ++cnt1;
    color[u] = c;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(color[v]==-1) dfs(v,1-c);
        else if(color[v]==color[u]){
            colorOk = 0;
            return;
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);

    for(int i=1; i<=m; ++i){
        scanf("%d%d",&x[i],&y[i]);
        e[x[i]].pb(y[i]);
        e[y[i]].pb(x[i]);
    }

    ll res1 = 0;

    reset(color,-1);
    colorOk = 1;
    for(int i=1; i<=n; ++i) if(color[i]==-1){
        cnt0 = cnt1 = 0;
        dfs(i,1);
        res1 += 1ll*cnt0*(cnt0-1)/2 + 1ll*cnt1*(cnt1-1)/2;
    }

    if(!colorOk){ //res 0
        puts("0 1");
        return 0;
    }

    if(m==0){ //res 3
        cout<<3<<' '<<1ll*n*(n-1)*(n-2)/6<<endl;
        return 0;
    }

    if(res1 > 0){ //res 1
        cout<<1<<' '<<res1<<endl;
        return 0;
    }

    //res 2
    ll res2 = 1ll*(n-2)*m;
    cout<<2<<' '<<res2<<endl;


}

