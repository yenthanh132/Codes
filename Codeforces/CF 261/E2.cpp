#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=300007;
struct edge{
    int x,y,w;
    bool operator<(const edge &a) const{
        return w<a.w;
    }
}e[maxn];
int n,m,f[maxn],g[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; ++i) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
    sort(e+1,e+m+1);
    reset(f,0);
    for(int i=1,j; i<=m; i=j+1){
        j=i;
        while(j+1<=m && e[j+1].w==e[i].w) ++j;
        for(int x=i; x<=j; ++x){
            int u=e[x].x, v=e[x].y;
            g[u]=f[u]; g[v]=f[v];
        }
        for(int x=i; x<=j; ++x){
            int u=e[x].x, v=e[x].y;
            g[v]=max(f[u]+1,g[v]);
        }
        for(int x=i; x<=j; ++x){
            int u=e[x].x, v=e[x].y;
            f[u]=g[u]; f[v]=g[v];
        }
    }
    int res = 0;
    for(int u=1; u<=n; ++u) res=max(res,f[u]);
    printf("%d\n",res);

    return 0;
}
