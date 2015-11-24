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

int a[1007],n;

int main(){
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    int x=n, y=1, minv=abs(a[n]-a[1]);
    FOR(i,1,n-1) if(minv>abs(a[i]-a[i+1])){
        minv=abs(a[i]-a[i+1]);
        x=i; y=i+1;
    }
    cout<<x<<' '<<y<<endl;
}
