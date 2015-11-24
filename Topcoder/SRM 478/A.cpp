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

ll mypow(int n){
    if(n==1) return 2;
    ll t=mypow(n/2);
    t=(t*t)%oo;
    if(n&1) return (t*2)%oo; else return t;
}

int count(int v){
    if(v%3==0) return v/3;
    else if(v%3==2) return ((v-2)/3+1);
    else return (v-4)/3+2;
}

class CarrotJumping {
public:
	int theJump(int init) {
        int res=oo;
        for(int i=2, val=count(i); val<=100000; val=count(++i)){
            ll t=mypow(i);
            if(((init+1)*t-1)%oo==0) res=min(res,val);
        }
        if(res==oo) return -1; else return res;
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
