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

int n,a[maxn],s1[maxn],s2[maxn];

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&a[i]);
        s1[i]=s1[i-1]; s2[i]=s2[i-1];
        if(a[i]>=0) s1[i]+=a[i]; else s2[i]-=a[i];
    }
    int res=-oo,t=0;
    FOR(i,1,n+1){
        res=max(res,s2[n]-s1[n] + 2*(s1[i-1]-s2[i-1]) + t*2);
        t=max(t,s2[i]-s1[i]);
    }
    
    printf("%d\n",res);
    return 0;
}
