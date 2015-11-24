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


class UndoHistory {
public:
	int minPresses(vector <string> lines) {
		int res=0;
		REP(i,sz(lines)){
            res+=sz(lines[i])+1;
            int maxv=0,t;
            REP(j,i){
                t=min(sz(lines[j]),sz(lines[i]));
                REP(z,min(sz(lines[j]),sz(lines[i]))) if(lines[j][z]!=lines[i][z]){
                    t=z;
                    break;
                }     
                maxv=max(maxv,t);           
            }
            if(i>0 && sz(lines[i])>=sz(lines[i-1]) && lines[i].substr(0,sz(lines[i-1]))==lines[i-1])
                maxv=max(maxv,sz(lines[i-1])+2);
            res-=maxv;            
        }
        res+=2*(sz(lines)-1);
        return res;
	}
};


<%:testing-code%>

int main(){
    UndoHistory t;
    vector<string> a;
    a.pb("tomorrow");
    a.pb( "topcoder");
    t.minPresses(a);
}
//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
