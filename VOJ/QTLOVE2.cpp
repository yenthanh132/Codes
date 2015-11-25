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

int mpow(int &a, int b){
    if(b==0) return 1;
    ll t=mpow(a,b/2);
    t=(t*t)%oo;
    if(b&1) return (t*a)%oo; else return t;
}

int main(){
    ll n;
    int m,v,res;
    scanf("%lld%d",&n,&m); m--;
    v=n%(oo-1);
    res=mpow(m,v);
    if(n&1) printf("%d\n",(res-m+oo)%oo);
    else printf("%d\n",(res+m)%oo);
    return 0;
}
