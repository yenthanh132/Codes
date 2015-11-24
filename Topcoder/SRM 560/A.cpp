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


class TomekPhone {
public:
	int minKeystrokes(vector <int> f, vector <int> s) {
		int n=sz(f), m=sz(s);
		vector<int> list;
        REP(i,m){
            FOR(j,1,s[i]) list.pb(j);
        }
        sort(list.begin(),list.end());
		sort(f.begin(),f.end()); 
		if(sz(list)<n) return -1;
		int res=0,j=0;
		REPD(i,n){
            res+=f[i]*list[j++];
        }
        return res;
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
