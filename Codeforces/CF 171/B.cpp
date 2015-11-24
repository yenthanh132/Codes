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

int n,a[maxn],s[maxn],v;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&v);
    FOR(i,1,n) scanf("%d",&a[i]), s[i]=s[i-1]+a[i];
    int res=0;
    FOR(i,1,n) if(a[i]<=v){
        int left=1, right=i, mid;
        while(left<=right){
            mid=(left+right)>>1;
            if(s[i]-s[mid-1]<=v){
                res=max(res,i-mid+1);
                right=mid-1;
            }else left=mid+1;
        }
    }
    printf("%d\n",res);
    return 0;
}
