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
#define oo 1000000009

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll mypow(int v0, int n){
    if(n==1) return v0;
    ll t=mypow(v0,n/2);
    t=(t*t)%oo;
    if(n&1) return (t*v0)%oo; else return t;   
}

int k,n;
ll val;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&k);
    n=1<<k;
    FOR(i,1,n/2-1) puts("0");
    val=2;
    FOR(i,2,n/2) val=val*i%oo*i%oo;
    
    printf("%lld\n",val);
    FOR(i,1,n/2){
        val=val*mypow(i,oo-2)%oo*(n/2+i-1)%oo;
        printf("%lld\n",val);
    }
    
}
