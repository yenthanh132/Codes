#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=57;

int g[maxn][maxn][maxn];

int f(int x, int y, int z){
    if(x==y && y==z && x==0) return 0;
    if(g[x][y][z]!=-1) return g[x][y][z];
    set<int> mys;
    for(int i=1; i<=x; ++i) mys.insert(f(x-i,y,z));
    for(int i=1; i<=y; ++i) mys.insert(f(x,y-i,z));
    for(int i=1; i<=z; ++i) mys.insert(f(x,y,z-i));
    int &res = g[x][y][z];
    for(res = 0; mys.count(res); ++res);
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    reset(g,-1);
    int T,n,x,y,z;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int r=0;
        for(int i=0; i<n; ++i){
            scanf("%d%d%d",&x,&y,&z);
            r ^= f(x,y,z);
        }
        if(r) puts("Stark"); else puts("Lannister");
    }
}

