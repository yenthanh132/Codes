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

ll power(int a, int n){
    if(n==0) return 1;
    if(n==1) return a;
    ll t=power(a,n/2);
    t=(t*t)%oo;
    if(n&1) return (t*a)%oo; else return t;
}   

int main(){
    int test,n;
    ll res,res2,div8=power(8,oo-2);
    scanf("%d",&test);
    REP(index,test){
        scanf("%d",&n);
        res=(power(3,n-2)*12)%oo;
        res2=(12*((-( power(9,(n-1)/2)-1 ) * div8 )%oo + 3 * (( power(9,(n-2)/2)-1 ) * div8 )%oo))%oo;
        if(n&1) printf("%d\n",(res+res2+oo)%oo); else printf("%d\n",(res-res2+oo)%oo);
    }
    return 0;
}
    
    
