#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxv=2007;

ll c1[maxv],c2[maxv],dp[maxv][maxv],val[maxv];
int n,m,c;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1; i<=n; ++i){
        int v;
        scanf("%d",&v);
        ++c1[v];
    }

    for(int i=1; i<=m; ++i){
        int v;
        scanf("%d",&v);
        ++c2[v];
    }

    for(int i=1; i<=c; ++i) dp[0][i]=c1[i]*c2[i]%oo;
    for(int d=1; d<=c; ++d){
        ll sum=0;
        for(int j=1; j<=c; ++j){
            dp[d][j]=sum*c1[j]%oo*c2[j]%oo;
            val[d]+=dp[d][j];
            val[d]%=oo;
            sum+=dp[d-1][j];
            sum%=oo;
        }
    }
    for(int i=1; i<=c; ++i) printf("%lld ",val[i]);
}

