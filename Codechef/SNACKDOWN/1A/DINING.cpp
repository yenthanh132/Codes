#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn = 107;

int n,k,d,N,start,finish,start2,finish2;
vector<int> e[maxn];
queue<int> myq;
bool inqueue[maxn];
int cap[maxn][maxn], trace[maxn], f[maxn][maxn];
double cost[maxn][maxn], dis[maxn],arr[maxn][maxn];
int ans[maxn];

void resetGraph(){
    for(int i=1; i<=N; ++i) e[i].clear();
    reset(cap,0); reset(f,0);
    reset(ans,0);
}

void addEdge(int u, int v, double c, int f){
    e[u].pb(v); e[v].pb(u);
    cost[u][v] = c; cost[v][u] = c;
    cap[u][v] = f; cap[v][u] = 0;
}

int getd(int f){
    return (f>=0)?1:-1;
}

bool findpath(int st, int fi){
    myq = queue<int>();
    reset(inqueue,0);
    for(int i=1; i<=N; ++i) dis[i] = oo;
    dis[st]=0; myq.push(st); inqueue[st]=0;
    while(!myq.empty()){
        int u = myq.front(); myq.pop(); inqueue[u] = 0;
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i];
            if(f[u][v] < cap[u][v] && dis[v] > dis[u] + cost[u][v]*getd(f[u][v]) + 1e-9){
                dis[v] = dis[u] + cost[u][v]*getd(f[u][v]);
                trace[v] = u;
                if(!inqueue[v]){
                    inqueue[v] = 1;
                    myq.push(v);
                }
            }
        }
    }
    return dis[fi]+1e-9<oo;
}

void incflow(int st, int fi){
    int delta=oo;
    int u,v=fi;
    do{
        u=trace[v];
        delta=min(delta,cap[u][v]-f[u][v]);
        v=u;
    }while(v!=st);
    v=fi;
    do{
        u=trace[v];
        f[u][v]+=delta;
        f[v][u]-=delta;
        v=u;
    }while(v!=st);
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&d,&k);
        start = n+d+1;
        finish = n+d+2;
        start2 = n+d+3;
        finish2 = n+d+4;
        N = n+d+4;
        resetGraph();
        for(int i=1; i<=n; ++i) for(int j=1; j<=d; ++j) scanf("%lf",&arr[j][i]);

        for(int i=1; i<=d; ++i){
            addEdge(start, i, 0, k-1);
            for(int j=1; j<=n; ++j)
                addEdge(i,j+d,-log(arr[i][j]),1);

            addEdge(start2, i, 0, 1);
        }
        addEdge(start, finish2, 0, d);
        for(int j=1; j<=n; ++j){
            addEdge(j+d,finish2, 0, 1);
        }
        addEdge(start2, finish, 0, n);
        addEdge(finish, start, 0, oo);
        while(findpath(start2,finish2)) incflow(start2,finish2);

        double res = 1;
        for(int u=1; u<=d; ++u){
            for(int v=1; v<=n; ++v){
                if(f[u][v+d]==1){
                    ans[v]=u;
                    res *= arr[u][v];
                }
            }
        }

        printf("%0.9f\n",res);
        for(int i=1; i<=n; ++i) printf("%d ",ans[i]); puts("");
    }
}

