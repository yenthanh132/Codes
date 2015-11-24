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

ll a[4],res;
int n;

int main(){
    scanf("%d",&n);
    REP(i,n){
        scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
        sort(a+1,a+4);
        a[2]-=1;
        a[3]-=2;
        res=((((a[1]%oo)*(a[2]%oo))%oo)*(a[3]%oo))%oo;
        printf("%lld\n",res);
    }
    return 0;
}
