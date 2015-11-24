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

int b[maxn][maxn],c[maxn][maxn],sum,n,m,k,list[maxn],a[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);    
    REP(tt,T){
        scanf("%d%d%d",&n,&m,&k);
        FOR(i,1,n) scanf("%d",&a[i]);
        FOR(i,1,n) FOR(j,1,m) scanf("%d",&b[i][j]);
        FOR(i,1,n) FOR(j,1,m) scanf("%d",&c[i][j]);
        sum=0;
        int cnt=0;
        FOR(i,1,n){
            sum+=b[i][a[i]];
            int maxv=-oo;
            FOR(j,1,m) maxv=max(maxv,b[i][j]-b[i][a[i]]-c[i][j]);
            if(maxv>0) list[++cnt]=maxv;
        }
        sort(list+1,list+cnt+1);
        FORD(i,cnt,max(1,cnt-k+1)) sum+=list[i];
        printf("%d\n",sum);
    }
    return 0;
}
