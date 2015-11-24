#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


// FFT Implementation
const double pi = acos(-1);

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

//====================================

const int M = 262144;
point pa[M], pb[M];


const int maxn=100007;
const int LIMIT=10000;
const int BASE=100000;

vector<int> a[maxn];
map<int, int> mm;
int n,T,cnt,ans[maxn];

void add(int v, int i){
    int pos;
    if(mm.count(v)==0){
        mm[v] = ++cnt;
        pos = cnt;
        a[pos].clear();
    }else
        pos=mm[v];

    a[pos].pb(i);
}

void solve(int idx){
    vector<int> &arr = a[idx];
    if(sz(arr)<=LIMIT){
        for(int i=0; i<sz(arr); ++i) for(int j=i+1; j<sz(arr); ++j)
            ++ans[arr[j]-arr[i]];
    }else{
        for(int i=0; i<M; ++i){
            pa[i].x=0;
            pa[i].y=0;
            pb[i].x=0;
            pb[i].y=0;
        }
        for(int i=0; i<sz(arr); ++i){
            pa[arr[i]].x=1;
            pb[BASE - arr[i]].x=1;
        }
        fft(M, 2.0 * pi / M, pa);
        fft(M, 2.0 * pi / M, pb);
        for(int i=0; i<M; ++i) pa[i] = pa[i] * pb[i];
        fft(M, -2.0 * pi / M, pa);

        for(int i=BASE+1; i<=BASE+n; ++i){
            pa[i].x/=M;
            int v=int(pa[i].x+0.5);
            ans[i-BASE] += v;
        }
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        cnt=0;
        mm.clear();
        add(0,0);
        int x=0,v;
        for(int i=1; i<=n; ++i){
            scanf("%d",&v);
            x^=v;
            add(x,i);
        }

        for(int i=1; i<=n; ++i) ans[i]=0;
        for(int i=1; i<=cnt; ++i) solve(i);

        for(int i=1; i<=n; ++i) printf("%d ",ans[i]); puts("");
    }
}

