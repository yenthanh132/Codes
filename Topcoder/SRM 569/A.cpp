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

const int maxn=107;
class TheDevice {
public:
    
    int c1[maxn],c2[maxn],n,len;
	int minimumAdditional(vector <string> a) {
		n=sz(a);
		len=sz(a[0]);
		reset(c1,0); reset(c2,0);
		FOR(i,0,n-2) FOR(j,i+1,n-1) REP(k,len) if(a[i][k]=='1' && a[j][k]=='1') c1[k]=1;
        else if(a[i][k]!='0' || a[j][k]!='0') c2[k]=1;
        int res=0;
        REP(k,len) res=max(res,2-c1[k]-c2[k]);
        return res;        
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
