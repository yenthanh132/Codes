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

const int maxn = 501;
const int dx[2][3]={{0,1,1},{0,1,1}};
const int dy[2][3]={{1,1,0},{-1,-1,0}};

bool free1[maxn][maxn];
int mark[maxn][maxn],mark2[maxn][maxn],n,k;
queue<pii> q[2][2];

int bfs(){
    if(n==1) return 0;
    int v,xt,yt;
    pii u;
    reset(mark,0); reset(mark2,0);
    q[0][0].push(pii(1,1));
    q[1][0].push(pii(1,n));
    FOR(step,1,n*2){
        v=1-step%2;
        while(!q[0][v].empty()){
            u=q[0][v].front(); q[0][v].pop();
            REP(k,3){
                xt=u.fi+dx[0][k]; yt=u.se+dy[0][k];
                if(xt>n || yt>n || !free1[xt][yt] || mark[xt][yt]==step) continue;
                mark[xt][yt]=step;
                q[0][1-v].push(pii(xt,yt));
            }
        }
        while(!q[1][v].empty()){
            u=q[1][v].front(); q[1][v].pop();
            REP(k,3){
                xt=u.fi+dx[1][k]; yt=u.se+dy[1][k];
                if(xt>n || yt<1 || !free1[xt][yt] || mark2[xt][yt]==step) continue;
                if(mark[xt][yt]==step) return(step);
                mark2[xt][yt]=step;
                q[1][1-v].push(pii(xt,yt));
            }
        }
    }
    return -1;
}
                
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    reset(free1,true);
    int x,y;
    REP(i,k){
        scanf("%d%d",&x,&y);
        free1[x][y]=false;
    }
    printf("%d",bfs());
    //getch();
    return 0;
}
