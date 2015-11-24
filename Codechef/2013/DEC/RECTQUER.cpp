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

const int maxn=307;

int a[11][maxn][maxn];
int n,q;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int x1,y1,x2,y2,v;
    scanf("%d",&n);
    FOR(i,1,n) FOR(j,1,n){
        FOR(v,1,10) a[v][i][j]=a[v][i-1][j]+a[v][i][j-1]-a[v][i-1][j-1];
        scanf("%d",&v);
        ++a[v][i][j];
    }
    scanf("%d",&q);
    REP(i,q){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int res=0;
        FOR(v,1,10) if(a[v][x2][y2]-a[v][x1-1][y2]-a[v][x2][y1-1]+a[v][x1-1][y1-1]>0) ++res;
        printf("%d\n",res);   
    }
}
