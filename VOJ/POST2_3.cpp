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

const double eps=1e-3;
const double pi=acos(-1);

struct point{double x, y;};

inline point operator+(point a, point b){a.x+=b.x; a.y+=b.y; return a;}
inline point operator-(point a, point b){a.x-=b.x; a.y-=b.y; return a;}
inline point operator*(point a, point b){point c; c.x=a.x*b.x-a.y*b.y; c.y=a.x*b.y+a.y*b.x; return c;}
inline point newpoint(double r, double t){point c; c.x=r*cos(t); c.y=r*sin(t); return c;}

const int M=131072;
const int lenbit=17;
point a[M],a2[M],b[M],c[M];
int cnt[M],cnt2[M],n;

int rev[M];

int reversebit(int v){
    int res=0;
    REP(i,lenbit) if((v>>i)&1) res|=1<<(lenbit-i-1);
    return res;
}

void init(){
    REP(i,M) rev[i]=reversebit(i);
}

point A[M];

inline void fft(int n, double theta, point a[]){
    REP(i,M) A[rev[i]]=a[i];
    int len,k;
    point w,t,wn,u;
    FOR(i,1,lenbit){
        len=1<<i;
        w=newpoint(1,theta/len);
        for(k=0; k<n; k+=len){
            wn=newpoint(1,0);
            REP(j,len/2){
                t=wn*A[k+j+len/2];
                u=A[k+j];
                A[k+j]=u+t;
                A[k+j+len/2]=u-t;
                wn=wn*w;
            }
        }
    }
    REP(i,M) a[i]=A[i];
}



#include <conio.h>
int main(){
    init();
    freopen("test.txt","r",stdin);
    int v;
    scanf("%d",&n);
    REP(i,M) a[i].x=a[i].y=b[i].x=b[i].y=c[i].x=c[i].y=0;
    FOR(i,1,n){
        scanf("%d",&v);
        a[v+50000].x+=1;
        a2[50000-v].x+=1;
    }
    FOR(i,1,n){
        scanf("%d",&v);
        if(v>=0) b[v].x+=1; else c[abs(v)].x+=1;
    }
    reset(cnt,0);
    FOR(i,1,n){
        scanf("%d",&v);
        cnt[v+50000]++;
        cnt2[50000-v]++;
    }
    
    ll res=0;
    //FFT
    fft(M,2.0*pi,a);
    fft(M,2.0*pi,a2);
    fft(M,2.0*pi,b);
    fft(M,2.0*pi,c);
    REP(i,M) b[i]=a[i]*b[i], c[i]=a2[i]*c[i];
    fft(M,-2.0*pi,b);
    fft(M,-2.0*pi,c);
    REP(i,100000) b[i].x=b[i].x/M, c[i].x=c[i].x/M;
    //-----------------------
    
    REP(i,100000){
        res+=(long long)(b[i].x+0.1)*cnt[i];
        res+=(long long)(c[i].x+0.1)*cnt2[i];
    }
    printf("%lld\n",res);
    cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    getch();
    return 0;
}
    


