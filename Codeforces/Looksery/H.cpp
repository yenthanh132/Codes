#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

double a,b,c,d;

double minval(double a, double d, double x){
    double v=(a+x)*(d+x);
    v=min(v, (a+x)*(d-x));
    v=min(v, (a-x)*(d+x));
    v=min(v, (a-x)*(d-x));
    return v;
}

double maxval(double a, double d, double x){
    double v=(a+x)*(d+x);
    v=max(v, (a+x)*(d-x));
    v=max(v, (a-x)*(d+x));
    v=max(v, (a-x)*(d-x));
    return v;
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>a>>b>>c>>d;
    double l,r,mid;
    l=0; r=oo;
    for(int i=0; i<1000; ++i){
        mid=(l+r)/2;
        double v1min = minval(a,d,mid);
        double v1max = maxval(a,d,mid);
        double v2min = minval(b,c,mid);
        double v2max = maxval(b,c,mid);
        double tmin=max(v1min,v2min);
        double tmax=min(v1max,v2max);
        if(tmin<=tmax){
            r=mid;
        }else{
            l=mid;
        }
    }
    printf("%0.9f\n",(l+r)/2);
}

