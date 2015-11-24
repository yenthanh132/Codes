#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;
const double eps=1e-9;

int T,n;
double V,X,r[maxn],c[maxn];

bool equal(double a, double b){
    return fabs(a-b)<eps;
}

bool ebig(double a, double b){
    return equal(a,b) || a>b;
}

double cal(int i, int j){
    double v1 = V*(X-c[j])/(c[i]-c[j]);
    return max(v1/r[i],(V-v1)/r[j]);
}

int main(){
freopen("input.txt","r",stdin);
//    freopen("B-small-attempt4.in","r",stdin);
//    freopen("B-small-attempt4.out","w",stdout);
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){

        scanf("%d%lf%lf",&n,&V,&X);
        double minc = oo, maxc = -oo;
        double res = oo;
        double sumr = 0;
        for(int i=1; i<=n; ++i){
            scanf("%lf%lf",&r[i],&c[i]);
            minc = min(minc, c[i]);
            maxc = max(maxc, c[i]);
            if(equal(c[i],X)) sumr += r[i];
        }
        if(sumr>0) res = min(res, V/sumr);

        for(int i=1; i<=n; ++i)
            for(int j=i+1; j<=n; ++j) res=min(res, cal(i,j));

        printf("Case #%d: ",tt);
        if(ebig(X,minc) && ebig(maxc,X)){
            printf("%0.9f\n",res);
        }else puts("IMPOSSIBLE");
    }
}

