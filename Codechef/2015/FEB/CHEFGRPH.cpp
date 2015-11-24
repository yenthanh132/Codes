#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> iii;


const int maxn=100007;

int m,k,N;
ll f[maxn],n,mInv,e[4][maxn];
vector<iii> xlist;
vector<int> ed[maxn];

ll mypow(ll base, ll n){
    if(n<=0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

int pos(ll u, ll v, int k){
    return lower_bound(xlist.begin(),xlist.end(), iii(pii(u,v),k))-xlist.begin();
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%lld%d%d",&n,&m,&k);
    xlist.pb(iii(pii(0,0),0));
    for(int i=0; i<k; ++i){
        for(int j=0; j<4; ++j) scanf("%lld",&e[j][i]);
        xlist.pb(iii(pii(e[0][i],e[1][i]),1));
        xlist.pb(iii(pii(e[2][i],e[3][i]),0));
    }
    xlist.pb(iii(pii(n+1,0),1));
    sort(xlist.begin(),xlist.end());
    xlist.resize(unique(xlist.begin(),xlist.end())-xlist.begin());

    for(int i=0; i<k; ++i){
        int u=pos(e[0][i],e[1][i],1);
        int v=pos(e[2][i],e[3][i],0);
        ed[v].pb(u);
    }
    f[0]=1;
    N=sz(xlist)-1;
    mInv = mypow(m,oo-2);
    ll sum=0;
    int pos = 0;
    for(int i=0; i<=N; ++i){
        while(xlist[pos].first.first<xlist[i].first.first){
            if(xlist[pos].second==0)
                sum=(sum + f[pos]*mypow(mInv,xlist[pos].first.first+1))%oo;
            ++pos;
        }
        if(xlist[i].second==1){
            f[i]=sum*mypow(m,xlist[i].first.first)%oo;
            if(xlist[i].first==xlist[i-1].first) f[i] = (f[i] + f[i-1])%oo;
        }else{
            for(int j=0; j<sz(ed[i]); ++j)
                f[i] = (f[i] + f[ed[i][j]])%oo;
        }
    }
    cout<<f[N]<<endl;
}

