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
const double pi=acos(-1);

struct point{double x, y;};

point operator+(point a, point b){a.x+=b.x; a.y+=b.y; return a;}
point operator-(point a, point b){a.x-=b.x; a.y-=b.y; return a;}
point operator*(point a, point b){point c; c.x=a.x*b.x-a.y*b.y; c.y=a.x*b.y+a.y*b.x; return c;}
point newpoint(double r, double t){point c; c.x=r*cos(t); c.y=r*sin(t); return c;}

void fft(int n, double theta, point a[]){
    int m,len,i,j;
    point t,w;
    for(m=n; m>1; m/=2){
        len=m/2;
        REP(d,len){
            w=newpoint(1,theta*d);
            for(i=d; i<n; i+=m){
                j=i+len;
                t=a[i]-a[j];
                a[i]=a[i]+a[j];
                a[j]=w*t;
            }
        }
        theta*=2;
    }
    i=0;
    FOR(j,1,n-1){
        for(int k=n/2; k>(i^=k); k/=2);
        if(j<i) swap(a[i],a[j]);
    }
}

const int M=262144;
point a[M],b[M];
int c[M],n;

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    int v;
    scanf("%d",&n);
    REP(i,M) a[i].x=a[i].y=b[i].x=b[i].y=0;
    FOR(i,1,n){
        scanf("%d",&v);
        a[v+50000].x+=1;
    }
    FOR(i,1,n){
        scanf("%d",&v);
        b[v+50000].x+=1;
    }
    //FFT
    fft(M,2.0*pi/M,a);
    fft(M,2.0*pi/M,b);
    REP(i,M) a[i]=a[i]*b[i];
    fft(M,-2.0*pi/M,a);
    REP(i,M) a[i].x=a[i].x/M;
    //-----------------------
    FOR(i,1,n){
        scanf("%d",&v);
        c[v+100000]++;
    }
    ll res=0;
    REP(i,M) res+=((long long)(a[i].x+eps))*c[i];
    printf("%lld\n",res);
     cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    getch();
    return 0;
}
    
