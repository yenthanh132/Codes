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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 500007;

vector<int> a[maxn],b[maxn];
int N,n,low[maxn],num[maxn],count1,m,com[maxn], mX[maxn],mY[maxn],dis[maxn];
stack<int> mystack;
bool free1[maxn],isnode[maxn];
map<pii,bool> medge;

void dfs(int u){
    num[u]=low[u]=++count1; 
    int v;
    mystack.push(u);
    REP(i,sz(a[u])){
        v=a[u][i];
        if(!free1[v]) continue;
        if(num[v]==0){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else low[u]=min(low[u],num[v]);
    }
    if(num[u]==low[u]){
        m++;
        isnode[m]=0;
        do{
            v=mystack.top();
            mystack.pop();
            com[v]=m;
            free1[v]=false;
            if(v<=N) isnode[m]=1;
        }while(v!=u);
    }
}

void dfs2(int u){
    int v,z;
    REP(i,sz(b[u])){
        v=b[u][i];
        if(medge[pii(u,v)]==1) continue;
        medge[pii(u,v)]=1;
        dfs2(v);
        REP(j,sz(b[v])){
           z=b[v][j];
           if(medge[pii(u,z)]==0) b[u].pb(z), medge[pii(u,z)]=1;
        }
    }
}        

queue<int> myqueue;   

bool findpath(){
    FOR(i,1,m) 
        if(mX[i]==0){
            dis[i]=0;
            myqueue.push(i);
        }else dis[i]=oo;
    dis[0]=oo;
    int u,v;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(b[u])){
            v=b[u][i];
            if(dis[mY[v]]==oo){
                dis[mY[v]]=dis[u]+1;
                if(mY[v]!=0) myqueue.push(mY[v]);
            }
        }
    }
    return(dis[0]!=oo);
}

bool dfs3(int u){
    if(u==0) return true;
    int v;
    REP(i,sz(b[u])){
        v=b[u][i];
        if(dis[mY[v]]==dis[u]+1 && dfs3(mY[v])){
            mX[u]=v;
            mY[v]=u;
            return true;
        }
    }
    dis[u]=oo;
    return false;
}

int domatching(){
    int res=0;
    reset(mX,0); reset(mY,0);
    while(findpath()) FOR(i,1,m) if(mX[i]==0 && dfs3(i)) res++;
    return res;
}
          
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&N);
    int k,v,nn=N;
    FOR(i,1,N-1){
        scanf("%d",&k);
        REP(j,k){
            scanf("%d",&v);
            nn++;
            a[i].pb(nn);
            a[nn].pb(v);
        }
    }
    n=nn;
    // Build DAG
    reset(num,0); reset(free1,true);
    count1=m=0;
    dfs(1);
    int x,y;
    FOR(i,1,n)
        REP(j,sz(a[i])){
            x=com[i]; y=com[a[i][j]];
            if(x!=y && medge[pii(x,y)]==0){
                medge[pii(x,y)]=1;
                b[x].pb(y);
            }
        }
    medge.clear();
    dfs2(com[1]);
    printf("%d",m-domatching());
    //getch();
    return 0;
}
