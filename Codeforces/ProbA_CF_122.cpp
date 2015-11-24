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

#define maxn 57

char a[maxn][maxn];
int m,n,ccom,countnode,low[maxn][maxn],num[maxn][maxn],tchild[maxn][maxn],child[maxn][maxn];
bool chutrinh,mark[maxn][maxn];
int dx[4]={-1,0,1,0}, 
    dy[4]={0,1,0,-1};

void dfs(int x,int y){
    int k,xt,yt;
    countnode++; num[x][y]=low[x][y]=countnode;
    for(k=0;k<4;k++){
        xt=x+dx[k]; yt=y+dy[k];
        if(1<=xt && xt<=m && 1<=yt && yt<=n && a[xt][yt]=='#'){
            child[x][y]++;
            if(num[xt][yt]==0){
                tchild[x][y]++;
                dfs(xt,yt);
                if(low[xt][yt]>=num[x][y]) mark[x][y]=true;
                low[x][y]=min(low[x][y],low[xt][yt]);
            }else low[x][y]=min(low[x][y],num[xt][yt]);
        }
    }
}
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d\n",&m,&n);
    FOR(i,1,m){
        FOR(j,1,n) scanf("%c",&a[i][j]);
        scanf("\n");
    }
    
    ccom=countnode=0;
    reset(num,0); reset(mark,false); reset(child,0); reset(tchild,0);
    FOR(i,1,m) FOR(j,1,n) if (num[i][j]==0 && a[i][j]=='#'){
        ccom++;
        dfs(i,j);
        if (tchild[i][j]<2) mark[i][j]=false;
    }
    
    chutrinh=true; 
    FOR(i,1,m) FOR(j,1,n) 
    if (a[i][j]=='#' && mark[i][j]==true && child[i][j]>1) chutrinh=false;
    
    if(ccom>1) printf("0\n");
    else if(ccom==0 || (ccom==1 && countnode<=2)) printf("-1\n");
    else if (chutrinh) printf("2\n");
    else printf("1\n");
    
    //getch();
    return 0;
}
