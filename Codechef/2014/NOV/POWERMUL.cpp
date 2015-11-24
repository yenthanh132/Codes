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
vector<int> p;
ll cnt[30][maxn];
ll f[maxn];
int T,M,N,Q;

ll mypow(ll base, ll n, int M){
    if(n==0) return 1;
    ll t=mypow(base,n/2,M);
    t=t*t%M;
    if(n&1) return t*base%M;
    return t;
}

int extended_euclid(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1, y = 0; return a; }
    else {
        int res = extended_euclid(b, a % b, x, y);
        int t = x; x = y; y = t - (a / b) * y;
        return res;
    }
}

ll invert(ll v, ll M){
    ll x,y;
    extended_euclid(v,M,x,y);
    return (x%M+M)%M;
}

ll query(int r){
    ll res = 1;
    for(int i=0; i<sz(p); ++i){
        ll c = cnt[i][N]-cnt[i][r]-cnt[i][N-r];
        res = res * mypow(p[i],c,M) % M;
    }
    res = res * f[N] % M;
    res = res * invert(f[r],M) % M;
    res = res * invert(f[N-r],M) % M;
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&N,&M,&Q);
        p.clear();
        int m=M;
        for(int i=2; i*i<=m; ++i) if(m%i==0){
            p.pb(i);
            while(m%i==0) m/=i;
        }
        if(m>1) p.pb(m);
//        for(int i=0; i<sz(p); ++i) cout<<p[i]<<' '; cout<<endl;
        f[0]=1;
        for(int i=1; i<=N; ++i){
            int v=i;
            for(int j=0; j<sz(p); ++j){
                cnt[j][i]=cnt[j][i-1];
                ll x=0;
                while(v%p[j]==0){
                    v/=p[j];
                    ++x;
                }
                cnt[j][i]+=x*i;
            }
            f[i]=f[i-1]*mypow(v,i,M)%M;
        }

        for(int i=0; i<Q; ++i){
            int r;
            scanf("%d",&r);
            printf("%lld\n",query(r));
        }
    }
}

