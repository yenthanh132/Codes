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


class SpellCards {
public:
    int n,f[57][57];
    
	int maxDamage(vector <int> w, vector <int> v) {
        n=sz(w);
		reset(f,0);
		FOR(i,1,n) FOR(j,0,n){
            f[i][j]=f[i-1][j];
            if(j>=w[i-1]) f[i][j]=min(f[i][j],f[i-1][j-w[i-1]]+v[i-1]);
        }
        
        int res=0;
        FOR(j,1,n) res=max(res,f[n][j]);
        return res;
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
