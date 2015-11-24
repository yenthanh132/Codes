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

const int maxn = 707;
const int dx[4]={1,1,-1,-1};
const int dy[4]={-1,1,1,-1};

char arr[maxn][maxn];
int m,n,a[maxn][maxn],mX[maxn*maxn],mY[maxn*maxn],dis[maxn*maxn],cl,cr,cm;
bool free1[maxn][maxn];
vector<int> linknode[maxn*maxn];
queue<int> myqueue;

bool ok(int x, int y){
    if(!free1[x][y]) return(a[x][y]!=0);
    free1[x][y]=0;
    int xt,yt;
    bool left=1;
    if(arr[x][y]!='F'){
        a[x][y]=0;
        return 0;
    }
    REP(k,4){
        xt=x+dx[k]*2; yt=y+dy[k]*2;
        if(xt>=0 && xt<m && yt>=0 && yt<n){
            if(arr[xt][yt]=='G' && arr[x+dx[k]][y+dy[k]]!='P'){
                a[x][y]=0;
                return 0;
            }
            if(arr[xt][yt]=='F' && !free1[xt][yt] && a[xt][yt]>0) left=0;
        }
    }
    if(left) a[x][y]=++cl; else a[x][y]=-(++cr);
    return 1;
}

void init(int x, int y){
    if(!ok(x,y)) return;
    int xt,yt;
    REP(k,4){
        xt=x+dx[k]*2; yt=y+dy[k]*2;
        if(xt>=0 && xt<m && yt>=0 && yt<n && !free1[xt][yt] && a[xt][yt]!=0 && arr[x+dx[k]][y+dy[k]]!='P'){
            if(a[x][y]>0) linknode[a[x][y]].pb(-a[xt][yt]);
            else linknode[a[xt][yt]].pb(-a[x][y]);
        }
    }
}

bool findpath(){
    FOR(i,1,cl)
        if(mX[i]==0){
            myqueue.push(i);
            dis[i]=0;
        }else dis[i]=oo;
    dis[0]=oo;
    int u,v;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(i,sz(linknode[u])){
            v=linknode[u][i];
            if(dis[mY[v]]==oo){
                dis[mY[v]]=dis[u]+1;
                if(mY[v]) myqueue.push(mY[v]);
            }
        }
    }
    return (dis[0]!=oo);
}

bool dfs(int u){
    if(u==0) return 1;
    int v;
    REP(i,sz(linknode[u])){
        v=linknode[u][i];
        if(dis[mY[v]]==dis[u]+1 && dfs(mY[v])){
            mX[u]=v;
            mY[v]=u;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}
    
#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d\n",&m,&n);
    while(m!=0){
        REP(i,m){
            REP(j,n) scanf("%c",&arr[i][j]);
            scanf("\n");
        }
        cl=cr=0; reset(free1,1);
        REP(i,m) REP(j,n) init(i,j);
        
        reset(mX,0); reset(mY,0); cm=0;
        while(findpath()) FOR(i,1,cl) if(mX[i]==0 && dfs(i)) cm++;
        printf("%d\n",cl+cr-cm);
        scanf("%d%d\n",&m,&n);
        FOR(i,1,cl) linknode[i].clear();
    }
    getch();
    return 0;
}
