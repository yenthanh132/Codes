#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const double JUMP=1e-4;

double x[5],y[5],minx,maxx;
double X,Y;
double R;

bool check(double xx, double &X, double &Y){
    double r=oo,l=-oo;
    for(int i=1; i<=3; ++i){
        double d=abs(xx-x[i])-1e-9;
        if(d>R) return 0;
        double delta=sqrt(sqr(R)-sqr(d));
        r=min(r,y[i]+delta);
        l=max(l,y[i]-delta);
    }
    if(l>r+1e-4) return 0;
    X=xx; Y=(l+r)/2;
    for(int i=1; i<=3; ++i)
        if(hypot(X-x[i],Y-y[i])>R+1e-3) return 0;
    return 1;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>R;
    for(int i=1; i<=3; ++i) cin>>x[i]>>y[i];
    minx=min(x[1],min(x[2],x[3]))-R;
    maxx=max(x[1],max(x[2],x[3]))+R;
    for(double xx=minx; xx<=maxx; xx+=JUMP){
        if(check(xx,X,Y)){
            puts("YES");
            printf("%0.12lf %0.12lf\n",X,Y);
            return 0;
        }
    }
    if(check(maxx,X,Y)){
        puts("YES");
        printf("%0.12lf %0.12lf\n",X,Y);
        return 0;
    }

    puts("NO");
}

