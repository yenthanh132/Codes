#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll dp[1<<18][18];
int n,m,k;
int a[18],cost[18][18];

void update(ll &a, ll b){
    a=max(a,b);
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; ++i) scanf("%d",a+i);
    reset(cost,0);
    for(int i=0; i<k; ++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        --u; --v;
        cost[u][v]=max(cost[u][v],w);
    }

    int cnt=1<<n;
    reset(dp,-1);
    for(int i=0; i<n; ++i) dp[1<<i][i]=a[i];
    ll res=0;
    for(int mask=0; mask<cnt; ++mask)
        for(int i=0; i<n; ++i) if(dp[mask][i]!=-1){
            int cbit=0;
            for(int j=0; j<n; ++j) if(!(mask>>j&1)){
                update(dp[mask|(1<<j)][j], dp[mask][i]+cost[i][j]+a[j]);
            }else{
                ++cbit;
            }
            if(cbit==m) res=max(res,dp[mask][i]);
        }

    cout<<res<<endl;

}

