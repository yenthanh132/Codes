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

const int maxn=37;

struct point{
    double x,y;
} p[maxn];
int n,t;

void giaihpt(double a1, double b1, double c1, double a2, double b2, double c2, double &x, double &y){
    double d=a1*b2-a2*b1;
    double dx=b1*c2-b2*c1;
    double dy=c1*a2-c2*a1;
    x=dx/d; y=dy/d;   
}

bool tam(int i, int j, int k, point &p0){
    point p1=p[i], p2=p[j], p3=p[k];
    if( fabs((p1.x-p2.x)*(p3.y-p2.y) - (p3.x-p2.x)*(p1.y-p2.y))<1e-9 ) return 0;
    double vx1,vy1,vx2,vy2;
    vx1=p2.x-p1.x; vy1=p2.y-p1.y;
    vx2=p3.x-p1.x; vy2=p3.y-p1.y;
    giaihpt(vx1, vy1, -vx1*(p1.x+p2.x)/2 - vy1*(p1.y+p2.y)/2, vx2, vy2, -vx2*(p1.x+p3.x)/2 -vy2*(p1.y+p3.y)/2, p0.x, p0.y);
    return 1;
}

double dis(const point &a, const point &b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool ok(int i, int j, int k, int x){
    point mp;
    double R, R2;
    if(!tam(i,j,k,mp)) return 0;
    R=dis(mp,p[i]);
    R2=dis(mp,p[x]);
    if(R2>R+1e-9) return 0;
    return 1;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&t);
    REP(tt,t){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%lf%lf",&p[i].x,&p[i].y);
        double num=0, den=n*(n-1)*(n-2)*(n-3)/6;
        FOR(i,1,n-2) FOR(j,i+1,n-1) FOR(k,j+1,n)
            FOR(x,1,n) if(x!=i && x!=j && x!=k && ok(i,j,k,x)) num+=1;
        
        printf("%0.12lf\n",num/den);
    }
    
    //getch();
    return 0;
}
