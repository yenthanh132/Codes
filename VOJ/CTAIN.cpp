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

int Test,n,cap[4];

struct node{int a[4];};

struct classcmp{
    bool operator()(const node &a, const node &b){
        REP(i,n) if(a.a[i]<b.a[i]) return 1; else if(a.a[i]>b.a[i]) return 0;
        return 0;
    }
};

node start,finish;

map<node,int,classcmp> dis;
map<node,node,classcmp> trace;

bool equal(node a, node b){
    REP(i,n) if(a.a[i]!=b.a[i]) return 0;
    return 1;
}

int bfs(){
    queue<node> myqueue;
    if(equal(start,finish)) return 0;
    myqueue.push(start);
    dis.clear();
    dis[start]=0;
    node u,v;
    int d;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop(); d=dis[u];
        REP(i,n){
            v=u;
            v.a[i]=0;
            if(equal(v,finish)){
                trace[v]=u;
                return d+1;
            }
            if(dis.find(v)==dis.end()){
                dis[v]=d+1;
                trace[v]=u;
                myqueue.push(v);
            }
        }
        REP(i,n) if(u.a[i]) REP(j,n) if(i!=j){
            v=u;
            if(v.a[i]+v.a[j]<=cap[j]){
                v.a[j]+=v.a[i];
                v.a[i]=0;
                if(equal(v,finish)){
                    trace[v]=u;
                    return d+1;
                }
                if(dis.find(v)==dis.end()){
                    dis[v]=d+1;
                    trace[v]=u;
                    myqueue.push(v);
                }
            }
            v=u;
            if(v.a[j]<cap[j] && v.a[i]+v.a[j]>=cap[j]){
                v.a[i]-=cap[j]-v.a[j];
                v.a[j]=cap[j];
                
                if(equal(v,finish)) return d+1;
                
                if(dis.find(v)==dis.end()){
                    dis[v]=d+1;
                    trace[v]=u;
                    myqueue.push(v);
                }
            }
        }
    }
    return oo;
}
        
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&Test);
    REP(i,Test){
        scanf("%d",&n);
        reset(start.a,0); reset(finish.a,0);
        REP(i,n) scanf("%d",&start.a[i]), cap[i]=start.a[i];
        REP(i,n) scanf("%d",&finish.a[i]);
        int res=bfs();
        if(res!=oo) printf("%d\n",res); else puts("NO");
    }
    //getch();
    return 0;
}
