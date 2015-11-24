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
int a[2][maxn][maxn];
int d[2][maxn],n,s,f;
bool free1[2][maxn];

void dijkstra(int id, int r, bool needSwap){
    for(int u=1; u<=n; ++u) d[id][u]=oo, free1[id][u]=1;
    d[id][r]=0;
    while(1){
        int u=-1,minv=oo;
        for(int i=1; i<=n; ++i) if(free1[id][i] && minv>d[id][i]){
            u=i;
            minv=d[id][i];
        }
        if(u==-1) break;
        free1[id][u]=0;
        for(int v=1; v<=n; ++v)
            if(free1[id][v]){
                int cost=a[id][u][v];
                if(needSwap) cost=a[id][v][u];
                d[id][v]=min(d[id][v], d[id][u]+cost);
            }
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int id=0; id<2; ++id) for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) scanf("%d",&a[id][i][j]);
    scanf("%d%d",&s,&f);

    dijkstra(0,s,0);
    dijkstra(1,f,1);
    int res=oo;
    for(int u=1; u<=n; ++u) if(u!=s && u!=f) res=min(res,d[0][u]+d[1][u]);

    dijkstra(1,s,0);
    dijkstra(0,f,1);
    for(int u=1; u<=n; ++u) if(u!=s && u!=f) res=min(res,d[0][u]+d[1][u]);

    cout<<res<<endl;
}

