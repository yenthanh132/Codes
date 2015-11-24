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

const double eps = 0.00001;
const double PI = 3.14159265358979323846264338327950288419716939937510;

pair<double,double> hpt(double a1, double b1, double c1, double a2, double b2, double c2){
    double d=a1*b2-a2*b1, dx=b1*c2-b2*c1, dy=c1*a2-c2*a1;
    return mp(dx/d,dy/d);
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    double x1,y1,x2,y2,x3,y3,xmid,ymid;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    
    double a1=x1-x2, b1=y1-y2, c1=(x2-x1)*(x1+x2)/2-(y1-y2)*(y1+y2)/2;
    double a2=x2-x3, b2=y2-y3, c2=(x3-x2)*(x2+x3)/2-(y2-y3)*(y2+y3)/2;
    pair<double,double> center=hpt(a1,b1,c1,a2,b2,c2);
    
    double r1=atan2(center.se-y1,center.fi-x1);
    double r2=atan2(center.se-y2,center.fi-x2);
    double r3=atan2(center.se-y3,center.fi-x3);
    int N;
    
    for(N=3;;N++)
        if(fabs(sin(N*(r1-r2)/2))<eps && fabs(sin(N*(r1-r3)/2))<eps && fabs(sin(N*(r2-r3)/2))<eps) break;
    double d=(center.fi-x1)*(center.fi-x1)+(center.se-y1)*(center.se-y1);
    double res=double(N)*d/2*sin(2*PI/double(N));
    printf("%0.10f\n",res);
    
    /*a1=x2-x1; b1=y2-y1;
    a2=x3-x1; b2=y3-y1;
    printf("%0.10f",fabs(a1*b2-a2*b1)/2);
    getch();*/
    return 0;
}
