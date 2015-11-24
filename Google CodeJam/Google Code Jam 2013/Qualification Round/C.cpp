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

int T;
ll a,b;
const int n=39;
const ll list[40]={0ll, 1ll, 4ll, 9ll, 121ll, 484ll, 10201ll, 12321ll, 14641ll, 40804ll, 44944ll, 1002001ll, 1234321ll, 4008004ll, 100020001ll, 102030201ll, 104060401ll, 121242121ll, 123454321ll, 125686521ll, 400080004ll, 404090404ll, 10000200001ll, 10221412201ll, 12102420121ll, 12345654321ll, 40000800004ll, 1000002000001ll, 1002003002001ll, 1004006004001ll, 1020304030201ll, 1022325232201ll, 1024348434201ll, 1210024200121ll, 1212225222121ll, 1214428244121ll, 1232346432321ll, 1234567654321ll, 4000008000004ll, 4004009004004ll};


/*ll list[1000000];
int arr[20],c;

bool ispalindrom(ll v){
    c=0;
    while(v){
        arr[++c]=v%10;
        v/=10;
    }
    FOR(i,1,c/2) if(arr[i]!=arr[c-i+1]) return 0;
    return 1;
}

bool ok(ll v){
    return ispalindrom(v) && ispalindrom(v*v);
}

void init(){
    n=0;
    FOR(i,1,10000000) if(ok(i)) list[++n]=1ll*i;
}
*/
#include <conio.h>
int main(){
   
    
    freopen("C-large-1.in","r",stdin);
    freopen("C-large-1.out","w",stdout);
    
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%lld%lld",&a,&b);
        int res=0;
        FOR(i,1,n) if(list[i]>=a && list[i]<=b) res++;
        printf("Case #%d: %d\n",tt,res);
    }
    
    return 0;
}

