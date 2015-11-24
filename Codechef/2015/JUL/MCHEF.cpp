#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

int n,a[maxn],m,k;
int mark[207][maxn];
ll dp[2][507],total;

int main(){
//    freopen("input.txt","r",stdin);

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&k,&m);
        total=0;
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]), total += a[i];
        for(int v=1; v<=200; ++v) for(int i=1; i<=n; ++i) mark[v][i] = 0;
        for(int i=0; i<m; ++i){
            int l,r,c;
            scanf("%d%d%d",&l,&r,&c);
            mark[c][l]++;
            mark[c][r+1]--;
        }
        for(int v=1; v<=200; ++v){
            int s=0;
            for(int i=1; i<=n; ++i){
                s+=mark[v][i];
                if(s>0) mark[v][i]=1;
                else mark[v][i]=0;
            }
        }
        reset(dp,0);
        int flag=0;
        for(int i=1; i<=n; ++i){
            flag^=1;
            int cost=oo;
            for(int v=1; v<=200; ++v) if(mark[v][i]){
                cost=v;
                break;
            }
            for(int j=0; j<=k; ++j){
                dp[flag][j]=dp[flag^1][j];
                if(a[i]<0 && j>=cost) dp[flag][j]=max(dp[flag][j],dp[flag^1][j-cost]-a[i]);
            }
        }
        ll best=0;
        for(int j=0; j<=k; ++j) best=max(best,dp[flag][j]);
        printf("%lld\n",total+best);
    }
}

