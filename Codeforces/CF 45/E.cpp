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

const int maxn=407;

int h,t,R,n,m,dis[maxn][maxn],cnt;
pii cut_head[maxn];
pii cut_tail[maxn];
pii list[maxn*maxn];
bool circle_detected;
queue<pii> myq;
bool mark[maxn][maxn];
bool inDFS[maxn][maxn];

void DFS(int x, int y){
    mark[x][y]=1;
    inDFS[x][y]=1;
    if(x+y<=R){
        int xt,yt;
        FOR(k,1,min(x,n)){
            xt=x-k+cut_head[k].fi; yt=y+cut_head[k].se;
            if(!mark[xt][yt]) DFS(xt,yt); else if(inDFS[xt][yt]) circle_detected=1;
        }
        FOR(k,1,min(y,m)){
            xt=x+cut_tail[k].fi; yt=y-k+cut_tail[k].se;
            if(!mark[xt][yt]) DFS(xt,yt); else if(inDFS[xt][yt]) circle_detected=1;
        } 
    }
    list[++cnt]=pii(x,y);
    inDFS[x][y]=0;
}

void Fixed(int x, int y){
    int xt,yt;
    if(x+y>R) return;
    FOR(k,1,min(x,n)){
        xt=x-k+cut_head[k].fi; yt=y+cut_head[k].se;
        dis[xt][yt]=max(dis[x][y]+1,dis[xt][yt]);
    }
    FOR(k,1,min(y,m)){
        xt=x+cut_tail[k].fi; yt=y-k+cut_tail[k].se;
        dis[xt][yt]=max(dis[x][y]+1,dis[xt][yt]);
    } 
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&h,&t,&R);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&cut_head[i].fi,&cut_head[i].se);
    scanf("%d",&m);
    FOR(i,1,m) scanf("%d%d",&cut_tail[i].fi,&cut_tail[i].se);
    
    FOR(x,0,200) FOR(y,0,200) dis[x][y]=oo;
    dis[h][t]=0;
    myq.push(pii(h,t));
    circle_detected=0;
    int x,y,xt,yt;
    while(!myq.empty()){
        x=myq.front().fi; y=myq.front().se; myq.pop();
        FOR(k,1,min(x,n)){
            xt=x-k+cut_head[k].fi; yt=y+cut_head[k].se;
            if(dis[xt][yt]==oo){
                dis[xt][yt]=dis[x][y]+1;
                if(xt+yt<=R) myq.push(pii(xt,yt));
            }
        }
        FOR(k,1,min(y,m)){
            xt=x+cut_tail[k].fi; yt=y-k+cut_tail[k].se;
            if(dis[xt][yt]==oo){
                dis[xt][yt]=dis[x][y]+1;
                if(xt+yt<=R) myq.push(pii(xt,yt));
            }
        }
    }
    
    if(dis[0][0]!=oo){
        puts("Ivan");
        printf("%d\n",dis[0][0]);    
    }else{
        cnt=0;
        reset(mark,0);
        circle_detected=0;
        DFS(h,t);
        if(circle_detected) puts("Draw");
        else{
            FOR(x,0,200) FOR(y,0,200) dis[x][y]=0;
            int res=-oo;
            FORD(i,cnt,1){
                Fixed(list[i].fi,list[i].se);
                if(list[i].fi+list[i].se>R) res=max(res,dis[list[i].fi][list[i].se]);
            }
            if(res!=-oo){
                puts("Zmey");
                printf("%d\n",res);
            }else puts("Draw");
        }
    }
    //getch();
    return 0;
}        
