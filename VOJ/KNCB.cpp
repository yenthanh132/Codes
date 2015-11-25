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

const int maxn=207;
const int dx[8]={-2,-1,1,2,2,1,-1,-2};
const int dy[8]={1,2,2,1,-1,-2,-2,-1};

int a[maxn][maxn],m,n,k,x,y,mX[maxn*maxn],mY[maxn*maxn],dis[maxn*maxn],res;
vector<int> e[maxn*maxn];

bool findpath(){
    queue<int> myqueue;
    FOR(i,1,x) if(mX[i]==0){
        dis[i]=0;
        myqueue.push(i);
    }else dis[i]=oo;
    dis[0]=oo;
    int u,v;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        REP(j,sz(e[u])){
            v=e[u][j];
            if(dis[mY[v]]==oo){
                dis[mY[v]]=dis[u]+1;
                if(mY[v]!=0) myqueue.push(mY[v]);
            }
        }
    }
    return dis[0]!=oo;
}

bool dfs(int u){
    if(u==0) return 1;
    int v;
    REP(i,sz(e[u])){
        v=e[u][i];
        if(dis[mY[v]]==dis[u]+1 && dfs(mY[v])){
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
    FOR(index,1,test){
        scanf("%d%d%d",&m,&n,&k);
        if(k==0 && m>2 && n>2){
            printf("Case %d: %d\n",index,(m*n+1)/2);
            continue;
        }
        int u,v;
        reset(a,0);
        FOR(i,1,k){
            scanf("%d%d",&u,&v);
            a[u][v]=-1;
        }
        x=y=0;
        FOR(i,1,m) FOR(j,1,n) if(a[i][j]!=-1 && (i+j)%2==0){
            x++;
            e[x].clear();
            a[i][j]=x;
            REP(k,8){
                u=i+dx[k]; v=j+dy[k];
                if(1<=u && u<=m && 1<=v && v<=n){
                    if(a[u][v]==0) a[u][v]=++y;
                    if(a[u][v]!=-1) e[x].pb(a[u][v]);
                }
            }
        }
        FOR(i,1,m) FOR(j,1,n) if(a[i][j]==0) y++;
        reset(mX,0); reset(mY,0); res=0;
        while(findpath())
            FOR(i,1,x) if(mX[i]==0 && dfs(i)) res++;
        printf("Case %d: %d\n",index,x+y-res);
    }
    //getch();
    return 0;
}
                        
                
            
