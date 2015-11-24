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

const double PI = atan(1)*4;
const double eps = 0.0000001;
int xp,yp,vp,x,y,v,r;
double R,w,rad;

#include <conio.h>

void getpos(double rad1, double R, double &xx, double &yy){
    while(rad1<0) rad1=rad1+2*PI;
    while(rad1>2*PI) rad1=rad1-2*PI;
    if(abs(rad1-PI/2)<eps){
        xx=0; yy=R;
    }else{
        double k=tan(rad+w*t);
        xx=sqrt(R/(1+k*k));
        yy=sqrt(R*R-xx*xx);
    }
}
    
double distance(double x1, double y1, double x2, double y2, double x, double y){
    double vx, double vy;
    vx=y2-y1; vy=x1-x2;
    return(abs(vx*(x-x1)+vy*(y-y1))/sqrt(vx*vx+vy*vy));
}



bool check(double t){
    double xx,yy,dis;
    getpos(rad+w*t,R,xx,yy);
    if(distance(x,y,xx,yy,0,0)>=r) dis=sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
    else{
        
    
void solve(){
    double res=0,l=0,r=10000;
    while(r-l>eps){
        mid=(r+l)/2;
        if(check(mid)){
            res=mid;
            r=mid;
        }else l=mid;
    }
}   

int main(){
    freopen("test.txt","r",stdin);
    cin>>xp>>yp>>vp;
    cin>>x>>y>>v>>r;
    
    R=sqrt(xp*xp+yp*yp);
    rad=atan2(yp,xp);
    w=vp/R;
    
    solve();
    
    
    
    getch();
    return 0;
}
