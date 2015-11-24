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


class MonstersValley {
public:
    int minimumPrice(vector<long long> dread, vector <int> price) {
	    ll f[51][101];
	    bool dp[51][101];
	    int n=sz(dread);
	    FOR(j,1,n*2) dp[0][j]=-oo;
	    FOR(i,1,n)
	        FOR(j,0,n*2){
                f[i][j]=f[i-1][j];
                if(j>=price[i-1]) f[i][j]=max(f[i][j],f[i-1][j-price[i-1]]+dread[i-1]);
                if(f[i][j]<dread[i]) f[i][j]=-oo;
            }
        FOR(j,0,n*2) if(f[n][j]>0) return j;
        
               
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
