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
#define FOR(a,b,c) for (unsigned int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (unsigned int a=b;a>=c;a--)
#define REP(i,a) for(unsigned int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(unsigned int i=(a)-1; i>=0; --i)
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

template<typename T>
void readNumber(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}

const double pi=acos(-1);

struct point{double x, y;};

inline point operator+(point a, point b){a.x+=b.x; a.y+=b.y; return a;}
inline point operator-(point a, point b){a.x-=b.x; a.y-=b.y; return a;}
inline point operator*(point a, point b){point c; c.x=a.x*b.x-a.y*b.y; c.y=a.x*b.y+a.y*b.x; return c;}
inline point newpoint(double r, double t){point c; c.x=r*cos(t); c.y=r*sin(t); return c;}

inline void fft(unsigned int n, double theta, point a[]){
    unsigned int m,len,i,j;
    register point t,w;
    for(m=n; m>1; m>>=1){
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
        for(int k=n/2; k>(i^=k); k>>=1);
        if(j<i)swap(a[i],a[j]);
    }
}

const int M=131072;
point a[M],a2[M],b[M],c[M];
unsigned int cnt[M],n;

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    int v;
    readNumber(n);
    //REP(i,M) a[i].x=a[i].y=b[i].x=b[i].y=c[i].x=c[i].y=0;
    FOR(i,1,n){
        readNumber(v);
        a[v+50000].x+=1;
        a2[50000-v].x+=1;
    }
    FOR(i,1,n){
        readNumber(v);
        if(v>=0) b[v].x+=1; else c[abs(v)].x+=1;
    }
    reset(cnt,0);
    FOR(i,1,n){
        readNumber(v);
        cnt[v+50000]++;
    }
    
    ll res=0;
    //FFT
    fft(M,2.0*pi/M,a);
    fft(M,2.0*pi/M,a2);
    fft(M,2.0*pi/M,b);
    fft(M,2.0*pi/M,c);
    REP(i,M) b[i]=a[i]*b[i], c[i]=a2[i]*c[i];
    fft(M,-2.0*pi/M,b);
    fft(M,-2.0*pi/M,c);
    REP(i,100000) b[i].x=b[i].x/M, c[i].x=c[i].x/M;
    //-----------------------
    
    REP(i,100000){
        res+=(long long)(b[i].x+0.1)*cnt[i];
        res+=(long long)(c[i].x+0.1)*cnt[100000-i];
        if(b[i].x>1e-9) cout<<i<<' '<<b[i].x<<' '<<cnt[i]<<endl;
    }
    printf("%lld\n",res);
    cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    getch();
    return 0;
}
    




