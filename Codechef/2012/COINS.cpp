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

ll val[32][32];

ll get(ll num, int p2, int p3){
    if(val[p2][p3]!=-1) return val[p2][p3];
    if(num==0){
        val[p2][p3]=0;
        return 0;
    }
    val[p2][p3]=max(get(num/2,p2-1,p3)+get(num/3,p2,p3-1)+get(num/4,p2-2,p3), num);
    return val[p2][p3];
}


int main(){
    ll n;
//    freopen("test.txt","r",stdin);
    while(scanf("%lld",&n)!=EOF){
        REP(i,32) REP(j,32) val[i][j]=-1;
        cout<<get(n,31,31)<<endl;
    }
    return 0;
}
