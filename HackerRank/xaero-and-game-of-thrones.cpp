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

int n,m,k,b;
int value[maxn],cost[maxn];
vector<int> toLeft[maxn],toRight[maxn];
int toR[maxn];
multiset<int> mys;
int IT[maxn*4];

ll dp[maxn][501];

void setValue(int i, int l, int r, int s, int f, int v){
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        IT[i]=min(IT[i],v);
        return;
    }
    int mid=(l+r)/2;
    setValue(i*2,l,mid,s,f,v); setValue(i*2+1,mid+1,r,s,f,v);
}

void fillValue(int i, int l, int r, int minValue){
    minValue = min(minValue,IT[i]);
    if(l==r){
        cost[l] = minValue;
        return;
    }
    int mid=(l+r)/2;
    fillValue(i*2,l,mid,minValue);
    fillValue(i*2+1,mid+1,r,minValue);
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&k,&b);
    for(int i=1; i<=n; ++i) scanf("%d",&value[i]);
    for(int i=0; i<m; ++i){
        int l,r;
        scanf("%d%d",&l,&r);
        toRight[l].pb(r);
        toLeft[r].pb(l);
    }

    mys.clear();
    for(int u=n; u>=1; --u){
        for(int i=0; i<sz(toLeft[u]); ++i)
            mys.insert(-u);
        if(mys.empty()) toR[u]=u;
        else toR[u]=-*mys.begin();
        for(int i=0; i<sz(toRight[u]); ++i)
            mys.erase(mys.find(-toRight[u][i]));
    }

    reset(IT,63);

    for(int i=1; i<=k; ++i){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        setValue(1,1,n,l,r,c);
    }

    fillValue(1,1,n,oo);

    reset(dp,-1);
    dp[0][0]=0;
    for(int i=1; i<=n; ++i) for(int v=0; v<=b; ++v) if(dp[i-1][v]!=-1){
        dp[i][v]=max(dp[i][v],dp[i-1][v]);
        if(v+cost[i]<=b)
            dp[toR[i]][v+cost[i]] = max(dp[toR[i]][v+cost[i]], dp[i-1][v] + value[i]);
    }
    ll res=0;
    for(int v=0; v<=b; ++v) res=max(res, dp[n][v]);
    printf("%lld\n",res);
}

