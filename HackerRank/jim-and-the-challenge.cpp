#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000009

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=300007;

int n,d,DSort;
struct point{
    vector<ll> x;
    ll h;
}p[maxn];

bool cmp(const point &a, const point &b){
    return a.x[DSort] < b.x[DSort];
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&d);
    for(int i=1; i<=n; ++i){
        ll v;
        scanf("%lld",&p[i].h);
        for(int j=0; j<d; ++j){
            scanf("%lld",&v);
            p[i].x.pb(v);
        }
    }
    ll res = 0;
    for(int i=0; i<d; ++i){
        DSort = i;
        sort(p+1,p+n+1,cmp);
        ll sumH = 0, sumV = 0;
        for(ll j=1; j<=n; ++j){
            res = (res + p[j].h * ( p[j].x[i]*sumH%oo - sumV)%oo + oo)%oo;
            sumH = (sumH + p[j].h)%oo;
            sumV = (sumV + p[j].h*p[j].x[i])%oo;
        }
    }

    cout<<res<<endl;
}

