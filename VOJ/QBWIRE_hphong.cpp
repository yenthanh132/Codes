#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

#define rep(i,a,b) for (long i=a; i<=b; i++)

using namespace std;

const long dx[4]={0,1,0,-1};
const long dy[4]={1,0,-1,0};
const long oo=1000000000;

typedef struct {long x,y;} point;

queue <point> q;
point A,B,C,D,prev[555][555],blank;
long deg[555][555],result,n;
bool notFree[555][555];

bool same(point a, point b)
{
    return (a.x==b.x&&a.y==b.y);
}

bool outside(point u)
{
    return ((u.x<0)||(u.y<0)||(u.x>n-1)||(u.y>n-1));
}

int BFS(point s, point t)
{
    while (!q.empty()) q.pop();
    q.push(s); notFree[s.x][s.y]=true; deg[s.x][s.y]=0; prev[s.x][s.y]=blank;
    if (same(s,t)) return 0;
    do
    {
        point u=q.front(); q.pop();
        rep(k,0,3)
        {
            point v;
            v.x=u.x+dx[k];
            v.y=u.y+dy[k];
            if (notFree[v.x][v.y]) continue;
            if (outside(v)) continue;
            deg[v.x][v.y]=deg[u.x][u.y]+1;
            notFree[v.x][v.y]=true;
            prev[v.x][v.y]=u;
            q.push(v);
            if (same(v,t)) return 0;
        }
    }
    while (!q.empty());
}

int trace(point s, point t)
{
    point v=t;
    while (!same(prev[v.x][v.y],blank))
    {
        notFree[v.x][v.y]=true;
        v=prev[v.x][v.y];
    }
    notFree[s.x][s.y]=true;
}

long process()
{
    scanf("%ld",&n);
    scanf("%ld%ld%ld%ld",&A.x,&B.x,&C.x,&D.x);
    scanf("%ld%ld%ld%ld",&A.y,&B.y,&C.y,&D.y);
    result=oo;
    if (same(A,C)||same(A,D)||same(B,C)||same(B,D)) return -1;
    if (same(A,B)&&same(C,D)) return 0;
    memset(notFree,false,sizeof(notFree));
    memset(deg,0,sizeof(deg));
    notFree[C.x][C.y]=notFree[D.x][D.y]=true;
    BFS(A,B);
    if (notFree[B.x][B.y])
    {
        memset(notFree,false,sizeof(notFree));
        trace(A,B);
        notFree[C.x][C.y]=notFree[D.x][D.y]=false; BFS(C,D);
        if (notFree[D.x][D.y]) result=min(result,deg[B.x][B.y]+deg[D.x][D.y]);
    }
    memset(notFree,false,sizeof(notFree));
    memset(deg,0,sizeof(deg));
    notFree[A.x][A.y]=notFree[B.x][B.y]=true;
    BFS(C,D);
    if (notFree[D.x][D.y]) 
    {
        memset(notFree,false,sizeof(notFree));
        trace(C,D);
        notFree[A.x][A.y]=notFree[B.x][B.y]=false; BFS(A,B);
        if (notFree[B.x][B.y]) result=min(result,deg[B.x][B.y]+deg[D.x][D.y]);
    }
    if (result==oo) return -1; else return result;
}

int main()
{
    blank.x=blank.y=-1;
    long test;
    scanf("%ld",&test);
    rep(i,1,test) printf("%ld\n",process());
    return 0;
}
