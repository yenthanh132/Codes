#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

char s[111];
int n,m;
int dp[2][111][111];
int main(){
//    freopen("input.txt","r",stdin);
    scanf("%s",s+1); n=strlen(s+1);
    scanf("%d",&m);
    for(int i=0; i<=n; ++i) for(int j=0; j<=n; ++j) dp[0][i][j]=dp[1][i][j]=-oo;
    dp[0][0][0]=dp[1][0][0]=0;
    for(int i=1; i<=n; ++i) for(int j=0; j<=min(m,i); ++j){
        if(s[i]=='F'){
            dp[0][i][j]=max(dp[0][i][j], dp[0][i-1][j]+1);
            if(j>0) dp[0][i][j]=max(dp[0][i][j], dp[1][i-1][j-1]);

            dp[1][i][j]=max(dp[1][i][j], dp[1][i-1][j]-1);
            if(j>0) dp[1][i][j]=max(dp[1][i][j], dp[0][i-1][j-1]);
        }else{
            dp[0][i][j]=max(dp[0][i][j], dp[1][i-1][j]);
            if(j>0) dp[0][i][j]=max(dp[0][i][j], dp[0][i-1][j-1]+1);

            dp[1][i][j]=max(dp[1][i][j], dp[0][i-1][j]);
            if(j>0) dp[1][i][j]=max(dp[1][i][j], dp[1][i-1][j-1]-1);
        }
    }
    int res=-oo;
    for(int j=m; j>=0; j-=2) res = max(res, max(dp[0][n][j], dp[1][n][j]));
    cout<<res<<endl;

}

