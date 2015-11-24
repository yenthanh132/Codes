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

const int maxn=5007;
int n,d4,d7;
ll gt[maxn],gt2[maxn],res;
char a[maxn];

ll mpow(ll v0, ll n){
    if(n==0) return 1;
    ll t=mpow(v0,n/2);
    t=(t*t)%oo;
    if(n&1) return (t*v0)%oo; else return t;
}

ll mul(ll a, ll b){
    return (a*b)%oo;
}

ll tohop(ll n, ll k){
    return mul(gt[n],mul(gt2[n-k],gt2[k]));
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out2.txt","w",stdout);
    int t;
    scanf("%d\n",&t);
    gt[0]=gt[1]=1;
    FOR(i,2,5000) gt[i]=mul(gt[i-1],i);
    FOR(i,0,5000) gt2[i]=mpow(gt[i],oo-2);
    
    REP(index,t){
        gets(a);
        n=strlen(a);
        d4=0;
        REP(i,n) if(a[i]=='4') d4++;
        d7=n-d4;
               
        res=0;
        int x;
        FOR(val,0,min(d4,d7)){
            x=d7+1;
            if(val<=x-1 && val<=n-x) res=(res+mul(tohop(x-1,val), tohop(n-x,val)))%oo;
            x=d7;
            if(val<=x-1 && val<=n-x) res=(res+mul(tohop(x-1,val), tohop(n-x,val)))%oo;
            if(val<=x-1 && val<=n-x-1) res=(res-mul(tohop(x-1,val), tohop(n-x-1,val)) + oo)%oo;
        }
        printf("%lld\n",res);
    }
    //getch();
    return 0;
    
}

