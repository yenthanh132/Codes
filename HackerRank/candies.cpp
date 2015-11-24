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

int n,candy[maxn],ranks[maxn];
pair<int,int> a[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i].first), a[i].second=i, ranks[i]=a[i].first;
    sort(a+1,a+n+1);
    reset(candy,0);
    ll res=0;
    for(int i=1; i<=n; ++i){
        int p=a[i].second;
        int v=1;
        if(p>1 && candy[p-1] && ranks[p]>ranks[p-1]) v=max(v,candy[p-1]+1);
        if(p<n && candy[p+1] && ranks[p]>ranks[p+1]) v=max(v,candy[p+1]+1);
        candy[p]=v;
        res+=v;
    }

    printf("%lld\n",res);

}
