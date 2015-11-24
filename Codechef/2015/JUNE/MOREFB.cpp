#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 99991
#define LOOP 33330
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

/*
formula: f(x+y) = f(x-1)*f(y) + f(x)*f(y+1) ; f(i) = i-th fibonaci number
    f(-2) = -1; f(-1) = 1; f(0) = 0; f(1) = 1; f(2) = 1; f(3) = 2; ....

we already have f(x), f(x-1), now consider a[i] = y
    f(x+y) = f(x-1)*f(y)+f(x)*f(y+1)
    f(x+y-1) = f(x-1)*f(y-1)+f(x)*f(y)

DP here:
    k =
    [ f[a[i]-1] f[a[i]]   ]
    [ f[a[i]]   f[a[i]+1] ]

    => f(i,j) = [fib(x-1); fib(x)]

    f(i,0) = [1; 0]
    f(i,j) = f(i-1,j) + k*f(i-1,j-1)

    result is f(n,k)[fib(x)]

Fast calculation?
	
	the problem is simplified to: Calculate the sum of all multiplication of all elements in a k-combination of n numbers, for all k-combination
	
    FFT for the 2x2 matrix?
    a   b
    b   c
      x
    x   y
    y   z
      =
    a*x + b*y   [a*y + b*z]
    b*x + c*y   b*y + c*z

    => a*x
       b*x  b*y
            c*y  c*z
	=> Just do FFT 5 times :D

*/


const int maxn=50007;
const int SEGMENT_LENGTH = 500;
int a[maxn],f[maxn];
int n,k;

ll fib(int i){
    i%=LOOP;
    if(i<0) i+=LOOP;
    return f[i];
}

//FFT implementation
struct point{ double x, y; };
inline point operator+(point a, point b)
{ a.x += b.x; a.y += b.y; return a; }
inline point operator-(point a, point b)
{ a.x -= b.x; a.y -= b.y; return a; }
inline point operator*(point a, point b)
{ point c; c.x = a.x * b.x - a.y * b.y; c.y = a.x * b.y + a.y * b.x; return c; }
inline point newpoint(double r, double t)
{ point c; c.x = r * cos(t); c.y = r * sin(t); return c; }

void fft(unsigned int n, double theta, point a[]) {
  unsigned int m, len, i, j;
  register point t,w;
  for (m = n; m > 1; m >>= 1) {
    len = m / 2;
    for(int d=0; d<len; ++d){
      w = newpoint(1, theta * d);
      for (i = d; i < n; i += m) {
        j = i + len; t = a[i] - a[j];
        a[i] = a[i] + a[j]; a[j] = w * t;
      }
    } theta *= 2;
  } i = 0;
  for(j = 1; j < n; ++j){
    for (int k = n / 2; k > (i ^= k); k >>= 1);
    if (j < i) swap(a[i], a[j]);
  }
}

const int M = 65536;
const double PI = acos(-1);
point pa[M], pb[M], pc[M];

int MValue[maxn];
ll m1a[maxn],m1b[maxn],m1c[maxn],m2a[maxn],m2b[maxn],m2c[maxn];
ll m1[maxn],m2[maxn],m3[maxn],m4[maxn],m5[maxn];

void fast_mul(ll *arr1, ll *arr2, ll *ans, int MM){
    int Mx = MValue[MM];
    for(int i=0; i<Mx; ++i){
        pa[i].x = 0;
        pb[i].x = 0;
        pa[i].y = 0;
        pb[i].y = 0;
    }

    for(int i=0; i<=min(MM,k); ++i) pa[i].x = arr1[i], pb[i].x = arr2[i];
    fft(Mx, 2.0*PI/Mx, pa);
    fft(Mx, 2.0*PI/Mx, pb);
    for(int i=0; i<Mx; ++i) pa[i] = pa[i]*pb[i];
    fft(Mx,-2.0*PI/Mx, pa);
    for(int i=0; i<Mx; ++i) pa[i].x /= Mx;
    for(int i=0; i<=min(MM,k); ++i) ans[i] = ll(pa[i].x+0.5);
}



//Matrix 2x2 implementation
struct Mat{
    ll a,b,c;
};

Mat operator *(Mat m1, Mat m2){
    Mat m;
    m.a = (m1.a*m2.a + m1.b*m2.b)%oo;
    m.b = (m1.b*m2.a + m1.c*m2.b)%oo;
    m.c = (m1.b*m2.b + m1.c*m2.c)%oo;
    return m;
}

Mat operator +(Mat m1, Mat m2){
    m1.a = m1.a + m2.a;
    if(m1.a>oo) m1.a-=oo;
    m1.b = m1.b + m2.b;
    if(m1.b>oo) m1.b-=oo;
    m1.c = m1.c + m2.c;
    if(m1.c>oo) m1.c-=oo;
    return m1;
}


Mat dp[2][maxn];
Mat num[maxn], stackMatrix[51][maxn];
int countStack = 0;
int stackLength[51];

bool canReduce(){
    if(countStack<=1) return 0;
    int MM = stackLength[countStack-1];
    int MM2 = stackLength[countStack]; //maybe MM2 < MM
    return MM == MM2;
}

void reduceMatrix(){
    if(countStack<=1) return;

    int MM = stackLength[countStack-1];
    int MM2 = stackLength[countStack]; //maybe MM2 < MM
    Mat *arr1 = stackMatrix[countStack-1];
    Mat *arr2 = stackMatrix[countStack];

    for(int i=0; i<=MM+MM2; ++i){
        m1a[i] = (i<=MM?arr1[i].a:0);
        m1b[i] = (i<=MM?arr1[i].b:0);
        m1c[i] = (i<=MM?arr1[i].c:0);
        m2a[i] = (i<=MM2?arr2[i].a:0);
        m2b[i] = (i<=MM2?arr2[i].b:0);
        m2c[i] = (i<=MM2?arr2[i].c:0);
    }
    fast_mul(m1a, m2a, m1, MM+MM2); //a*x
    fast_mul(m1b, m2a, m2, MM+MM2); //b*x
    fast_mul(m1b, m2b, m3, MM+MM2); //b*y
    fast_mul(m1c, m2b, m4, MM+MM2); //c*y
    fast_mul(m1c, m2c, m5, MM+MM2); //c*z

    for(int i=0; i<=MM+MM2; ++i){
        arr1[i].a = (m1[i] + m3[i])%oo;
        arr1[i].b = (m2[i] + m4[i])%oo;
        arr1[i].c = (m3[i] + m5[i])%oo;
    }
    --countStack;
    stackLength[countStack] = MM+MM2;

//        cout<<"Reduce: "<<countStack<<" => ";
//        for(int i=1; i<=countStack; ++i) cout<<stackLength[i]<<' '; cout<<endl;
}

void pushMatrix(Mat *arr, int cnt){

    stackLength[++countStack] = cnt;

//        cout<<"Push: "<<countStack<<" => ";
//        for(int i=1; i<=countStack; ++i) cout<<stackLength[i]<<' '; cout<<endl;

    for(int i=0; i<=cnt; ++i) stackMatrix[countStack][i] = arr[i];

    while(canReduce()) reduceMatrix();

}


int main(){
//    freopen("input.txt","r",stdin);
    f[1]=1; f[2]=1;
    for(int i=3; i<=LOOP; ++i){
        f[i]=(f[i-1]+f[i-2])%oo;
    }
    f[0]=f[LOOP];



    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i){
        scanf("%d",&a[i]);
        a[i]%=LOOP;
    }

    {// build the MValue array for faster FFT
        int mul2=1;
        for(int i=1; i<=n; ++i){
            while(mul2 <= i) mul2*=2;
            MValue[i]=mul2;
        }
    }


    for(int i=1; i<=n; ++i){
        num[i].a = fib(a[i]-1);
        num[i].b = fib(a[i]);
        num[i].c = fib(a[i]+1);
    }

    int cnt=0;
    for(int i=1; i<=n; ++i){
        ++cnt;
        int flag = cnt&1;
        dp[flag][1] = num[i] + dp[flag^1][1];
        for(int j=2; j<=min(cnt,k); ++j){ //max 5000
            dp[flag][j] = dp[flag^1][j] + dp[flag^1][j-1]*num[i];
        }
        if(cnt==SEGMENT_LENGTH || i==n){
            dp[flag][0].a = dp[flag][0].c = 1;
            dp[flag][0].b = 0;
            pushMatrix(dp[flag],cnt);
            reset(dp,0);
            cnt=0;
        }
    }

    while(countStack > 1) reduceMatrix();
    cout<<stackMatrix[1][k].b<<endl;

}
