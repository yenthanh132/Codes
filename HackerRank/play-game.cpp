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

int a[maxn],n,T;
ll s[maxn],f[maxn];
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",&a[i]);
        s[n+1]=f[n+1]=0;
        FORD(i,n,1){
            s[i]=s[i+1]+a[i];
            f[i]=-1;
            ll sum=0;
            REP(j,3){
                if(i+j>n) break;
                sum+=a[i+j];
                f[i] = max(f[i], sum + (s[i+j+1] - f[i+j+1]));
            }
        }
        printf("%lld\n",f[1]);
    }
    return 0;
}
