//#include <bits/stdc++.h>
//
//#define pb push_back
//#define sqr(x) (x)*(x)
//#define sz(a) int(a.size())
//#define oo 1000000007
//using namespace std;
//
//typedef pair <int, int> pii;
//typedef pair <int, pii> iii;
//typedef long long ll;
//
//
//ll mypow(ll base, ll n){
//    if(n==0) return 1;
//    ll t=mypow(base,n/2);
//    t=t*t%oo;
//    if(n&1) return base*t%oo;
//    return t;
//}
//
//const int maxn=100007;
//int T,a[maxn],n,b[maxn];
//map<int,ll> cnt;
//map<int,ll> dem;
//
//int main() {
//    //freopen("input.txt", "r", stdin);
//    scanf("%d",&T);
//    for(int tt=1; tt<=T; ++tt){
//        scanf("%d",&n);
//        dem.clear();
//        for(int i=1; i<=n; ++i) scanf("%d",&a[i]), dem[a[i]]++;
//        sort(a+1,a+n+1);
//        n=unique(a+1,a+n+1)-(a+1);
//        for(int i=1; i<=n; ++i) b[i]=mypow(a[i],oo-2);
//        ll res=0;
//        cnt.clear();
//        for(int i=1; i<=n; ++i) if((1ll*a[i]*a[i])%oo!=1) cnt[a[i]]++;
//        for(int i=1; i<=n; ++i) if((1ll*b[i]*b[i])%oo!=1) res+=cnt[b[i]];
//        res/=2;
//        for(int i=1; i<=n; ++i) if((1ll*a[i]*a[i])%oo==1 && dem[a[i]]>1) ++res;
//
////        for(int i=1; i<=n;++i) cout<<a[i]<<' '; cout<<endl;
////        for(int i=1; i<=n;++i) cout<<b[i]<<' '; cout<<endl;
//        printf("Case #%d: %I64d\n",tt,res);
//    }
//    return 0;
//}
//
//
