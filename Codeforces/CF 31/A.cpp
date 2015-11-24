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

const int maxn=107;
int n,a[maxn];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) FOR(j,1,n) if(i!=j) FOR(k,1,n) if(k!=i && k!=j)
        if(a[i]==a[j]+a[k]){
            printf("%d %d %d\n",i,j,k);
            return 0;
        }
    puts("-1");
    return 0;
}
