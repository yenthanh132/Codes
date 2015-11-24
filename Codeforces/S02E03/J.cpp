#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


struct point{ double x,y;};
point operator+(point a, point b){a.x+=b.x; a.y+=b.y; return a;}
point operator-(point a, point b){a.x-=b.x; a.y-=b.y; return a;}
point operator*(point a, point b){point c; c.x=a.x*b.x-a.y*b.y; c.y=a.x*b.y+a.y*b.x; return c;}
point newpoint(double r, double t){point c; c.x=r*cos(t); c.y=r*sin(t); return c;}

inline void fft(int n, double theta, point a[]){
    int m,len,i,j;
    point t,w;
    for(m=n; m>1; m/=2){
        len=m/2;
        for(int d=0; d<len; ++d){
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
    for(int j=1; j<=n-1; ++j){
        for(int k=n/2; k>(i^=k); k/=2);
        if(j<i) swap(a[i],a[j]);
    }
}

const int M=1048576;
const double pi=acos(-1);

point a[M],b[M],c[M];
int n;
ll cnt[M],cnt2[M];

int main(){
    cin>>n;

    for(int i=1; i<n; ++i){
        ll v=1ll*i*i%n;
        a[v].x+=1;
        cnt[v]++;
    }
    ll res=0;

//    for(int i=1; i<=n*2; ++i) cout<<b[i].x<<' '; cout<<endl;
//    for(int i=1; i<n; ++i) for(int j=1; j<n; ++j) b[i+j].x += a[i].x*a[j].x;
//    for(int i=1; i<=n*2; ++i) cout<<b[i].x<<' '; cout<<endl;
    //FFT
    fft(M,2.0*pi/M,a);
    for(int i=0; i<M; ++i) c[i]=a[i]*a[i];
    fft(M,-2.0*pi/M,c);
    for(int i=0; i<M; ++i) c[i].x/=M, cnt2[i%n]+=((int)(c[i].x+0.1));


//    for(int i=1; i<=n*2; ++i) printf("%0.0lf ",c[i].x+1e-9); cout<<endl;
    for(int i=0; i<n; ++i) res+=cnt[i]*cnt2[i];
    for(int i=1; i<n; ++i) res += cnt[(1ll*i*i*2)%n];
    cout<<res/2<<endl;

//    ll t=0;
//    for(ll i=1; i<n; ++i) for(ll j=i; j<n; ++j){
//        t+=cnt[(i*i+j*j)%n];
//    }
//    cout<<t<<endl;

}
