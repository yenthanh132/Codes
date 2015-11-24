#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1007;

int x[maxn],n,t;

int toR[maxn],dp[maxn];

int insect(int l1, int r1, int l2, int r2){
    int l=max(l1,l2);
    int r=min(r1,r2);
    return max(0,r-l+1);
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&x[i]),x[i]--;
        for(int i=1; i<n; ++i){
            int vmin=1, vmax=min(x[i],x[i+1]);
            toR[i]=n;
            for(int j=i+1; j<n; ++j){
                int vmin2=1, vmax2=min(x[j],x[j+1]);
                int new_vmax=min(x[j],x[j]-vmin+1);
                int new_vmin=max(1,x[j]-vmax+1);
                if(new_vmax < new_vmin || !insect(new_vmin,new_vmax,vmin2,vmax2)){
                    toR[i]=j;
                    break;
                }
                vmin = max(new_vmin,vmin2);
                vmax = min(new_vmax,vmax2);
            }
        }
        //for(int i=1; i<n; ++i) cout<<toR[i]<<' '; cout<<endl;
        for(int i=1; i<=n; ++i) dp[i]=oo;
        dp[1]=0;
        for(int i=1; i<n; ++i) if(dp[i]!=oo){
            for(int j=i+1; j<=toR[i]; ++j)
                dp[j]=min(dp[j],dp[i]+j-i+1);
        }
        cout<<dp[n]<<endl;
    }
}

