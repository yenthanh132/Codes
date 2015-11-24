#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

//FFT

const double pi = acos(-1);
struct point{
    double x, y;
    point(){
        x=y=0;
    }
};
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
  for(j=1; j<=n-1; ++j) {
    for (int k = n / 2; k > (i ^= k); k >>= 1);
    if (j < i) swap(a[i], a[j]);
  }
}


//FFT
//fft(M, 2.0 * pi / M, a);
//fft(M, 2.0 * pi / M, b);
//REP(i, M) c[i] = a[i] * b[i];
//fft(M, -2.0 * pi / M, b) c[i].x = c[i].x / M;

//===================================
const int maxn=500007;

int n,m,k;
int sum[maxn];
char S[maxn],T[maxn];

const int M = 1<<19;
point a[M], b[M], c[M];

vector<int> cal(char ch){
    for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+(S[i]==ch);
    for(int i=0; i<M; ++i) a[i] = b[i] = point();
    for(int i=1; i<=n; ++i){
        int r=min(i+k,n);
        int l=max(0,i-k-1);
        if(sum[r]-sum[l]>0)
            a[i].x = 1;
    }
    for(int i=1; i<=m; ++i)
        if(T[i]==ch)
            b[m-i].x = 1;
    fft(M, 2.0 * pi / M, a);
    fft(M, 2.0 * pi / M, b);
    for(int i=0; i<M; ++i) c[i] = a[i] * b[i];
    fft(M, -2.0 * pi / M, c);
    vector<int> res;
    for(int i=m; i<=n; ++i){
       res.pb((int)(c[i].x/M + 0.1));
    }
    return res;
}
vector<int> vA, vC, vG, vT;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    scanf("%s%s",S+1,T+1);
    vA = cal('A');
    vC = cal('C');
    vG = cal('G');
    vT = cal('T');
    int res=0;
    for(int i=0; i<sz(vA); ++i)
        if(vA[i] + vC[i] + vG[i] + vT[i] == m) ++res;

    cout<<res<<endl;
}

