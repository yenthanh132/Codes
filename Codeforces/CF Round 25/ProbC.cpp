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

const int maxn =307;

ll res,a[maxn][maxn];
int n,k;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(u,1,n) FOR(v,1,n) scanf("%d",&a[u][v]);
    
    int u,v,c;
    scanf("%d",&k);
    REP(i,k){
        scanf("%d%d%d",&u,&v,&c);
        a[u][v]=a[v][u]=min(a[u][v],ll(c));
        FOR(i,1,n) FOR(j,1,n) a[i][j]=min(a[i][j],min(a[i][u]+c+a[v][j],a[i][v]+c+a[u][j]));
        res=0;
        FOR(i,1,n-1) FOR(j,i+1,n) res+=a[i][j];
        printf("%I64d\n",res);
    }
    //getch();
    return 0;
}
