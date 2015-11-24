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

const double eps=1e-11;

double yw,xb,yb,rad;

double cal(double xw){
    double len1=xb-xw, len2=xw;
    double yres=len2*(yw-yb)/len1;
    return yw-yres;
}

bool equal(double a, double b){
    return fabs(a-b)<eps;
}

bool bigger(double a, double b){
    return !equal(a,b) && a>b;
}

double sqr(double r){
    return r*r;
}

double dis(double x0, double y0, double x1, double y1, double x2, double y2){
    double a=y2-y1, b=x1-x2;
    return fabs(a*(x0-x1)+b*(y0-y1))/sqrt(sqr(a)+sqr(b));
}

//#include <conio.h>
int main(){
    double y1,y2;
    //freopen("test.txt","r",stdin);
    cin>>y1>>y2>>yw>>xb>>yb>>rad;
    yw-=rad;
    double l=0, r=xb,mid,res=oo;
    while(l+eps<r){
        mid=(l+r)/2;
        if(equal(cal(mid),y1+rad) || bigger(cal(mid),y1+rad)){
            res=mid;
            l=mid;
        }else r=mid;
    }

    if(!bigger(cal(res),y2-rad) && bigger(dis(0,y2,0,cal(res),res,yw),rad)){
        printf("%0.12lf",res);
    }else{
        cout<<-1<<endl;
    }
    //getch();
    return 0;
}
    
