#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1e18

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=555;

int x[maxn],y[maxn];
int n,T;
double dp[maxn][maxn];

double dis(int i, int j){
    return hypot(x[i]-x[j],y[i]-y[j]);
}

void gmin(double &x, double y){
    if(x>y) x=y;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d%d",&x[i],&y[i]);
        for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) dp[i][j]=oo;
        dp[1][1]=0;
        for(int i=1; i<=n; ++i) for(int j=i; j<=n; ++j) if(dp[i][j]<oo){
            if(i<j){
                gmin(dp[j][j], dp[i][j]+dis(i,j));
                if(j<n) gmin(dp[j][j+1],dp[i][j]+dis(i,j+1));
                if(j<n) gmin(dp[i][j+1],dp[i][j]+dis(j,j+1));
                gmin(dp[i+1][j],dp[i][j]+dis(i,i+1));
            }else{
                if(j<n) gmin(dp[i][j+1], dp[i][j]+dis(j,j+1));
            }
        }
        printf("%0.9f\n",dp[n][n]);
    }
}

