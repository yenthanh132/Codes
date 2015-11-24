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

int a[maxn],n,t,f[maxn],g[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&t);
    FOR(tt,1,t){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",&a[i]);
        reset(f,0); reset(g,0);
        f[0]=0;
        FOR(i,1,n){
            FORD(j,i-1,1) if(a[j]>a[i]) f[i]++;
        }
        g[n+1]=0;
        FORD(i,n,1){
            FOR(j,i+1,n) if(a[j]>a[i]) g[i]++;
        }
        int res=0;
        FOR(i,1,n){
            res+=min(f[i],g[i]);
        }

        printf("Case #%d: %d\n",tt,res);
    }
}

