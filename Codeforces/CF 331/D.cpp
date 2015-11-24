#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const double eps=1e-9;

double dp[2111][2111][2][2],P;
int n,x[2111],h;

int goLeft[2111],goRight[2111];

int getGoLeft(int i){
    if(goLeft[i]!=-1) return goLeft[i];
    int &p=goLeft[i];
    p=i;
    while(p>1 && x[p-1]+h>x[p]) --p;
    return p;
}

int getGoRight(int i){
    if(goRight[i]!=-1) return goRight[i];
    int &p=goRight[i];
    p=i;
    while(p<n && x[p]+h>x[p+1]) ++p;
    return p;
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>h>>P;
    for(int i=1; i<=n; ++i) cin>>x[i];
    sort(x+1,x+n+1);
    reset(dp,0); reset(goLeft,-1); reset(goRight,-1);
    dp[1][n][0][0]=1;
    double res = 0;
    x[0]=-oo;
    x[n+1]=+oo;
    for(int len=n; len>=1; --len) for(int i=1; i<=n-len+1; ++i){
        int j=i+len-1;
        for(int vl=0; vl<2; ++vl) for(int vr=0; vr<2; ++vr){
            int leftBound = x[i-1];
            if(vl) leftBound = x[i-1]+h;
            int rightBound = x[j+1];
            if(vr) rightBound = x[j+1]-h;
            //choose left
            {
                //fall left
                int len = x[i] - max(leftBound, x[i]-h);
                res += len * (dp[i][j][vl][vr]*0.5*P);
                dp[i+1][j][0][vr] += dp[i][j][vl][vr]*0.5*P;

                //fall right
                int p=getGoRight(i);
                len = min(rightBound,x[p]+h)-x[i];
                res += len * (dp[i][j][vl][vr]*0.5*(1-P));
                dp[p+1][j][1][vr] += dp[i][j][vl][vr]*0.5*(1-P);
            }

            //chose right
            {
                //fall right
                int len = min(rightBound,x[j]+h) - x[j];
                res += len * (dp[i][j][vl][vr]*0.5*(1-P));
                dp[i][j-1][vl][0] += dp[i][j][vl][vr]*0.5*(1-P);

                //fall left
                int p=getGoLeft(j);
                len = x[j] - max(leftBound,x[p]-h);
                res += len * (dp[i][j][vl][vr]*0.5*P);
                dp[i][p-1][vl][1] += dp[i][j][vl][vr]*0.5*P;
            }
        }
    }

    printf("%0.9f\n",res);
}

