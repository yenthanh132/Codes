#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef long long ll;

const ll val=1000000000;

int T,M;
double p;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%lf",&M,&p);
        double res=0;
        if(M&1) res = val * (1 + pow(p,M))/(1+p);
        else res = val * (1 - pow(p,M))/(1+p);
        printf("%0.9f %0.9f\n",res, val-res);
    }
}

