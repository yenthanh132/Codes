#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int xs,ys,xf,yf;
int vmax,T,vx,vy,wx,wy;

bool check(double t){
    double xt,yt;
    if(t<=T){
        xt = xs + vx*t;
        yt = ys + vy*t;
    }else{
        xt = xs + vx*T + wx*(t-T);
        yt = ys + vy*T + wy*(t-T);
    }
    double cost = hypot(xf-xt,yf-yt)/vmax;
    return cost < t + 1e-9;
}

int main(){
    cin>>xs>>ys>>xf>>yf;
    cin>>vmax>>T;
    cin>>vx>>vy>>wx>>wy;
    double l=0, r=oo, mid;
    for(int i=0; i<100 && r-l>1e-9; ++i){
        mid=(l+r)/2;
        if(check(mid)){
            r=mid;
        }else
            l=mid;
    }


    printf("%0.12f\n",r);
}

