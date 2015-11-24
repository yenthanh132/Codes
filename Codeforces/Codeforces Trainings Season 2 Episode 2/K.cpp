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

const int maxn=207;

int a[maxn][maxn],n;
vector<int> e[maxn];
int deg[maxn],myq[maxn],first,last,res[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) scanf("%d",&a[i][j]);
    reset(deg,0);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(i!=j && a[i][j]==i) e[i].pb(j), deg[j]++;
    first=1; last=0;
    for(int u=1; u<=n; ++u)
        if(deg[u]==0) myq[++last]=u;

    reset(res,0);
    while(first<=last){
        int u=myq[first++];
        for(int i=0; i<sz(e[u]); ++i){
            int v=e[u][i];
            --deg[v];
            if(deg[v]==0){
                myq[++last]=v;
                res[v]=u;
            }
        }
    }
    for(int u=1; u<=n; ++u) printf("%d ",res[u]);
    return 0;
}
