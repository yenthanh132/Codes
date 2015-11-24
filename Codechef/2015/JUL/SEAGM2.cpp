#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=15;
const int maxm=10007;

int n,m;
double p[maxn][maxm];
long double win[maxn];

/*
p[1][1] * p[1][2] * p[1][3] * ...
-----------------------------------
p[1][1]*p[1][2]*p[1][3]*... + p[2][1]*p[2][2]*p[2][3]*... + ***
*/

int main(){
//    freopen("input.txt","r",stdin);

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                scanf("%lf",&p[i][j]);
            }
        }
        bool ok=1;
        for(int j=1; j<=m; ++j) if(p[1][j]==0){
            ok=0;
            break;
        }
        if(!ok){
            printf("%0.9f\n",0);
            continue;
        }

        long double res=0;
        for(int i=1; i<=n; ++i){
            long double val = 1;
            for(int j=1; j<=m; ++j){
                long double A = p[i][j];
                long double B = p[1][j];
                val *= (A/B);
            }
            res += val;
        }
        double res2 = 1.0/res;
        printf("%0.9f\n",res2);
    }
}

