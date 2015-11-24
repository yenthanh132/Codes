#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=5007;

pii a[maxn];
int dp[maxn];
int n;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    dp[0]=0;
    for(int i=1; i<=n; ++i){
        dp[i]=a[i].first;
        if(dp[i-1]<=a[i].second) dp[i]=a[i].second;
    }
    cout<<dp[n]<<endl;
}

