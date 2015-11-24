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

const int maxn=100007;

int n,type[maxn],prev[maxn],deg[maxn],d[maxn],trace[maxn],list[maxn],cnt;

void dfs(int u){
    int v=prev[u];
    if(v!=0 && type[v]==0 && deg[v]==1) dfs(v);
    list[++cnt]=u;
}    

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&type[i]);
    reset(deg,0);
    FOR(i,1,n){
        scanf("%d",&prev[i]);
        deg[prev[i]]++;
    }
    
    cnt=0;
    reset(d,0);
    FOR(u,1,n) if(type[u]==1){
        dfs(u);
        d[u]=1;
        trace[u]=0;
    }
    FORD(i,cnt,1){
        int u=list[i];
        int v=prev[u];
        if(v!=0 && deg[v]==1 && type[v]==0 && d[v]<d[u]+1){
            d[v]=d[u]+1;
            trace[v]=u;
        }
    }
    
    int res=0,t=-1;
    FOR(u,1,n) if(res<d[u]){
        res=d[u];
        t=u;
    }
    
    printf("%d\n",res);
    if(t!=-1){
        printf("%d",t);
        while(trace[t]){    
            t=trace[t];
            printf(" %d",t);
        }
    }
    //getch();
    return 0;
}

    
    
