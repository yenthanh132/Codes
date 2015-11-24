#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000000007ll

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxm=107;
const int maxk=507;

int cnt[maxm];
ll dp[maxm][maxk];
int n,m,k;

ll sum(ll n){
    return n*(n+1)/2;
}

ll calc(int n, int p){
    ++p; //part
    if(p>=n) return n;
    int a=n/p;
    int b=n%p;
    return sum(a+1)*b + sum(a)*(p-b);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    reset(cnt,0);
    for(int i=0,v; i<n; ++i){
        scanf("%d",&v);
        cnt[v]++;
    }

    dp[0][0]=0; for(int j=1; j<=k; ++j) dp[0][j]=oo;
    for(int i=1; i<=m; ++i) for(int j=0; j<=k; ++j){
        dp[i][j]=oo;
        if(j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]);
        for(int p=0; p<=j; ++p) dp[i][j]=min(dp[i][j], dp[i-1][j-p] + calc(cnt[i],p));
    }

    cout<<dp[m][k]<<endl;
}

