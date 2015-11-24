#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

double angle[720];

int main(){
//    freopen("input.txt","r",stdin);
    double hline=0;
    for(int h=0; h<12; ++h){
        double mline=0;
        for(int m=0; m<60; ++m){
            angle[h*60+m]=min(abs(mline-hline), 360-abs(mline-hline));
            hline += 0.5;
            mline += 6;
        }
    }

    int T;
    scanf("%d",&T);
    while(T--){
        double a;
        scanf("%lf",&a);
        for(int h=0; h<12; ++h) for(int m=0; m<60; ++m)
            if(abs(angle[h*60+m]-a) < 1.0/120)
                printf("%02d:%02d\n",h,m);


    }
}

