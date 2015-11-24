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

const int maxn=2007;

char a[maxn][maxn];
int n,m,k;

int calc(int col){
    int res=0;
    for(int i=3; i<=n; i+=2) if(a[i][col]=='U') ++res;
    int i=2, j=col-1;
    while(i<=n && j>=1){
        if(a[i][j]=='R') ++res;
        ++i;
        --j;
    }
    i=2; j=col+1;
    while(i<=n && j<=m){
        if(a[i][j]=='L') ++res;
        ++i;
        ++j;
    }
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%s",a[i]+1);
    FOR(i,1,m) printf("%d ",calc(i));
    return 0;
}
