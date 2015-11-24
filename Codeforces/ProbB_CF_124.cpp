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


char arr[1501][1501];
int n,m,xs,ys;
int dx[4]={-1,0,1,0}, dy[4]={0,1,0,-1};
pii save[1501][1501];
bool free1[1501][1501];

void dfs(int x, int y, int xx,int yy){
    if(free1[x][y]) save[x][y]=pii(xx,yy), free1[x][y]=0;
    else if(save[x][y]==pii(xx,yy)) return;
    else {printf("Yes\n"); exit(0);}
    REP(k,4){
        int xt=(x+dx[k]+n)%n, yt=(y+dy[k]+m)%m;
        if(arr[xt][yt]!='#') dfs(xt,yt,xx+dx[k],yy+dy[k]);
    }
}
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d\n",&n,&m);
    REP(i,n){
        REP(j,m) scanf("%c",&arr[i][j]);
        scanf("\n");
    }
    REP(i,n) REP(j,m) if(arr[i][j]=='S'){ xs=i; ys=j; arr[i][j]='.'; break; }
    reset(free1,true);
    dfs(xs,ys,xs,ys);
    printf("No\n");
    //getch();
    return 0;
}
            
