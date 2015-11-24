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
const int maxk=17;

bool added[maxn];
int p[maxn][maxk],T,n,q,root;
vector<int> a[maxn];

void dfs(int u, int parent){
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==parent) continue;
        p[v][0]=u;
        dfs(v,u);
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d",&n);
        FOR(i,1,100000) a[i].clear();
        reset(added,0);
        reset(p,0);
        int x,y,t;
        REP(ttt,n){
            scanf("%d%d",&x,&y);
            added[x]=1;
            if(y==0) root=x;
            else{
                a[x].pb(y);
                a[y].pb(x);
                added[y]=1;
            }
        }
        dfs(root,0);
        FOR(k,1,maxk-1) FOR(u,1,100000) if(added[u]) p[u][k]=p[p[u][k-1]][k-1];
        scanf("%d",&q);
        REP(ttt,q){
            scanf("%d",&t);
            if(t==0){
                scanf("%d%d",&x,&y);
                added[y]=1;
                p[y][0]=x;
                FOR(k,1,maxk-1) p[y][k]=p[p[y][k-1]][k-1];   
            }else if(t==1){
                scanf("%d",&x);
                added[x]=0;
            }else{
                scanf("%d%d",&x,&y);
                if(added[x]==0) puts("0");
                else{
                    REP(i,maxk) if((y>>i)&1) x=p[x][i];
                    printf("%d\n",x);
                }   
            }
        }
    }
    //getch();
    return 0;
}
    
