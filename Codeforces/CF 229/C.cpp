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

const int maxn=100007;

int s[maxn][11];
int a[maxn];
int n,k,w;
char buf[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&k,&w);
    scanf("%s",buf+1);
    FOR(i,1,n) a[i]=buf[i]-'0';
    REP(j,k) FOR(i,1,n) s[i][j]=s[i-1][j]+(a[i]==1)*(i%k==j);
    int l,r;
    REP(tt,w){
        scanf("%d%d",&l,&r);
        int res=(r-l+1)/k - (s[r][(l-1)%k]-s[l-1][(l-1)%k]);
        REP(j,k) if(j!=(l-1)%k) res+=s[r][j]-s[l-1][j];

        printf("%d\n",res);
    }
    return 0;

}

