#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;

int n,a[maxn],lab[maxn];

int getroot(int u){
    if(lab[u]<0) return u;
    return (lab[u]=getroot(lab[u]));
}

void dsu(int u, int v){
    int r1=getroot(u), r2=getroot(v);
    if(r1==r2) return;
    if(lab[r1]>lab[r2]) swap(r1,r2);
    lab[r1] += lab[r2];
    lab[r2]=r1;
}

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

multiset<int> mys;
set<pii> mys2;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    reset(lab,-1);

    for(int i=1; i<=n; ++i){
        if(mys.empty() || a[i] <= *mys.begin()){
            mys.insert(a[i]);

            if(sz(mys)>=3){
                puts("0");
                return 0;
            }
        }else{
            multiset<int>::iterator it=mys.lower_bound(a[i]);
            --it;
            mys.erase(it);
            mys.insert(a[i]);
        }
    }

    for(int i=1; i<=n; ++i){
        int v=a[i];
        pii x=pii(0,0);
        while(!mys2.empty()){
            set<pii>::iterator it = mys2.lower_bound(pii(v,0));
            if(it==mys2.end()) break;
            x = *it;
            dsu(i, x.second);
            mys2.erase(it);
        }
        if(x.second!=0) mys2.insert(x);
        mys2.insert(pii(v,i));
    }

    int cnt=0;
    for(int u=1; u<=n; ++u) if(lab[u]<0) ++cnt;
    cout<<mypow(2,cnt)<<endl;

    return 0;
}

