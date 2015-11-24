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

const int maxn = 2001;
int n,m,k,x,y,up[maxn][maxn], down[maxn][maxn];
bool free1[maxn][maxn];

pii query(int x, int y){
    if(free1[x][y]) return(pii(x,y));
    int ans, X, Y, i,dis,z;
    ans=oo;
    for(int len=0; len<=ans; len++)
        for(z=-1;z<=1; z+=2){
            i=x+len*z;
            if(i<1 || i>n) continue;
            if(free1[i][y]){
                dis=len;
                if(dis<ans || (dis==ans && (i<X || (i==X && y<Y)))) ans=dis, X=i, Y=y;
            }
            if(up[i][y]){
                dis=len+up[i][y]-y;
                if(dis<ans || (dis==ans && (i<X || (i==X && up[i][y]<Y)))) ans=dis, X=i, Y=up[i][y];
            }
            if(down[i][y]){
                dis=len+y-down[i][y];
                if(dis<ans || (dis==ans && (i<X || (i==X && down[i][y]<Y)))) ans=dis, X=i, Y=down[i][y];
            }
        }
    return(pii(X,Y));
}
 
void del(int x, int y){
    free1[x][y]=false;
    FOR(i,y+1,m){
        down[x][i]=down[x][y];
        if(free1[x][i]) break;
    }
    FORD(i,y-1,1){
        up[x][i]=up[x][y];
        if(free1[x][i]) break;
    }
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) FOR(j,1,m){
        up[i][j]=(j<m?j+1:0);
        down[i][j]=j-1;
    }
    reset(free1,true);
    REP(kk,k){
        scanf("%d%d",&x,&y);
        pii ans=query(x,y);
        printf("%d %d\n",ans.fi,ans.se);
        del(ans.fi, ans.se);
    }
    //getch();
    return 0;    
}
