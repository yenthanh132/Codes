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


class BallsSeparating {
public:
    int n;
	int minOperations(vector <int> r, vector <int> g, vector <int> b) {
		n=sz(r);
		if(n<=2) return -1;
		int res=oo,t;
		FOR(i,0,n-1) FOR(j,0,n-1) if(i!=j) FOR(z,0,n-1) if(z!=i && z!=j){
            t=g[i]+b[i]+r[j]+b[j]+r[z]+g[z];
            FOR(k,0,n-1) if(k!=i && k!=j && k!=z) t+=r[k]+g[k]+b[k]-max(max(r[k],g[k]),b[k]);
            res=min(res,t);
        }
        return res;
            
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
