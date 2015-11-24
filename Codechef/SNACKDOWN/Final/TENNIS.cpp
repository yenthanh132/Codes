#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int T,n,m,cnt;
double p;

double dp[8][66][66];
int mark[8][66][66];
double C[222][222];

double f(int round, int n, int m){
    if(m==0) return 0;
    if(n==0) return 1;
    if(round==1) return p;
    if(mark[round][n][m]==cnt) return dp[round][n][m];
    mark[round][n][m]=cnt;
    double &res = dp[round][n][m];
    res = 0;
    int total=(n+m)/2;
    for(int n1=0; n1<=n; ++n1){
        int m1=total-n1;
        if(0<=m1 && m1<=m){
            double v1 = f(round-1,n1,m1);
            double v2 = f(round-1,n-n1,m-m1);
            double x = C[n1+m1][n1] * C[n-n1+m-m1][n-n1] / C[n+m][n];
            res += (v1*v2 + v1*(1-v2)*p + (1-v1)*v2*p) * x;
        }
    }
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    C[0][0]=1;
    for(int i=1; i<=150; ++i){
        C[i][0]=1;
        for(int j=1; j<=i; ++j) C[i][j]=C[i-1][j]+C[i-1][j-1];
    }

    cin>>T;
    reset(mark,0);
    cnt=0;

    while(T--){
        cin>>n>>m>>p;
        int x=n+m,y=0;
        while(x>1){
            x/=2;
            ++y;
        }

        cnt++;
        printf("%0.9f\n",f(y,n,m));
    }
}

