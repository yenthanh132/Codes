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

string tostr(int v){
    stringstream ss;
    ss<<v;
    return ss.str();
}

int next(int v, int n){
    if(v*10ll<=n) return v*10;
    if(v%10==9) return v/10+1;
    if(v+1<=n) return v+1;
    return v/10+1;
}

class FoxAndMp3 {
public:
	vector <string> playList(int n) {
		vector<string> res;
		
            int v=1;
            res.pb("1.mp3");
            REP(i,min(n-1,49)){
                v=next(v,n);
                res.pb(tostr(v)+".mp3");
            }
            return res;
            
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
