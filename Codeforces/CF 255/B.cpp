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
#define oo 1000000000000000007ll

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1007;
const int maxk=1000007;

int m,n,k,p;
ll c[maxn],r[maxn],a[maxn][maxn];
ll vc[maxk],vr[maxk];
multiset<ll> mys;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d%d%d",&m,&n,&k,&p);

    for(int i=1; i<=m; ++i) for(int j=1; j<=n; ++j) scanf("%I64d",&a[i][j]);
    for(int i=1; i<=m; ++i){
        r[i]=0;
        for(int j=1; j<=n; ++j) r[i]+=a[i][j];
    }
    for(int j=1; j<=n; ++j){
        c[j]=0;
        for(int i=1; i<=m; ++i) c[j]+=a[i][j];
    }

    mys.clear();
    for(int i=1; i<=m; ++i) mys.insert(-r[i]);
    vr[0]=0;
    for(int i=1; i<=k; ++i){
        vr[i]=vr[i-1];
        ll val=-*mys.begin();
        mys.erase(mys.begin());
        vr[i]+=val;
        mys.insert(-(val-p*n));
    }

    mys.clear();
    for(int i=1; i<=n; ++i) mys.insert(-c[i]);
    vc[0]=0;
    for(int i=1; i<=k; ++i){
        vc[i]=vc[i-1];
        ll val=-*mys.begin();
        mys.erase(mys.begin());
        vc[i]+=val;
        mys.insert(-(val-p*m));
    }

    ll res=-oo;
    for(int i=0; i<=k; ++i){
        res=max(res, vr[i]+vc[k-i]-1ll*p*i*(k-i));
    }

    printf("%I64d\n",res);

    return 0;
}
