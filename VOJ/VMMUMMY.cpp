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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
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
typedef pair<pii,int> iii;

struct node{int x,y,x1,y1,x2,y2;};

struct cmpclass{
    bool operator()(const node &u, const node& v){
        if(u.x<v.x) return true; else if(u.x>v.x) return false;
        else if(u.y<v.y) return true; else if(u.y>v.y) return false;
        else if(u.x1<v.x1) return true; else if(u.x1>v.x1) return false;
        else if(u.y1<v.y1) return true; else if(u.y1>v.y1) return false;
        else if(u.x2<v.x2) return true; else if(u.x2>v.x2) return false;
        else if(u.y2<v.y2) return true; else return false;
    }
};

map<node,int,cmpclass> cost;
map<node,bool,cmpclass> mark;
map<node,node,cmpclass> track;
queue<node> myqueue;


const int dx[5]={1,0,0,-1,0};
const int dy[5]={0,1,-1,0,0};
const int dxm[2][4]={{-1,1,0,0}, {0,0,-1,1}};
const int dym[2][4]={{0,0,-1,1}, {-1,1,0,0}};

int n,sx,sy,fx,fy,z1,z2,m;
bool locked[11][11][11][11];

bool inside(int x,int y){
    if(x<1 || x>n || y<1 || y>n) return false; else return true;
}

bool ok_state(const node &u){
    if((u.x==u.x1 && u.y==u.y1) || (u.x==u.x2 && u.y==u.y2)) return false; else return true;
}

int myabs(int x){return((x>=0)?x:-x);}

int dis(int x1, int y1, int x2, int y2){return(myabs(x2-x1)+myabs(y2-y1));}

void mummy_move(node &u){
    int xx,yy,sk,mindis;
    if(m>=1)
        REP(i,2){
            sk=-1; mindis=dis(u.x,u.y,u.x1,u.y1);
            REP(k,4){
                xx=u.x1+dxm[z1][k]; yy=u.y1+dym[z1][k];
                if(inside(xx,yy) && !locked[u.x1][u.y1][xx][yy] && dis(u.x,u.y,xx,yy)<mindis){
                    mindis=dis(u.x,u.y,xx,yy);
                    sk=k;
                }
            }
            if(sk!=-1) u.x1+=dxm[z1][sk], u.y1+=dym[z1][sk];
        }
    if(m==2)
        REP(i,2){
            sk=-1; mindis=dis(u.x,u.y,u.x2,u.y2);
            REP(k,4){
                xx=u.x2+dxm[z2][k]; yy=u.y2+dym[z2][k];
                if(inside(xx,yy) && !locked[u.x2][u.y2][xx][yy] && dis(u.x,u.y,xx,yy)<mindis){
                    mindis=dis(u.x,u.y,xx,yy);
                    sk=k;
                }
            }
            if(sk!=-1) u.x2+=dxm[z2][sk], u.y2+=dym[z2][sk];
        }
}

int getmove(int oldx, int oldy, int newx, int newy){
    REP(k,5) if(newx==oldx+dx[k] && newy==oldy+dy[k]) return k;
}

node bfs(){
    node u1,u2;
    while(!myqueue.empty()){
        u1=myqueue.front(); myqueue.pop();
        REPD(k,5){      
            u2=u1;
            u2.x+=dx[k]; u2.y+=dy[k];
            if(u2.x==fx && u2.y==fy){
                cost[u2]=cost[u1]+1;
                track[u2]=u1;
                return u2;
            }
            if(!inside(u2.x,u2.y) || locked[u1.x][u1.y][u2.x][u2.y]) continue;
            mummy_move(u2);
            if(!ok_state(u2)) continue;
            if(mark.find(u2)==mark.end()){
                track[u2]=u1;
                cost[u2]=cost[u1]+1;
                mark[u2]=true;
                myqueue.push(u2);
            }else if(cost[u2]==cost[u1]+1){
                node ut=track[u2];
                if(getmove(ut.x,ut.y,u2.x,u2.y)>k) track[u2]=u1;
            }
        }
    }
}  
      
void output(node v){
    node u;
    vector<int> ds;
    while(cost[v]>0){
        u=track[v];
        ds.pb(getmove(u.x,u.y,v.x,v.y));
        v=u;
    }
    REPD(i,sz(ds)) printf("%d",ds[i]); printf("\n");
} 
        
#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d%d%d%d",&n,&sx,&sy,&fx,&fy,&m);
    node start,finish;
    start.x=sx; start.y=sy;
    if(m>=1) scanf("%d%d%d",&start.x1,&start.y1,&z1); else start.x1=0, start.y1=0;
    if(m==2) scanf("%d%d%d",&start.x2,&start.y2,&z2); else start.x2=0, start.y2=0;
    
    reset(locked,false);
    int count,u,v,uu,vv;
    REP(index,2){
        scanf("%d",&count);
        REP(i,count){
            scanf("%d%d",&u,&v);
            uu=u; vv=v;
            if(index) vv++; else uu++;
            locked[u][v][uu][vv]=locked[uu][vv][u][v]=true;
        }
    }
    
    mark[start]=true; 
    cost[start]=0;
    myqueue.push(start);
    finish=bfs();
    output(finish);
    getch();
    return 0;
}
