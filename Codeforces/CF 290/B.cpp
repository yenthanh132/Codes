#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=307;

int a[maxn],c[maxn],n;
map<int,int> f;

struct classcomp {
    bool operator() (const int& lhs, const int& rhs) const
    {return lhs>rhs;}
};
set<int,classcomp> mys;

int gcd(int a, int b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
//   freopen("input.txt","r",stdin);
    cin>>n;

    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=1; i<=n; ++i) cin>>c[i];
    for(int i=1; i<=n; ++i){
        if(f.count(a[i])) f[a[i]]=min(f[a[i]],c[i]);
        else f[a[i]]=c[i];
        mys.insert(a[i]);
    }
    while(!mys.empty()){
        int u=*mys.begin(); mys.erase(mys.begin());
        cout<<u<<endl;
        for(int i=1; i<=n; ++i){
            int v=gcd(u,a[i]);
            if(v==u) continue;
            if(f.count(v)) f[v]=min(f[v],f[u]+c[i]);
            else f[v]=f[u]+c[i];
            mys.insert(v);
        }
    }
    if(f.count(1)) cout<<f[1]<<endl;
    else cout<<-1<<endl;
}

