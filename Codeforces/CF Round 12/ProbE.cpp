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

int N,a[1000][1000];

int main(){
    scanf("%d",&N);
    REP(i,N) REP(j,N) a[i][j]=(i+j)%(N-1)+1;
    REP(i,N) a[i][N-1]=a[N-1][i]=a[i][i], a[i][i]=0;
    REP(i,N){
        REP(j,N) printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
