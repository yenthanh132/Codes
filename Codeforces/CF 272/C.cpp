#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2007;

char s[maxn],p[maxn];
int n,m,f[maxn],dp[maxn][maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%s",s+1); n=strlen(s+1);
    scanf("%s",p+1); m=strlen(p+1);
    for(int i=1; i<=n; ++i){
        int cost=0;
        int x,j;
        for(j=i,x=1; j<=n && x<=m; ++j){
            if(s[j]==p[x]) ++x;
            else ++cost;
        }
        if(x>m) f[i]=cost; else f[i]=oo;
    }
    reset(dp,0);
    for(int i=1; i<=n; ++i) for(int j=0; j<i; ++j){
        dp[i+1][j+1]=max(dp[i][j],dp[i+1][j+1]);
        dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
        if(f[i]!=oo) dp[i+f[i]+m][j+f[i]] = max(dp[i+f[i]+m][j+f[i]],dp[i][j]+1);
    }
    for(int x=0; x<=n; ++x) printf("%d ",dp[n+1][x]);
}

