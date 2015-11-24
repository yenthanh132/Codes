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
int myq[2][maxn], n, a,b,k;
ll dp[2][maxn];
ll d[maxn];
int cnt[2],mark[maxn];

void update(int l, int r, ll v){
    if(l>r) return;
    if(l<1) l=1;
    d[l]=(d[l]+v)%oo;
    mark[l]++;
    if(r<n){
        d[r+1] = (d[r+1] + (oo-v))%oo;
        mark[r+1]--;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d%d",&n,&a,&b,&k);
    reset(dp,0);
    cnt[0]=1;
    myq[0][1]=a;
    dp[0][a]=1;
    int flag=0;
    for(int i=0; i<k; ++i){
        for(int v=1; v<=n; ++v) d[v]=0, mark[v]=0, dp[1^flag][v]=0;
        for(int j=1; j<=cnt[flag]; ++j){
            int x=myq[flag][j];
            int len=abs(x-b)-1;
            update(x-len,x-1,dp[flag][x]);
            update(x+1,x+len,dp[flag][x]);
        }
        cnt[1^flag]=0;
        ll val=0;
        for(int v=1, xx=0; v<=n; ++v){
            val = (val + d[v] + oo )%oo;
            xx+=mark[v];
            if(xx>0){
                myq[1^flag][++cnt[1^flag]]=v;
                dp[1^flag][v]=val;
            }
        }
        flag^=1;
    }
    ll res=0;
    for(int i=1; i<=n; ++i) res = (res +dp[flag][i]+oo)%oo;
    cout<<res<<endl;
}

