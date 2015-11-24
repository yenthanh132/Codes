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
int a[maxn],n,ans[maxn];

int main(){
    freopen("cubes.in","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",&a[i]);
        sort(a+1,a+n+1);   
        int l=1, r=n, flag=1;
        FORD(i,n,1){
            if(flag)
                ans[r--]=a[i];   
            else ans[l++]=a[i];
            flag^=1;
        }
        printf("Case %d:\n",tt);
        FOR(i,1,n-1) printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
}
