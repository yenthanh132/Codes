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


class TheNumberGame {
public:
    string tostr(int v){
        stringstream ss;
        ss<<v;
        return ss.str();
    }
    
	string determineOutcome(int A, int B) {
	   string a = tostr(A);
       string b = tostr(B);
       string c = b;
       reverse(c.begin(),c.end());
       if(a.find(b)!=string::npos || a.find(c)!=string::npos) return "Manao wins"; else return "Manao loses";	
	}
};

#include <conio.h>
int main(){
    TheNumberGame t;
    cout<<t.determineOutcome(1234,43211);
    getch();
}
//<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
