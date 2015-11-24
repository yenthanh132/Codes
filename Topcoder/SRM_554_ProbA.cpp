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

vector<int> minv(vector<int> &a, vector<int> &b){
    int n=sz(a);
    REP(i,n) if(a[i]<b[i]) return a; else if(a[i]>b[i]) return b;
    return b;
}

class TheBrickTowerMediumDivOne {
public:
	vector <int> find(vector <int> a) {
		vector<int> res, res2; res.pb(0); res2.pb(0);
		vector<pii> b;
		int n=sz(a)-1,p,p2;
		
		FOR(i,1,n) b.pb(pii(a[i],i));
		
		sort(b.begin(),b.end());
		p=max(a[0],b[0].fi); FOR(i,0,n-2) p+=max(b[i].fi,b[i+1].fi);
		REP(i,n) res.pb(b[i].se);
		
		sort(b.rbegin(),b.rend());
		p2=max(a[0],b[0].fi); FOR(i,0,n-2) p2+=max(b[i].fi,b[i+1].fi);
		REP(i,n) res2.pb(b[i].se);
		
		if(p<p2) return res; else if(p>p2) return res2; else return minv(res,res2);
	}
};



<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
