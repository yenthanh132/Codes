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

int a[maxn],n,k,Left[maxn],Right[maxn],mys[maxn],last;
ll res,p[maxn];


int main(){
    //freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1; i<=n; ++i) cin>>a[i];

    mys[0]=0;
    last=0;
    for(int i=1; i<=n; ++i){
        while(last>0 && a[mys[last]]>a[i]) --last;
        Left[i]=mys[last];
        mys[++last]=i;
    }
    mys[last=0]=n+1;
    for(int i=n; i>=1; --i){
        while(last>0 && a[mys[last]]>a[i]) --last;
        Right[i]=mys[last];
        mys[++last]=i;
    }

    res=0;
    for(int i=1; i<=n; ++i){
        ll r=Right[i]-i, l=i-Left[i];
        p[i]=(l*l*r + r*r*l)/2;
        res+=1ll*a[i]*p[i];
    }
    sort(p+1,p+n+1,greater<ll>());
    for(int i=1; i<=k; ++i) res+=p[i];

    cout<<res<<endl;
}

