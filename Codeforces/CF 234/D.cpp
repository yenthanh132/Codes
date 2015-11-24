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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=111111;
const int maxk=555;

int arr[maxn],c[maxn],n,m,k,f[maxk][maxk],com[maxn],cnt;
vector<int> a[maxn];

void dfs(int u){
    com[u]=cnt;
    int v;   
    REP(i,sz(a[u])){
        v=a[u][i];
        if(com[v]==-1) dfs(v);
    }
}

int main(){

    
    scanf("%d%d%d",&n,&m,&k);
    int p=1;
    FOR(i,1,k){
        scanf("%d",&c[i]);
        REP(j,c[i]) arr[p++]=i;
    }
    
    int u,v,w;
    FOR(i,1,k) FOR(j,1,k) if(i!=j) f[i][j]=oo; else f[i][j]=0;
    REP(i,m){
        scanf("%d%d%d",&u,&v,&w);
        if(w==0) a[u].pb(v), a[v].pb(u);   
        int x=arr[u], y=arr[v];
        f[x][y]=min(f[x][y],w);
        f[y][x]=min(f[y][x],w);
    }   
    
    reset(com,-1); cnt=0;
    FOR(u,1,n) if(com[u]==-1){
        ++cnt;   
        dfs(u);
    }
    
    bool ok=1;
    p=0;
    FOR(i,1,k){
        FOR(x,p+1,p+c[i]-1) if(com[x]!=com[x+1]) ok=0;
        p+=c[i];
    }
    
    if(!ok) puts("No");
    else{
        puts("Yes");
        FOR(z,1,k) FOR(i,1,k) FOR(j,1,k) f[i][j]=min(f[i][j],f[i][z]+f[z][j]);
        FOR(i,1,k){
            FOR(j,1,k){
                w=f[i][j];
                if(w==oo) w=-1;
                printf("%d ",w);   
            }
            puts("");
        }   
    }
    return 0;
}
