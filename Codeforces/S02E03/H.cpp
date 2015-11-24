#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=207;

struct point{
    double x,y;
    point(){}
    point(double a, double b):x(a),y(b){}
}p[maxn], original;
int n,r;

bool hpt(double a1, double b1, double c1, double a2, double b2, double c2, double &X, double &Y){
    double d=a1*b2-a2*b1;
    if(d==0) return 0;
    double dx=b1*c2-b2*c1;
    double dy=c1*a2-c2*a1;
    X=dx/d; Y=dy/d;
    return 1;
}

bool insect(point a, point b, point c, point d, point &x){
    double A1=a.y-b.y, B1=b.x-a.x, C1=-A1*a.x - B1*a.y;
    double A2=c.y-d.y, B2=d.x-c.x, C2=-A2*c.x - B2*c.y;
    return hpt(A1,B1,C1,A2,B2,C2,x.x,x.y);
}

double rad(point a, point b, point c){
    double vx1=b.x-a.x, vy1=b.y-a.y;
    double vx2=c.x-a.x, vy2=c.y-a.y;
    return (vx1*vx2 + vy1*vy2)/sqrt( sqr(vx1) + sqr(vy1) ) /sqrt( sqr(vx2) + sqr(vy2) );
}

double dis(point a, point b){
    return hypot(a.x-b.x,a.y-b.y);
}

point insect(double R, point a, point b, int sign){
    // Now intersecting circle (x1,y1,r1) with line ax+by=c
    double A=a.y-b.y, B=b.x-a.x, C=A*a.x + B*a.y;
    double e = C - A*0 - B*0;
    double h = sqrt( sqr(R) - sqr(e)); // check if r1<e for circle-line test
    point res;
    res.x=A*e + sign*h*(-B);
    res.y=B*e + sign*h*A;
    return res;
}

double dot(point a, point b){
    return a.x*b.x+a.y*b.y;
}

point CircleLineIntersection(point a, point b, point c, double r) {
    b.x -= a.x; b.y-=a.y;
    a.x -= c.x; a.y-=c.y;
    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r*r;
    double D = B*B - A*C;
    point res;
    res.x=c.x+a.x+b.x*(-B+sqrt(D))/A;
    res.y=c.y+a.y+b.y*(-B+sqrt(D))/A;
    return res;
}

int main(){
    freopen("input.txt","r",stdin);
    original.x=original.y=0;
    scanf("%d%d",&n,&r);
    for(int i=0; i<n; ++i) scanf("%lf%lf",&p[i].x,&p[i].y);
    double res = 0;
    for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j){
        point a=p[i], b=p[(i+1)%n];
        point c=p[j], d=p[(j+1)%n];
        point x;
        if(insect(a,b,c,d,x)){
            if(dis(x,original)<=r){
                point pleft;
                if(a.x!=x.x || a.y!=x.y) pleft = CircleLineIntersection(a,x,original,r); else pleft = CircleLineIntersection(b,x,original,r);
                point pright;
                if(c.x!=x.x || c.y!=x.y) pright = CircleLineIntersection(c,x,original,r); else pright = CircleLineIntersection(d,x,original,r);

                double rad1 = atan2(pleft.y, pleft.x);
                double rad2 = atan2(pright.y,pright.x);
                if(rad2<rad1) rad2+=2*PI;
            }else{
                res=max(res,rad(x,a,d));
            }
        }
    }
    return 0;
}
