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

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

class SequenceOfCommands {
public:
	string whatHappens(vector <string> s) {
		int k=0,x=0,y=0;
	REP(index,10)
		REP(i,sz(s))
            REP(j,sz(s[i]))
                if(s[i][j]=='S'){
                    x+=dx[k];
                    y+=dy[k];
                }else if(s[i][j]=='L'){
                    k=(k+3)%4;
                }else{
                    k=(k+1)%4;
                }
        if(x==0 && y==0) return "bounded";else return "unbounded";
    }
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
