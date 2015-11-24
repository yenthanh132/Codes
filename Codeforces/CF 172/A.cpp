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

double w,h,a;
const double pi=acos(-1);

bool giaihpt(double a1, double b1, double c1, double a2, double b2, double c2, double &x, double &y){
    double d=a1*b2-a2*b1;
    double dx=b1*c2-c1*b2;
    double dy=c1*a2-a1*c2;
    if(fabs(d)<1e-9) return 0;
    x=dx/d; y=dy/d;
    return 1;
}

bool giaonhau(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double& X, double& Y){
    double vx1=(y2-y1), vy1=(x1-x2);
    double vx2=(y4-y3), vy2=(x3-x4);
    return giaihpt(vx1,vy1,-vx1*x1-vy1*y1,vx2,vy2,-vx2*x3-vy2*y3,X,Y);
}

int ai;

//#include <conio.h>
int main(){
    cin>>w>>h>>ai;
    if(w<h) swap(w,h);
    if(ai==0 || ai==180) printf("%0.12lf\n",w*h);
    else if(ai==90) printf("%0.12lf\n",min(w,h)*min(w,h));
    else{
        if(ai>90) ai=180-ai;
        a=ai*1.0/180*pi;
        double x1,y1,x2,y2,x3,y3,x4,y4;
        x1=w/2; y1=h/2;
        x2=w/2; y2=-h/2;
        x3=-w/2; y3=-h/2;
        x4=-w/2; y4=h/2;
    
        double i1, j1,i2,j2,i3,j3,i4,j4;
        i1=x1*cos(a)-y1*sin(a);
        j1=x1*sin(a)+y1*cos(a);
        i2=x2*cos(a)-y2*sin(a);
        j2=x2*sin(a)+y2*cos(a);
        i3=-i1; j3=-j1;
        i4=-i2; j4=-j2;
        
        double X[7],Y[7];
        
        X[0]=-w/2; Y[0]=0;
        X[1]=w/2; Y[1]=0;
        giaonhau(x1,y1,x2,y2,i1,j1,i2,j2,X[2],Y[2]);
        giaonhau(x1,y1,x4,y4,i1,j1,i2,j2,X[3],Y[3]);
        giaonhau(x1,y1,x4,y4,i1,j1,i4,j4,X[4],Y[4]);
        giaonhau(x4,y4,x3,y3,i1,j1,i4,j4,X[5],Y[5]);
        if(Y[2]<=h/2){
            X[6]=X[0]; Y[6]=Y[0];
            double r1=0,r2=0;
            REP(i,6){
                r1+=X[i]*Y[i+1];
                r2+=Y[i]*X[i+1];
            }
            printf("%0.12lf\n",fabs(r1-r2));
        }else{
            giaonhau(x1,y1,x4,y4,i2,j2,i3,j3,X[0],Y[0]);
            giaonhau(x1,y1,x4,y4,i1,j1,i4,j4,X[1],Y[1]);
            giaonhau(x2,y2,x3,y3,i1,j1,i4,j4,X[2],Y[2]);
            giaonhau(x2,y2,x3,y3,i2,j2,i3,j3,X[3],Y[3]);
            X[4]=X[0]; Y[4]=Y[0];
            double r1=0,r2=0;
            REP(i,4){
                r1+=X[i]*Y[i+1];
                r2+=Y[i]*X[i+1];
            }
            printf("%0.12lf\n",fabs(r1-r2)/2);
        }
        
    }
    //getch();
    return 0;
}
    
