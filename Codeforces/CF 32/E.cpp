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


bool equal(double a, double b){
    return fabs(a-b)<1e-9;
}

bool bigger(double a, double b){
    return (!equal(a,b) && a>b);
}

bool smaller(double a, double b){
    return (!equal(a,b) && a<b);
}

//long long

ll dis(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    ll vx=y1-y2;
    ll vy=x2-x1;
    return vx*(x3-x1)+vy*(y3-y1);
}

bool khacphia(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){
    ll t1=dis(x1,y1,x2,y2,x3,y3);
    ll t2=dis(x1,y1,x2,y2,x4,y4);
    if(t1>1) t1=1; if(t1<-1) t1=-1;
    if(t2>1) t2=1; if(t2<-1) t2=-1;
    return t1*t2<=0;
}

bool catnhau(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){
    return khacphia(x1,y1,x2,y2,x3,y3,x4,y4) && khacphia(x3,y3,x4,y4,x1,y1,x2,y2);
}

bool songsong(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){
    ll vx1=x2-x1, vy1=y2-y1, vx2=x4-x3, vy2=y4-y3;
    return vx1*vy2==vx2*vy1;
}


// double 
double dis(double x1, double y1, double x2, double y2, double x3, double y3){
    double vx=y1-y2;
    double vy=x2-x1;
    return vx*(x3-x1)+vy*(y3-y1);
}

bool khacphia(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    double t1=dis(x1,y1,x2,y2,x3,y3);
    double t2=dis(x1,y1,x2,y2,x4,y4);
    if(t1>1) t1=1; if(t1<-1) t1=-1;
    if(t2>1) t2=1; if(t2<-1) t2=-1;
    return !bigger(t1*t2,0.0);
}

bool dcatnhau(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    return khacphia(x1,y1,x2,y2,x3,y3,x4,y4) && khacphia(x3,y3,x4,y4,x1,y1,x2,y2);
}

//-----------------------------------------------------------------------


double giaihpt(double a1, double b1, double c1, double a2, double b2, double c2, double &X, double &Y){
    double d=a1*b2-a2*b1;
    double dx=b1*c2-b2*c1;
    double dy=c1*a2-c2*a1;
    X=dx/d; Y=dy/d;
}

double hinhchieu(double x1, double y1, double x2, double y2, double x0, double y0, double &X, double &Y){
    double vx=y1-y2;
    double vy=x2-x1;
    giaihpt(vx,vy,-x1*vx-y1*vy,vy,-vx,-x0*vy+y0*vx,X,Y);
}

double I1,J1,I2,J2,xx,yy;
ll xv,yv,xp,yp;

double cal(double val, double len){
    double vx,vy,l1,l2;
    vx=I2-I1; vy=J2-J1;
    xx=vx*val/len+I1; yy=vy*val/len+J1;
    l1=hypot(xv-xx,yv-yy);
    l2=hypot(xp-xx,yp-yy);
    return val/l1-(len-val)/l2;
}
    
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    
    
    cin>>xv>>yv>>xp>>yp;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    if((!catnhau(xv,yv,xp,yp,x1,y1,x2,y2) || (songsong(xv,yv,xp,yp,x1,y1,x2,y2) 
            && (min(x1,x2)>max(xv,xp) || min(y1,y2)>max(yv,yp) || max(x1,x2)<min(xv,xp) || max(y1,y2)<min(yv,yp))))
      && (songsong(xv,yv,xp,yp,x3,y3,x4,y4) || !catnhau(xv,yv,xp,yp,x3,y3,x4,y4))){
        puts("YES");
        //getch();
        return 0;
    }
    if(!khacphia(x3,y3,x4,y4,xv,yv,xp,yp)){
        hinhchieu(x3,y3,x4,y4,xv,yv,I1,J1);
        hinhchieu(x3,y3,x4,y4,xp,yp,I2,J2);
        double len=hypot(I1-I2,J1-J2);
        double left=0, right=len, mid, val;
        while(fabs(right-left)>1e-9){
            mid=(left+right)/2;
            val=cal(mid,len);
            if(val>0) right=mid; else left=mid;
        }
        cal((left+right)/2,len);
        if(!smaller(xx,min(x3,x4)) && !bigger(xx,max(x3,x4))  
        && !smaller(yy,min(y3,y4)) && !bigger(yy,max(y3,y4))
        && !dcatnhau(xx,yy,xv,yv,x1,y1,x2,y2) && !dcatnhau(xx,yy,xp,yp,x1,y1,x2,y2)){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    //getch();
    return 0;
}
    
    
