#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxm=107;
const int maxn=10007;
const int M=40;
const int N=10000;
int T,n,m;
vector<pii> res;
int dp[maxm][maxn],ta[maxm][maxn],tb[maxm][maxn];

ll mypow(int base, int n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    if(t>=oo) return oo;
    t=t*t;
    if(t>=oo) return oo;
    if(n&1){
        t=t*base;
        if(t>=oo) return oo;
        return t;
    }
    return t;
}

int getpow(int base, int n, int m){
    int l=1, r=m, mid, res=0;
    while(l<=r){
        mid=(l+r)/2;
        int v=mypow(base,mid);
        if(v<=n){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return res;
}

int getlog(int p, int n, int m){
    int l=1, r=m, mid, res;
    while(l<=r){
        mid=(l+r)/2;
        int v=mypow(mid,p);
        if(v<=n){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return res;
}


pii get(int n, int m){
    if(2<=m && m<=M+60 && n<=N){
        return pii(ta[min(m,M)][n],tb[min(m,M)][n]);
    }

    int vmax=-1,a,b;
    for(int i=1; i<=min(30,min(m,n)); ++i){
        int res=getpow(i,n,m);
        if(res==0) continue;
        int v=mypow(i,res);
        if(v>vmax){
            vmax=v;
            a=i; b=res;
        }
    }
    for(int i=min(m,n); i>=min(m,n)-30 && i>=1; --i){
        int res=getpow(i,n,m);
        if(res==0) continue;
        int v=mypow(i,res);
        if(v>vmax){
            vmax=v;
            a=i; b=res;
        }
    }
    for(int i=1; i<=min(30,min(m,n)); ++i){
        int res=getlog(i,n,m);
        int v=mypow(res,i);
        if(v>vmax){
            vmax=v;
            a=res; b=i;
        }
    }
    return pii(a,b);
}

void solve(){
    res.clear();
    int n2=n;
    while(n){
        pii x=get(n,m);
        res.pb(x);
        n-=mypow(x.first,x.second);
    }
    n=n2;
    if(2<=m && n<=N && sz(res)>dp[min(M,m)][n]){
        res.clear();
        while(n){
            pii x=pii(ta[min(M,m)][n], tb[min(M,m)][n]);
            n-=mypow(x.first,x.second);
            res.pb(x);
        }
    }
    printf("%d\n",sz(res));
    for(int i=0; i<sz(res); ++i) printf("%d ",res[i].first); puts("");
    for(int i=0; i<sz(res); ++i) printf("%d ",res[i].second); puts("");
}

//dp for small m

void init(){
    for(int m=2; m<=M; ++m){
        dp[m][0]=0;
        for(int n=1; n<=N; ++n){
            dp[m][n]=oo;
            for(int a=1; a<=m; ++a){
                int b=getpow(a,n,m);
                int v=mypow(a,b);
                if(dp[m][n]>dp[m][n-v]+1){
                    dp[m][n]=dp[m][n-v]+1;
                    ta[m][n]=a;
                    tb[m][n]=b;
                }
            }
        }
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        solve();
    }
}

