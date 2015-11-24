#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=500007;

bool isCv[maxn];
int go[maxn],n,ds[maxn],cnt;
int deg[maxn];
int myq[maxn],first,last;
bool mark[maxn];
int dp[maxn][2];

int main(){
    //freopen("input.txt","r",stdin);
    reset(deg,0); reset(isCv,0); reset(mark,1);
    scanf("%d",&n);
    for(int i=1,v; i<=n; ++i){
        scanf("%d",&v);
        go[i]=v;
        deg[v]++;
    }
    first=1; last=0;
    for(int u=1; u<=n; ++u) if(deg[u]==0) myq[++last]=u;
    int res = 0;
    while(first<=last){
        int u=myq[first++], v=go[u];
        mark[u]=0;
        if(!isCv[u]) isCv[v]=1, ++res;
        --deg[v];
        if(deg[v]==0) myq[++last]=v;
    }

    for(int i=1; i<=n; ++i) if(mark[i]){
        ds[cnt=1]=i;
        mark[i]=0;

        int u=go[i];
        while(mark[u]){
            ds[++cnt]=u;
            mark[u]=0;
            u=go[u];
        }

        int ans = 0;
        for(int start=0; start<2; ++start){
            if(isCv[ds[1]] && start==1) continue;

            if(start==0){
                dp[1][0]=0;
                dp[1][1]=-oo;
            }else{
                dp[1][0]=-oo;
                dp[1][1]=1;
            }

            for(int j=2; j<=cnt; ++j){
                dp[j][0]=max(dp[j-1][0],dp[j-1][1]);
                if(isCv[ds[j]]) dp[j][1]=-oo; else dp[j][1]=dp[j-1][0]+1;
            }

            if(start==0) ans=max(ans, max(dp[cnt][0], dp[cnt][1]));
            else ans=max(ans, dp[cnt][0]);
        }

        res += ans;
    }

    cout<<res<<endl;
}

