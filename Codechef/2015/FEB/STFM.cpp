#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxm=10000007;

int m,n;
ll fr[maxm];

ll frac(ll t){
    if(t>=m) return 0;
    return fr[t];
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    fr[0]=1;
    for(int i=1; i<m; ++i) fr[i]=fr[i-1]*i%m;
    ll res=0;
    ll v;
    for(int i=1; i<=n; ++i){
        scanf("%lld",&v);
        ll val;
        if(v&1) val=(v%m)*(v%m)%m*(((v+1)/2)%m)%m;
        else val=(v%m)*((v/2)%m)%m*((v+1)%m)%m;
        res=(res+val)%m;
        val = frac(v+1)-1;
        if(val<0) val+=m;
        res=(res+val)%m;
    }
    printf("%lld\n",res);
}

