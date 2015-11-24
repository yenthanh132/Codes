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
int n,a[maxn],res1,res2;

int main(){
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    int i=1,j;
    res1=res2=0;
    while(i<=n){
        j=i; while(j<n && a[j+1]==a[i]) j++;
        res1=max(res1,j-i+1);
        res2++;
        i=j+1;
    }
    cout<<res1<<' '<<res2<<endl;
}
