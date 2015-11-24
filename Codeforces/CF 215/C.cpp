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

const int maxn=2107;

int dp[maxn],n,m,a[2000007];

ll cal(int n){
    if(n&1) return n*(n-1)/2 + 1;
    else return n*(n-1)/2 + (n-2)/2 + 1;
}

bool cmp(const int &a, const int &b){
    return a>b;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    //FOR(i,1,10) cout<<i<<' '<<cal(i)<<endl;
    
    scanf("%d%d",&n,&m);
    int t;
    FOR(i,1,m) scanf("%d%d",&t,&a[i]);
    
    sort(a+1,a+m+1,cmp);
    int p=0;
    while(cal(p+1)<=n) ++p;
    ll res=0;
    FOR(i,1,min(p,m)) res+=a[i];
    cout<<res<<endl;
    
}
