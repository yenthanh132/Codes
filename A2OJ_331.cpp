#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;
const double PI=acos(-1);

double x[maxn],y[maxn];
int n;

double area(double x1, double y1, double x2, double y2, double x3, double y3){
    double vx=x2-x1, vy=y2-y1;
    double vx2=x3-x1, vy2=y3-y1;
    return abs(vx2*vy-vx*vy2)*0.5;
}

void giaiHpt(double a1, double b1, double c1, double a2, double b2, double c2, double &x, double &y){
    double d=a1*b2-a2*b1;
    double dx=b1*c2-b2*c1;
    double dy=c1*a2-c2*a1;
    x=dx/d; y=dy/d;
}

bool pointOnLine(double x1, double y1, double x2, double y2, double xt, double yt){
    if(x1>x2) swap(x1,x2);
    if(y1>y2) swap(y1,y2);
    return x1-1e-9<=xt && xt<=x2+1e-9 && y1-1e-9<=yt && yt<=y2+1e-9;
}

double calc(double rad){
    double totalArea=0, A=0, B=0;
    for(int i=1; i<=n; ++i){
        int j=i+1;
        if(j>n) j=1;
        A+=x[i]*y[j];
        B+=y[i]*x[j];
    }
    totalArea = abs(A-B)*0.5;

    double xm, ym;
    xm = cos(rad)*x[2] - sin(rad)*y[2];
    ym = sin(rad)*x[2] + cos(rad)*y[2];
    double a=ym, b=-xm, c=0;

    double leftArea = 0;
    for(int i=2; i<n; ++i){
        double a2=y[i+1]-y[i], b2=x[i]-x[i+1], c2=-a2*x[i]-b2*y[i];
        double xt,yt;
        giaiHpt(a,b,c,a2,b2,c2,xt,yt);
        if(pointOnLine(x[i],y[i],x[i+1],y[i+1],xt,yt)){
            leftArea += area(x[1],y[1],x[i],y[i],xt,yt);
            break;
        }else
            leftArea += area(x[1],y[1],x[i],y[i],x[i+1],y[i+1]);
    }

    double rightArea = totalArea-leftArea;
    return rightArea - leftArea;

}



int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        printf("Case %d:\n",tt);
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%lf%lf",&x[i],&y[i]);
        double rad = atan2(y[n],x[n]) - atan2(y[2],x[2]);
        if(rad<0) rad += 2*PI;
        if(rad>=PI) rad = 2*PI - rad;
        double l=0, r=rad;
        for(int i=0; i<100; ++i){
            double mid=(l+r)/2;
            double area=calc(mid);
            if(area>0){
                l=mid;
            }else r=mid;
        }

        double res=(l+r)/2 + atan2(y[2],x[2])+PI/2;
        for(int i=1; i<=n; ++i){
            double xm, ym;
            xm = cos(-res)*x[i] - sin(-res)*y[i];
            ym = sin(-res)*x[i] + cos(-res)*y[i];
            if(xm<=0 && xm>=-1e-9) xm=1e-9;
            if(ym<=0 && ym>=-1e-9) ym=1e-9;
            printf("%0.6f %0.6f\n",xm,ym);
        }
    }
}

