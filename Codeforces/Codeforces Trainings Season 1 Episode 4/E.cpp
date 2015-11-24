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

const double eps=1e-9;

double x[5],y[5];
int xc,yc,r;

double sqr(double r){return r*r;}
double dis(double x1, double y1, double x2, double y2){
    return sqrt(sqr(x2-x1)+sqr(y2-y1));
}

double dis2(double x1, double y1, double x2, double y2, double x3, double y3){
    double a=y2-y1, b=x1-x2;
    return fabs(a*(x3-x1) + b*(y3-y1))/sqrt(a*a+b*b);   
}

double val(double x1, double y1, double x2, double y2, double x, double y){
    double a=y2-y1, b=x1-x2;
    return a*(x-x1)+b*(y-y1);
}

bool cung_phia(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
    return val(x1,y1,x2,y2,x3,y3)*val(x1,y1,x2,y2,x4,y4)>=0;   
}

bool equal(double a, double b){
    return fabs(a-b)<eps;
}

bool in_cirle(double x, double y){
    double d=dis(x,y,xc,yc);
    return d<r || equal(d,r);
}   

void giai_hpt(double a1, double b1, double c1, double a2, double b2, double c2, double &x, double &y){
    double d=a1*b2-a2*b1;
    double dx=b1*c2-b2*c1;
    double dy=c1*a2-c2*a1;
    x=dx/d; y=dy/d;
}   

void giao_diem(double x1, double y1, double x2, double y2, double x3, double y3, double &x, double &y){
    if(equal( val(x1,y1,x2,y2,x3,y3), 0)){
        x=x3; y=y3;
        return;
    }
    double a=y2-y1, b=x1-x2;
    double a2=-b, b2=a;
    giai_hpt(a,b,-a*x1-b*y1, a2,b2,-a2*x3-b2*y3, x,y);
}

double in_range(double l, double r, double x){
    if(l>r) swap(l,r);
    return (equal(x,l) || equal(x,r) || (l<x && x<r));
}

bool check(){
    FOR(i,1,3) if(in_cirle(x[i],y[i])) return 1;
    int c=0;
    FOR(i,1,2) FOR(j,i+1,3) if(cung_phia(x[i],y[i],x[j],y[j],x[4],y[4],xc,yc)) c++;
    if(c==3) return 1;
    FOR(i,1,2) FOR(j,i+1,3){
        double D=dis2(x[i],y[i],x[j],y[j],xc,yc);
        if(!equal(D,r) && D>r) continue;
        double X,Y;
        giao_diem(x[i],y[i],x[j],y[j],xc,yc,X,Y);
        if(in_range(x[i],x[j],X) && in_range(y[i],y[j],Y)) return 1;          
    }   
    return 0;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int T;
    cin>>T;
    REP(tt,T){
        FOR(i,1,3) cin>>x[i]>>y[i];
        x[4]=(x[1]+x[2]+x[3])/3; y[4]=(y[1]+y[2]+y[3])/3;
        cin>>xc>>yc>>r;
        
        if(check()) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
    //getch();
    return 0;
}
