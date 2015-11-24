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
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;
const int maxv=100000;

ll fac[maxn],fac2[maxn];
map<pii,int> save;
int cnt;

ll mypow(int base, int n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=(t*t)%oo;
    if(n&1) return (t*base)%oo; else return t;
}

ll C(int n, int k){
    ll res=fac[n]*fac2[k]%oo;
    res=res*fac2[n-k]%oo;
    return res;
}


ll solve(int f, int n){
    if(f==1) return (n==1);
    //if(f==2) return phi(n);
    if(f==n) return 1;
    if(f>n) return 0;
    if(save.count(pii(f,n))) return save[pii(f,n)];
    ll res=0;
    for(int i=2; i*i<=n; i++) if(n%i==0){
        int x=i;
        res=(res+solve(f,n/x))%oo;

        if(i*i==n) continue;
        x=n/i;
        res=(res+solve(f,n/x))%oo;
    }
    save[pii(f,n)]=(C(n-1,f-1)-res+oo)%oo;
    return save[pii(f,n)];
}

int main(){
    //freopen("input.txt","r",stdin);

    fac[0]=1;
    FOR(i,1,maxv) fac[i]=fac[i-1]*i%oo;
    FOR(v,0,maxv) fac2[v]=mypow(fac[v],oo-2);
    int q,f,n;
    scanf("%d",&q);
    REP(i,q){
        scanf("%d%d",&n,&f);
        printf("%I64d\n",solve(f,n));
    }
}

