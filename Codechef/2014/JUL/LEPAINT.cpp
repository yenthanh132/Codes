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

int n,k,c,l[maxn],r[maxn];
double f[maxn],g[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d%d",&n,&c,&k);
        FOR(i,1,k) scanf("%d%d",&l[i],&r[i]);

        double res=0;
        FOR(i,1,n){
            REP(v,c) f[v]=0;
            f[1]=1;
            FOR(j,1,k) if(l[j]<=i && i<=r[j]){
                REP(v,c) g[v]=0;
                REP(v,c) if(f[v]>0) REP(v2,c){
                    int r=v*v2%c;
                    g[r]+=f[v]/2/c;
                }
                REP(v,c) f[v]=f[v]/2+g[v];
            }
            REP(v,c) res+=f[v]*v;
        }

        printf("%0.9lf\n",res);
    }

    return 0;
}
