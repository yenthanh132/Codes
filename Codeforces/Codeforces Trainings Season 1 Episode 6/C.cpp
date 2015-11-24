#include <conio.h>
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

const double PI=acos(-1.0);
double x,y,d,a1,b1,c1,a2,b2,c2;

void process(double x, double y, double d, double &a, double &b, double &c){
    if(d<=90) d=90-d;
    else d=360-(d-90);
    d=d/180*PI;
    a=sin(d);
    b=-cos(d);
    c=-x*a-y*b;
}

void giaihpt(double &x, double &y){
    double d=a1*b2-a2*b1;
    double dx=b1*c2-b2*c1;
    double dy=c1*a2-c2*a1;
    x=dx/d; y=dy/d;   
}

int main(){
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%lf%lf%lf",&x,&y,&d);
        process(x,y,d,a1,b1,c1);
        scanf("%lf%lf%lf",&x,&y,&d);
        process(x,y,d,a2,b2,c2);
        giaihpt(x,y);
        printf("%0.4lf %0.4lf\n",x,y);
    }
    //getch();
    return 0;
}
