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

const int maxn = 5007;

int n,m,k,p1[maxn],p2[maxn],maxr1,A,B;
double res;

#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    int v;
    scanf("%d",&n);
    maxr1=-1;
    REP(i,n) scanf("%d",&v), maxr1=max(maxr1,v);
    scanf("%d",&m);
    REP(i,m) scanf("%d",&p1[i]);
    scanf("%d",&k);
    REP(i,k) scanf("%d",&p2[i]);
    scanf("%d%d",&A,&B);
    
    res=-1;
    REP(i,m) REP(j,k) res=max(res,(1.0*maxr1*maxr1*p1[i]*B)/(1.0*p1[i]*B+1.0*p2[j]*A));
    printf("%0.12lf",sqrt(res));
    //getch();
    return 0;
}
    
