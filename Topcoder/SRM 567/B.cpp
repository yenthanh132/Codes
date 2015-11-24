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

int len,n;
int c[57][27];
bool mark[57];

class StringGame {
public:
	vector <int> getWinningStrings(vector <string> S) {
        n=sz(S);
	    len=sz(S[0]);	
	    reset(c,0);
        REP(i,n) REP(j,len) c[i][S[i][j]-'a']++;
        vector<int> res;
        bool ok;
        REP(i,n){
            reset(mark,0);
            REP(t,26) if(c[i][t]){
                ok=1;
                REP(j,n) if(i!=j && c[j][t]>c[i][t]){
                    ok=0;
                    break;
                }
                if(!ok) continue;
                REP(j,n) if(c[i][t]>c[j][t]) mark[j]=1;
            }
            ok=1;
            REP(j,n) if(j!=i && !mark[j]){
                ok=0;
                break;
            }
            if(ok) res.pb(i);
        }
        return res;
            
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
