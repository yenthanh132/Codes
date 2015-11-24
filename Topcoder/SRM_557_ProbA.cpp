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


class FoxAndMountainEasy {
public:
	string possible(int n, int h0, int hn, string s){
		int x=0,minx=0;
		REP(i,sz(s)){
            if(s[i]=='U') x++; else x--;
            minx=min(minx,x);
        }
		h0+=x; n-=sz(s);
		int d=abs(hn-h0);
		if(d>n) return "NO";
		else if((n-d)&1) return "NO";
		int up;
		if(h0<hn) up=d; else up=0;
		up+=(n-d)/2;
		if(up+minx<0) return "NO";
		return "YES";
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
