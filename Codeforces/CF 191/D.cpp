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

const int maxn=507;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int m,n;
char a[maxn][maxn];
int mark[maxn][maxn];
struct node{
    char ch;
    int x,y;
    node(){}
    node(char _ch, int _x, int _y){
        ch=_ch;
        x=_x;
        y=_y;
    }
};
vector<node> list;
    
void dfs(int x, int y, int x0, int y0){
    int xt,yt;
    mark[x][y]=1;
    list.pb(node('B',x,y));
    REP(k,4){
        xt=x+dx[k];
        yt=y+dy[k];
        if(xt<1 || xt>m || yt<1 || yt>n || mark[xt][yt] || a[xt][yt]=='#') continue;
        dfs(xt,yt,x0,y0);
    }
    if(x!=x0 || y!=y0){
        list.pb(node('D',x,y));
        list.pb(node('R',x,y));
    }
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&m,&n);
    FOR(i,1,m) scanf("%s",a[i]+1);
    reset(mark,0);
    FOR(i,1,m) FOR(j,1,n) if(!mark[i][j] && a[i][j]!='#')
        dfs(i,j,i,j);   
    printf("%d\n",sz(list));
    REP(i,sz(list)) printf("%c %d %d\n",list[i].ch,list[i].x,list[i].y);
        
    //getch();
    return 0;
}
    
