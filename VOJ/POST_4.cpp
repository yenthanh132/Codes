#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

#ifndef M_PI
    #define M_PI 3.141592653589793238462643
#endif

const long maxPow=18;
const long absMax=1<<(maxPow-2);
long _cnt[2][2*absMax+1];
#define Cnt(i,x) _cnt[i][x+absMax]

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

////// template class Cos
// compile-time calculation of cos(A*M_PI/B) function

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
    inline void scramble(T* data, unsigned long nn){
        register unsigned long n, j, i, m;
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
inline void ComplexMulti(T* r, T* p1, T* p2, unsigned long nn){
    unsigned long n=nn<<1;
    for(register unsigned long i=0;i<n;i+=2){
        r[i]=p1[i]*p2[i]-p1[i+1]*p2[i+1],
        r[i+1]=p1[i]*p2[i+1]+p1[i+1]*p2[i];
    }
}

enum {pmaxPow=1<<(maxPow)};
GFFT<maxPow,double> fftC;
long N;
double A[1<<(maxPow+1)];
double B[1<<(maxPow+1)];
double AB[1<<(maxPow+1)];
long C[1<<(maxPow)];
#include <conio.h>
#include <iostream>
int main(){
    freopen("test.txt","r",stdin);
    readNumber(N);
    register long i,j,k,x;
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    for(i=0;i<N;i++) readNumber(x),A[(x+absMax)<<1]+=1.;
    for(i=0;i<N;i++) readNumber(x),B[(x+absMax)<<1]+=1.;
    for(i=0;i<N;i++) readNumber(x),C[(x+absMax)]++;
    fftC.fft(A,false);fftC.fft(B,false);
    ComplexMulti(AB,A,B,pmaxPow);
    fftC.fft(AB,true);
    for(i=0;i<(1<<(maxPow+1));i+=2) AB[i]/=pmaxPow;
    const long zzz=1<<(maxPow+1);
    register long long res=0;
    for(i=0+2*absMax,j=-absMax+absMax;j<=2*absMax;i+=2,j++)
        if(fabs(C[j])>1e-8) res+=1ll*(long)(AB[zzz-i]+.5f)*C[j];
       if(res>11435000000ll) exit(-1);
    printf("%lld\n",res);
    cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    getch();
    return 0;
}

