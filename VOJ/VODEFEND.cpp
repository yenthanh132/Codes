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

const int maxn=57;
double eps=1e-9;

double dp[maxn][maxn][maxn],res;
int n,k,m,val[maxn][maxn];
struct point{int x,y;} a[maxn],b[maxn];

bool diff(point a, point b){
    return a.x!=b.x || a.y!=b.y;
}

int ccw(point p1, point p2, point p3){
    ll vx1=p2.x-p1.x, vy1=p2.y-p1.y;
    ll vx2=p3.x-p1.x, vy2=p3.y-p1.y;
    if(vx1*vy2-vx2*vy1>0) return 1; else if(vx1*vy2-vx2*vy1==0) return 0; else return -1;
}

ll dis2(point p1, point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

bool online(point p1, point p2, point p){
    ll vx=p2.y-p1.y, vy=p1.x-p2.x;
    return (vx*(p.x-p1.x)+vy*(p.y-p1.y)==0 
    && min(p1.x,p2.x)<=p.x && p.x<=max(p1.x,p2.x)
    && min(p1.y,p2.y)<=p.y && p.y<=max(p1.y,p2.y));
}

bool inside(point p1, point p2, point p3, point p){
    return ccw(p1,p2,p)==1 && ccw(p2,p3,p)==1 && ccw(p3,p1,p)==1;
} 

int count(int i, int j){
    int res=0;
    FOR(k,2,m) if(k!=i)
        if(inside(b[1],b[i],b[j],b[k]) || online(b[i],b[j],b[k]) || online(b[j],b[1],b[k]))
            res++;
    return res;
}

double sqr(double v){return v*v;}

double dis(int i, int j){
    return sqrt(sqr(b[i].x-b[j].x)+sqr(b[i].y-b[j].y));
}

void update(double &a, double b){
    a=min(a,b);
}

void solve(int r){
    b[m=1]=a[r];
    FOR(i,1,n) if(i!=r)
        if(a[i].x>a[r].x || a[i].y>a[r].y)
            b[++m]=a[i];
    if(m<k) return;
    FOR(i,2,m-1) FOR(j,i+1,m)
        if(atan2(b[i].y-b[1].y,b[i].x-b[1].x) > atan2(b[j].y-b[1].y,b[j].x-b[1].x) + eps
        || (fabs(atan2(b[i].y-b[1].y,b[i].x-b[1].x)-atan2(b[j].y-b[1].y,b[j].x-b[1].x))<eps
             && dis2(b[1],b[i])>dis2(b[1],b[j]))) swap(b[i],b[j]);
    FOR(i,1,m-1) FOR(j,i+1,m) val[i][j]=count(i,j);
    
    FOR(i,1,m-1) FOR(j,i+1,m) FOR(z,0,m) dp[i][j][z]=oo;
    FOR(i,2,m) dp[1][i][val[1][i]]=dis(1,i);
    FOR(i,1,m-2) FOR(j,i+1,m-1) FOR(z,0,m) if(dp[i][j][z]!=oo)
        FOR(k,j+1,m) if(ccw(b[i],b[j],b[k])==1)
            update(dp[j][k][z+val[j][k]],dp[i][j][z]+dis(j,k));
        
    
    FOR(i,1,m-1) FOR(j,i+1,m) FOR(z,k-1,m) if(dp[i][j][z]!=oo)
        update(res,dp[i][j][z]+dis(j,1));
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    res=oo;
    scanf("%d%d",&n,&k);
    
    FOR(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
    
    if(k==1)
        res=0;
    else
        FOR(i,1,n) solve(i);
    printf("%0.4lf\n",res);
    
    //getch();
    return 0;
}
