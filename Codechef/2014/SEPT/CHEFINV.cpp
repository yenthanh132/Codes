#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


const int maxn=200007;

int a[maxn],b[maxn],n,m,k;
ll ans[maxn];


//Bit structure
ll bit[maxn];

void updateDown(int i, ll v){
    for(;i>0; i-=i&(-i)) bit[i]+=v;
}

ll getUp(int i){
    ll r=0;
    for(;i<=200000; i+=i&(-i)) r+=bit[i];
    return r;
}

void updateUp(int i, ll v){
    for(;i<=200000; i+=i&(-i)) bit[i]+=v;
}

ll getDown(int i){
    ll r=0;
    for(;i>0; i-=i&(-i)) r+=bit[i];
    return r;
}

//==============================


struct Query{
    int pos, id, sign;
    Query(){}
    Query(int a, int b, int c):pos(a), id(b), sign(c){};
};
vector<Query> query[maxn];

void addQuery(int l, int r, int v, int id, int sign){
    if(l>r) return;
    query[v].pb( Query(r, id, sign) );
    query[v].pb( Query(l-1, id, -sign) );
}

vector<int> num[maxn];

void solve(){
    for(int i=1; i<=n; ++i) num[a[i]].pb(i);

    reset(bit,0);
    for(int v=1; v<=k; ++v){
        for(int i=0; i<sz(query[v]); ++i){
            Query &q = query[v][i];
            ans[q.id] += getDown(q.pos) * q.sign;
        }
        for(int i=0; i<sz(num[v]); ++i)
            updateUp(num[v][i],1);
    }

    reset(bit,0);
    for(int v=k; v>=1; --v){
        for(int i=0; i<sz(query[v]); ++i){
            Query &q = query[v][i];
            ans[q.id] -= getDown(q.pos) * q.sign;
        }
        for(int i=0; i<sz(num[v]); ++i)
            updateUp(num[v][i],1);
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]), b[i]=a[i];
    sort(b+1,b+n+1);
    k=unique(b+1,b+n+1)-(b+1);
    for(int i=1; i<=n; ++i) a[i] = lower_bound(b+1,b+k+1,a[i])-b;

    ll res = 0;
    reset(bit,0);
    for(int i=1; i<=n; ++i){
        res += getUp(a[i]+1);
        updateDown(a[i],1);
    }
    //for(int i=1; i<=n; ++i) cout<<a[i]<<' '; cout<<endl<<k<<endl;

    reset(ans,0);
    int x,y,v1,v2;
    for(int i=1; i<=m; ++i){
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        if(x==y) continue;
        v1=a[x]; v2=a[y];
        addQuery(x+1,y-1,v2,i,1);
        addQuery(x+1,y-1,v1,i,-1);
        if(v1>v2) --ans[i];
        else if(v1<v2) ++ans[i];
    }
    solve();
    for(int i=1; i<=m; ++i) printf("%lld\n",res + ans[i]);

    return 0;
}
