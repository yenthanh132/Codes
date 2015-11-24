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


class SwitchesAndLamps {
public:
    int n,m,deg[57];
    bool a[57][57];
	int theMin(vector <string> s, vector <string> l) {
		n=sz(s); m=sz(s[0]);
		REP(i,m) deg[i]=m;
		reset(a,1);
		REP(i,n){
            REP(j,m){
                REP(z,m) if(l[i][z]!=s[i][j] && a[j][z]){
                    a[j][z]=0;
                    deg[z]--;
                }
            }
        }
        int mindeg=oo,maxdeg=-oo;
        REP(i,m){
            mindeg=min(mindeg,deg[i]);
            maxdeg=max(maxdeg,deg[i]);
        }
        if(mindeg==0) return -1;
        int res=0;
        while(maxdeg>1){
            maxdeg=maxdeg-maxdeg/2;
            res++;
        }
        return res;
	}
};


//<%:testing-code%>
#include <conio.h>
int main(){
    SwitchesAndLamps t;
    vector<string> s,l;
    s.pb("YYYNNN"); s.pb("YNNYYN");
    l.pb("YYYNNN"); l.pb("YYNYNN");
    cout<<t.theMin(s,l);
    getch();
}

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
