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

const int maxn=800007;

ll gt[maxn],ngt[maxn],res;
int r,m,n,a,b;

ll mpow(ll v0, int n){
    if(n==1) return v0;
    ll t=mpow(v0,n/2);
    t=(t*t)%oo;
    if(n&1) return (t*v0)%oo; else return t;
}

ll count(int m, int n){
    return (((gt[m+n]*ngt[m])%oo)*ngt[n])%oo;
}

//#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    gt[0]=1; ngt[0]=mpow(gt[0],oo-2);
    FOR(i,1,800000) gt[i]=(gt[i-1]*i)%oo, ngt[i]=mpow(gt[i],oo-2);
    scanf("%d",&r);
    REP(index,r){
        scanf("%d%d%d%d",&n,&m,&a,&b);
        res=0;
        FOR(i,0,n-a) res=(res+count(b-1,i)*count(m-b,n-i))%oo;
        printf("%lld\n",res);
    }
    //getch();
    return 0;
}   
