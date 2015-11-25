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


//This implementation is a reference at URL: 
//http://www.drdobbs.com/go-parallel/article/print?articleId=199500857&siteSectionName=

//Super fast FFT :D -- T7

template<unsigned M, unsigned N, unsigned B, unsigned A>
struct SinCosSeries {
   static double value() {
      return 1-(A*M_PI/B)*(A*M_PI/B)/M/(M+1)
               *SinCosSeries<M+2,N,B,A>::value();
   }
};

template<unsigned N, unsigned B, unsigned A>
struct SinCosSeries<N,N,B,A> {
   static double value() { return 1.; }
};

template<unsigned B, unsigned A, typename T=double>
struct Sin;

template<unsigned B, unsigned A>
struct Sin<B,A,float> {
   static float value() {
      return (A*M_PI/B)*SinCosSeries<2,24,B,A>::value();
   }
};
template<unsigned B, unsigned A>
struct Sin<B,A,double> {
   static double value() {
      return (A*M_PI/B)*SinCosSeries<2,34,B,A>::value();
   }
};

template<unsigned B, unsigned A, typename T=double>
struct Cos;

template<unsigned B, unsigned A>
struct Cos<B,A,float> {
   static float value() {
      return SinCosSeries<1,23,B,A>::value();
   }
};
template<unsigned B, unsigned A>
struct Cos<B,A,double> {
   static double value() {
      return SinCosSeries<1,33,B,A>::value();
   }
};

template<unsigned N, typename T=double>
class DanielsonLanczos {
   DanielsonLanczos<N/2,T> next;
public:
   void apply(T* data,bool rev) {
      next.apply(data,rev);
      next.apply(data+N,rev);

      T wtemp,tempr,tempi,wr,wi,wpr,wpi;
      wtemp = -Sin<N,1,T>::value();
      wpr = -2.0*wtemp*wtemp;
      wpi = -Sin<N,2,T>::value();
      wr = 1.0;
      wi = 0.0;
      for (register unsigned i=0; i<N; i+=2) {
        tempr = data[i+N]*wr - data[i+N+1]*wi;
        tempi = data[i+N]*wi + data[i+N+1]*wr;
        data[i+N] = data[i]-tempr;
        data[i+N+1] = data[i+1]-tempi;
        data[i] += tempr;
        data[i+1] += tempi;

        wtemp = wr;
        wr += wr*wpr - wi*wpi;
        wi += wi*wpr + wtemp*wpi;
      }
   }
};
 
template<typename T>
class DanielsonLanczos<1,T> {
public:
   void apply(T* data, bool rev) { }
};

template<unsigned P,
         typename T=double>
class GFFT {
   enum { N = 1<<P };
   DanielsonLanczos<N,T> recursion;
public:
    inline void scramble(T* data, unsigned int nn){
        register unsigned int n, j, i, m;
        n = nn<<1;
        j=1;
        for (i=1; i<n; i+=2) {
            if (j>i) {
                swap(data[j-1], data[i-1]);
                swap(data[j], data[i]);
            }
            m = nn;
            while (m>=2 && j>m) {
                j -= m;
                m >>= 1;
            }
            j += m;
        };        
    }
    void fft(T* data, bool rev) {
      scramble(data,N);
      recursion.apply(data, rev);
    }
};

template<typename T>
inline void ComplexMulti(T* r, T* p1, T* p2, unsigned int nn){
    unsigned int n=nn<<1;
    for(register unsigned int i=0;i<n;i+=2){
        r[i]=p1[i]*p2[i]-p1[i+1]*p2[i+1],
        r[i+1]=p1[i]*p2[i+1]+p1[i+1]*p2[i];
    }
}

//--------------------------------------------------------------


template<typename T>
void read(T& x){
    int c;
    bool isNega;
    isNega=0;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}

const int BITLEN=18;
const int M=1<<BITLEN;
GFFT<BITLEN,double> myfft;
double a[M*2],b[M*2],c[M*2];
int cnt[M],n;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    read(n);
    int v;
    FOR(i,1,n){
        read(v);
        a[(v+50000)*2]+=1;
    }
    FOR(i,1,n){
        read(v);
        b[(v+50000)*2]+=1;
    }
    FOR(i,1,n){
        read(v);
        cnt[v+100000]++;
    }
    myfft.fft(a,0); myfft.fft(b,0); 
    ComplexMulti(c,a,b,M);
    myfft.fft(c,1); 
    
    ll res=0;
    FOR(i,0,M) res+=(long long)(c[i*2]/M+0.1)*cnt[M-i];
    
    cout<<res<<endl;
    
    //cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    //getch();
    return 0;
}
