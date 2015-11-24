#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000000007ll

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,k,a[333333],c1,c2,len;
ll dp[5555][5555];

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    dp[0][0]=0;
    c2=n%k;
    c1=k-c2;
    len=n/k;
    for(int i=0; i<=c1; ++i) for(int j=0; j<=c2; ++j) if(i>0 || j>0){
        //i-1, j
        dp[i][j]=oo;
        if(i>0){
            int x=(i-1)*len + j*(len+1)+1;
            int y=x+len-1;
            dp[i][j]=min(dp[i][j],dp[i-1][j]+a[y]-a[x]);
        }
        if(j>0){
            int x=i*len + (j-1)*(len+1) + 1;
            int y=x+len;
            dp[i][j]=min(dp[i][j], dp[i][j-1]+a[y]-a[x]);
        }
    }
    cout<<dp[c1][c2]<<endl;
}

