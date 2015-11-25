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

const int maxn = 10007;

int n,a[maxn*2],s,t,v,f[maxn*2],sum[maxn*2];
bool ok;

int main(){
    //freopen("test.txt","r",stdin);
    s=0; t=0;
    scanf("%d",&n);
    sum[0]=0;
    while(n){
        s=0;
        FOR(i,1,n) scanf("%d",&a[i]), s+=a[i], a[i+n]=a[i];
        int res=oo,z;
        FOR(i,0,n-3) if(s%(n-i)==0){
            t=s/(n-i);
            v=0;
            ok=0;
            reset(f,0); z=0;
            FOR(j,1,n*2){
             	sum[j]=sum[j-1]+a[j];   
             	while(sum[j]-sum[z]>t) z++;
             	if(sum[j]-sum[z]==t) f[j]=f[z]+j-z;
             	if(f[j]==n){
					ok=1;
					break;
				}
            }
            if(ok){
                res=i;
                break;
            }
        }
        if(res!=oo) printf("%d\n",res); else puts("-1");
        scanf("%d",&n);
    }
    return 0;
}
