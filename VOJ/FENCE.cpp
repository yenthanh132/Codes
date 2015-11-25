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

const int maxn=307;
const double pi=acos(-1);

struct point{int x,y;};

int n,next_left2[maxn][maxn],next_left[maxn][maxn],id[maxn];
point a[maxn];

int getnextleft(int i, int j){
    double minr=oo,r1,r2,r;
    int pos=-1;
    int vx1=a[j].x-a[i].x, vy1=a[j].y-a[i].y;
    int vx2,vy2;
    r1=atan2(vy1,vx1);
    FOR(z,1,n) if(z!=i && z!=j){
        vx2=a[z].x-a[j].x; vy2=a[z].y-a[j].y;
        if(vy2*vx1>vy1*vx2){
            r2=atan2(vy2,vx2);
            if(r2>r1) r=r2-r1; else r=r2-r1+2*pi;
            if(r<minr){
                minr=r;
                pos=z;
            }
        }
    }
    return pos;
}

int getnextleft2(int i, int j){
    double minr=oo,r1,r2,r;
    int pos=-1;
    int vx1=a[j].x-a[i].x, vy1=a[j].y-a[i].y;
    int vx2,vy2;
    r1=atan2(vy1,vx1);
    FOR(z,1,n) if(z!=i && z!=j){
        vx2=a[z].x-a[i].x; vy2=a[z].y-a[i].y;
        if(vy2*vx1>vy1*vx2){
            r2=atan2(vy2,vx2);
            if(r2>r1) r=r2-r1; else r=r2+2*pi-r1;
            if(r<minr){
                minr=r;
                pos=z;
            }
        }
    }
    return pos;
}

int origin,dp[maxn][maxn];

int get_res(int i, int j){
    if(j==origin) return 2;
    if(dp[i][j]!=-1) return dp[i][j];
    int v1=(a[j].y >= a[origin].y && next_left[i][j]!=-1)?get_res(j,next_left[i][j])+1:0;
    int v2=(next_left2[i][j]!=-1)?get_res(i,next_left2[i][j]):0;
    dp[i][j]=max(v1,v2);
    return dp[i][j];
}

//#include <conio.h>
int main(){
    
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
    FOR(i,1,n) FOR(j,1,n) if(i!=j){
        next_left2[i][j]=getnextleft2(i,j);
        next_left[i][j]=getnextleft(i,j);
    }
    int res=0;
    for(origin=1; origin<=n; origin++){
        FOR(x,1,n) FOR(y,1,n) dp[x][y]=-1;
        FOR(x,1,n) if(x!=origin && a[x].y >= a[origin].y && next_left[origin][x]!=-1) 
            res=max(get_res(x,next_left[origin][x]),res);
        
    }
    cout<<res<<endl;
    //getch();
    return 0;
}    
    
