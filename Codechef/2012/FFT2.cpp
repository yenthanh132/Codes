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
#include <valarray>
#include <complex>
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
typedef complex<double> Complex;
typedef valarray<Complex> Carr;

const double pi=acos(-1);
void fft(Carr &a, int flag){
    int n=sz(a);
    if(n==1) return;
    Carr even = a[slice(0,n/2,2)];
    Carr odd = a[slice(1,n/2,2)];
    fft(even,flag); fft(odd,flag);
    REP(k,n/2){
        Complex w=polar(1.0,flag*2*pi*k/n) * odd[k];
        a[k]=even[k]+w;
        a[k+n/2]=even[k]-w;
    }
}

#include <conio.h>

int main(){
    Complex a[] = {1,4,2,0,0,0,0,0};
    Complex b[] = {1,0,0,0,0,0,0,0};
    Carr x(a,8), y(b,8);
    fft(x,1); fft(y,1);
    REP(i,8) x[i]=x[i]*y[i];
    fft(x,-1);
    REP(i,8) x[i]/=8;
    REP(i,8) printf("%d\n",int(real(x[i])+0.5));
    getch();
    return 0;
}
