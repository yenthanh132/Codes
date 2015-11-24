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


class RouteIntersection {
public:
    int m,c;
    map<int,int> mymap;
    map<vector<int>,bool> mark;
	string isValid(int N, vector <int> a, string s) {
		m=sz(a);
		c=0;
		REP(i,m) if(mymap[a[i]]==0) mymap[a[i]]=++c;
		vector<int> vec;
		vec.resize(c,0);
		mark[vec]=1;
		REP(i,m){
            int id=mymap[a[i]]-1;
            if(s[i]=='+') vec[id]++;
            else vec[id]--;
            if(mark[vec]) return "NOT VALID";
            mark[vec]=1;
        }
        return "VALID";
    } 
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
