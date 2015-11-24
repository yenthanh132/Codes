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
int T,n;
ll a[maxn];

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

ll frac[maxn],invfrac[maxn];

int main(){
//    freopen("input.txt","r",stdin);

    frac[0]=1; invfrac[0]=1;
    for(int i=1; i<=100000; ++i){
        frac[i]=frac[i-1]*i%oo;
        invfrac[i]=mypow(frac[i], oo-2);
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ll way = frac[n];
        ll way2 = 1;
        int one=0;
        for(int i=1; i<=n; ++i){
            scanf("%lld",&a[i]);
            if(a[i]==1) ++one;
        }
        sort(a+1,a+n+1);
        for(int i=1; i<=n;){
            int j=i;
            while(j+1<=n && a[j+1]==a[i]) ++j;
            way=way*invfrac[j-i+1]%oo;
            if(a[i]>1) way2 = way2*invfrac[j-i+1]%oo;
            i=j+1;
        }

        ll way3 = 0;
        for(int x=1; x<=one; x+=2){
            ll v1 = frac[n-x]*way2%oo*invfrac[one-x]%oo;
            ll v2 = 0;
            if(x<n && x<one){
                v2 = frac[n-(x+1)]*way2%oo*invfrac[one-(x+1)]%oo;
            }
            v1 = (v1 - v2 + oo)%oo;
            if(one<n) way3 = (way3 + v1)%oo;
        }
        if(one==n && n%2==0) way3=(way3+1)%oo;
        ll res = (way-way3+oo)%oo;
//        cout<<way<<' '<<way3<<endl;
        cout<<res<<endl;
    }
}

