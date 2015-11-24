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

int n;
char s[maxn];
vector<int> a,res;

int main(){
    gets(s);
    n=strlen(s);
    REPD(i,n) a.pb(s[i]-48);
    int t=0;
    REP(i,n+4){
        if(i<n) t+=a[i];
        if(i>=4) t+=a[i-4];
        res.pb(t%2);
        t/=2;
    }
    if(t) res.pb(t);
    REPD(i,sz(res)) printf("%d",res[i]);
    return 0;
}
    
    
