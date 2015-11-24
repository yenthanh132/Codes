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

const int maxn=1007;

int c[maxn][maxn],n;

int main(){
    c[0][0]=1;
    FOR(i,1,1000){
        c[i][0]=1;
        FOR(j,1,i) c[i][j]=(c[i-1][j-1]+c[i-1][j])%oo;
    }sc
    int test,v,res;
    scanf("%d",&test);
    REP(index,test){
        scanf("%d",&n);
        res=0;
        FOR(i,1,n) scanf("%d",&v);
        FOR(i,n/2+1,n) res=(res+c[n][i])%oo;
        printf("%d\n",res);
    }
    return 0;
}
        
