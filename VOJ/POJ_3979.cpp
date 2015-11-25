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

const int maxn = 101;

vector<int> a[maxn];
queue<int> myqueue;
int m,n,T,mx[maxn],my[maxn],dis[maxn];

bool findpath(){
    myqueue=queue<int>();
    FOR(i,1,m) if(mx[i]==0) dis[i]=0, myqueue.push(i); else dis[i]=oo;
    dis[0]=oo;
    int u,v;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(a[u])){
            v=a[u][i];
            if(dis[my[v]]==oo){
                dis[my[v]]=dis[u]+1;
                if(my[v]!=0) myqueue.push(my[v]);
            }
        }
    }
    return (dis[0]!=oo);
}

bool dfs(int u){
    if(u==0) return 1;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(dis[my[v]]==dis[u]+1 && dfs(my[v])){
            mx[u]=v;
            my[v]=u;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}

//#include <conio.h>
int main(){
    int p,v,res;
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(index,T){
        scanf("%d%d",&n,&m);
        FOR(i,1,m){
            a[i].clear();
            scanf("%d",&p);          
            REP(j,p) scanf("%d",&v), a[i].pb(v);
        }
        reset(mx,0); reset(my,0);
        res=0;
        while(findpath())
            FOR(i,1,m) if(mx[i]==0 && dfs(i)) res++;
        printf("Case %d: %d\n",index+1,n+(m-res));
    }
    //getch();
    return 0;
}
