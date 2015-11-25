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

const int maxn=1007;

int n,m,cnt,num[maxn],low[maxn],com[maxn],q;
bool arr[maxn][maxn],free1[maxn];
vector<int> a[maxn];
stack<int> mystack;

void dfs(int u){
    num[u]=++cnt; low[u]=num[u];
    mystack.push(u);
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(!free1[v]) continue;
        if(num[v]==0){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else low[u]=min(low[u],num[v]);
    }
    if(num[u]==low[u]){
        q++;
        do{
            v=mystack.top(); mystack.pop();
            com[v]=q;
            free1[v]=0;
        }while(v!=u);
    }
}

void bfs(int s){
    queue<int> myqueue;
    reset(free1,1);
    myqueue.push(s);
    free1[s]=0;
    int u,v;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(a[u])){
            v=a[u][i];
            if(free1[v]){
                free1[v]=0;
                myqueue.push(v);
            }
        }
    }
    FOR(v,1,n) arr[s][v]=!free1[v];
    arr[s][s]=0;
}

//Matching
int mX[maxn],mY[maxn],dis[maxn];
queue<int> myqueue;

bool findpath(){
    FOR(u,1,n) if(mX[u]==0){
        dis[u]=0;
        myqueue.push(u);
    }else dis[u]=oo;
    dis[0]=oo;
    int u,v;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(a[u])){
            v=a[u][i];
            if(dis[mY[v]]==oo){
                dis[mY[v]]=dis[u]+1;
                if(mY[v]!=0) myqueue.push(mY[v]);
            }
        }
    }
    return dis[0]!=oo;
}

bool match(int u){
    if(u==0) return 1;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(dis[mY[v]]==dis[u]+1 && match(mY[v])){
            mX[u]=v;
            mY[v]=u;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int test;
    scanf("%d",&test);
    int u,v;
    FOR(tt,1,test){
        scanf("%d%d",&n,&m);
        FOR(i,1,n) a[i].clear();
        FOR(i,1,m){
            scanf("%d%d",&u,&v);
            a[u].pb(v);
        }
        reset(num,0); reset(free1,1);
        mystack=stack<int>();
        q=0; cnt=0;
        FOR(i,1,n) if(num[i]==0) dfs(i);
        FOR(i,1,q) FOR(j,1,q) arr[i][j]=0;
        FOR(u,1,n) REP(i,sz(a[u])){
            int v=a[u][i];
            if(com[u]!=com[v]) arr[com[u]][com[v]]=1;
        }
        
        //--------------
        n=q;
        FOR(i,1,n) a[i].clear();
        FOR(u,1,n) FOR(v,1,n) if(arr[u][v]==1) a[u].pb(v);
        reset(arr,0);
        FOR(u,1,n) bfs(u); 
        FOR(i,1,n) a[i].clear();
        FOR(u,1,n) FOR(v,1,n) if(arr[u][v]) a[u].pb(v);    
        
        int res=0;
        FOR(u,1,n) mX[u]=mY[u]=0;
        while(findpath()) FOR(u,1,n) if(mX[u]==0 && match(u)) res++;
        printf("Case %d: %d\n",tt,n-res);
    }
    
    //getch();
    return 0;
}
        
