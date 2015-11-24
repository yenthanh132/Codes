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


class DefectiveAddition {
public:
	int count(vector <int> a, int n) {
		int m=sz(a);
		int v;
		sort(a.begin(),a.end());
		v=1;
		while(v*2<=a[m-1]) v*=2;
		if(n>v*2-1) return 0;
		REP(i,m) cout<<a[i]<<' '; cout<<endl;
		ll dp[57][2];
		reset(dp,0);
        dp[0][0]=1; 
		FOR(i,1,m-1) REP(j,2){
            dp[i][j]=(dp[i][j]+dp[i-1][j]*min(a[i-1]+1,v) + dp[i-1][1^j]*max(0,a[i-1]-v+1))%oo;
        }
        ll ans=0;
        if(n>=v) ans+=dp[m-1][1]; else ans+=dp[m-1][0];
        if(a[m-1]>=v){
            a[m-1]-=v;
            ans=(ans+count(a,n^v))%oo;
        }
        return ans%oo;
	}
};


//<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!

#include <conio.h>
int main(){
    DefectiveAddition t;
    vector<int> a;
    a.pb(1); a.pb(2); a.pb(3);
    cout<<t.count(a,1)<<endl;
    getch();
}
