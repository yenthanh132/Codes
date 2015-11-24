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

const int maxn=2007;

int a[maxn],n,k;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    int res=0;
    int i=3;
    while(i<=n){
        if(5-a[i]>=k) ++res; else break;
        i+=3;
    }
    
    cout<<res<<endl;
    return 0;   
}
