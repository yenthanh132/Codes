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
const int maxv=67;
const int maxk=37;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
const char dch[4]={'W','N','E','S'};

int n,m,k,dp[maxv][maxv][maxk],a[maxv][maxv];
string move[maxv][maxv][maxk];
struct point{int x,y;} cow[maxn],haystack[maxn];
struct node{
    int x,y,t;
    node(){}
    node(int _x, int _y, int _t){
        x=_x; y=_y; t=_t;
    }
};
queue<node> myq;
int res;
string moveres;

int dis(point a, point b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}

bool update(int &a, string &b, int a0, string b0){
    if(a<a0){
        a=a0;
        b=b0;
        return 1;
    }else if(a==a0 && b0<b) b=b0;
    return 0;
}
    
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%d%d",&cow[i].x,&cow[i].y);
    FOR(i,1,m) scanf("%d%d",&haystack[i].x,&haystack[i].y);
    
    FOR(i,1,n)
        FOR(j,1,m) if(dis(cow[i],haystack[j])<=k)
            a[haystack[j].x-cow[i].x+k][haystack[j].y-cow[i].y+k]++;
    
    dp[k][k][0]=1;
    move[k][k][0]="";
    myq.push(node(k,k,0));    
    res=0;
    node u,v;
    while(!myq.empty()){
        u=myq.front(); myq.pop();
        if(u.t==k){
            update(res,moveres,dp[u.x][u.y][u.t],move[u.x][u.y][u.t]);
            continue;
        }
        REP(kt,4){
            v.x=u.x+dx[kt]; v.y=u.y+dy[kt]; v.t=u.t+1;
            if(update(dp[v.x][v.y][v.t],move[v.x][v.y][v.t], 
                   dp[u.x][u.y][u.t]+a[v.x][v.y], move[u.x][u.y][u.t]+dch[kt]))
                myq.push(node(v.x,v.y,v.t));;
            
        }
    }
    
    cout<<res-1<<endl;
    cout<<moveres<<endl;
    //getch();
    return 0;
}
            
