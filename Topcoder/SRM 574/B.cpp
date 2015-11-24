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

int n,m;
ll dp[1<<18][18];

bool can_go(int v, int s, int f){
    int i;
    bool ok;
    ok=0;
    for(i=(s+1)%n; i!=f; i=(i+1)%n)
        if((v>>i)&1){
            ok=1;
            break;
        }
    if(!ok) return 0;
    ok=0;
    for(i=(s-1+n)%n; i!=f; i=(i-1+n)%n)
        if((v>>i)&1){
            ok=1;
            break;
        }
    return ok;
}

class PolygonTraversal {
public:
    
    
	long long count(int N, vector <int> a) {
        reset(dp,0);
        n=N;
		m=1<<n;
		int id=0;
		REP(i,sz(a)) id|=1<<(a[i]-1);
		dp[id][a.back()-1]=1;
		REP(i,m-1) REP(j,n) if(dp[i][j])
		    REP(z,n) if(((i>>z)&1)==0 && can_go(i,j,z))
		        dp[i + (1<<z)][z] += dp[i][j];
		ll res=0;
		REP(x,n) if(x!=a[0]-1 && x!=(a[0]-2+n)%n && x!=(a[0])%n) res+=dp[m-1][x];
		return res;
	}
};


<%:testing-code%>
#include <conio.h>
int main(){
    PolygonTraversal t;
    int a[]={1,7,18};
    vector<int> va(a,a+3);
    cout<<t.count(18,va);
    getch();
}


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
