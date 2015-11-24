#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2000007;
int f[maxn];

ll cal(ll a, ll b){
    if(a==b) return 0;
    int tmp=0;
    if(b%10==0){
        --b;
        ++tmp;
    }
    int lb[22];
    int n=0;
    while(b){
        ++n;
        lb[n]=b%10;
        b/=10;
    }
    ll r1 = 0, r2 = 0;
    int x=(n+1)/2;
    for(int i=x; i>=1; --i) r1=r1*10+lb[i];
    for(int i=x+1; i<=n; ++i) r2=r2*10+lb[i];
    ll res = r1+r2+tmp;
    if(r2<=1) --res;
    return res;
}

ll cal(ll n){
    ll res = 1;
    ll v=1;
    while(v*10<n){
        res+=cal(v,v*10-1)+1;
        v=v*10;
    }
    res+=cal(v,n);
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
//    f[1]=1;
//    for(int i=2; i<=1000000; ++i) f[i]=oo;
//    for(int i=1; i<1000000; ++i){
//        f[i+1]=min(f[i+1],f[i]+1);
//        int x=i,y=0;
//        while(x){
//            y=y*10+(x%10);
//            x/=10;
//        }
//        if(y<maxn && f[y] > f[i]+1) f[y]=f[i]+1;
//    }
    int T;
    ll v;
    scanf("%d",&T);
    for(int tt=1; tt<=T; ++tt){
        scanf("%lld",&v);
        printf("Case #%d: %d\n",tt,cal(v));
    }

}

