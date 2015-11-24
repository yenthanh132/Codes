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

struct point{double x, y;};

point operator+(point a, point b){a.x+=b.x; a.y+=b.y; return a;}
point operator-(point a, point b){a.x-=b.x; a.y-=b.y; return a;}
point operator*(point a, point b){point c; c.x=a.x*b.x-a.y*b.y; c.y=a.x*b.y+a.y*b.x; return c;}
point newpoint(double r, double t){point c; c.x=r*cos(t); c.y=r*sin(t); return c;}

const double eps=1e-9;
const double pi=acos(-1);

void fft(int n, double theta, point a[]){
    point x,w;
    for(int m=n; m>1; m/=2){
        int len=m/2;
        REP(d,len){
            w=newpoint(1,theta*d);
            for(int i=d; i<n; i+=m){
                int j=i+len;
                x=a[i]-a[j];
                a[i]=a[i]+a[j];
                a[j]=w*x;
            }
        }
        theta*=2;
    }
    int i=0;
    FOR(j,1,n-1){
        for(int k=n/2; k>(i^=k); k/=2);
        if(j<i) swap(a[i],a[j]);
    }
}

point a[16],b[16];

#include <conio.h>
int main(){
    int n=16;
    point t;
    t.x=t.y=0;
    REP(i,n) a[i]=b[i]=t;
    a[0].x=1; a[1].x=2; a[2].x=3;
    b[1].x=2; b[2].x=1; b[3].x=5;

    fft(n,2.0*pi/n,a); 
    fft(n,2.0*pi/n,b);
    REP(i,n) a[i]=a[i]*b[i];
    fft(n,-2.0*pi/n,a);
    REP(i,n) a[i].x=a[i].x/n;
    REP(i,n) printf("%d ",int(a[i].x+eps));
    getch();
    return 0;
}
    
    
