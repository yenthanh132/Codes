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

const int maxn=200007;

int a[maxn],n,t,c;
multiset<int> mys;

int main(){
    
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
  
    int res=0;
    scanf("%d%d%d",&n,&t,&c);
    FOR(i,1,n) scanf("%d",&a[i]);
    if(c>n){
        puts("0");
        return 0;   
    }
    FOR(i,1,c-1) mys.insert(a[i]);
    FOR(i,c,n){
        if(i>c) mys.erase(mys.find(a[i-c]));
        mys.insert(a[i]);
        if(*mys.rbegin() <= t) ++res;   
    }
    printf("%d\n",res);
    
    return 0;
}
