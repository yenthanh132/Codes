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


int C,n,dp[1<<15];
vector<int> bot, price;

int cal(int id){
    int cbit=0,sum=0;
    REP(i,n) if((id>>i)&1){
        sum+=bot[i];
        cbit++;
    }
    if(sum==C*cbit) return price[C]*cbit;
    else return price[sum%C] + price[C]*(sum/C) + price[0]*(cbit-sum/C-1);
}

int count(int id){
    if(id==0) return 0;
    if(dp[id]!=-1) return dp[id];
    int res=0;
    REP(i,n) if((id>>i)&1) res+=price[bot[i]];
    int mask=id;
    while(mask){
        res=max(res,cal(mask)+count(id^mask));
        mask=(mask-1)&id;
    }
    dp[id]=res;
    return res;
}

class KiwiJuice {
public:
	int theProfit(int C, vector <int> bottles, vector <int> prices) {
		n=sz(bottles);
		bot=bottles;
		::C=C;
		price=prices;
		REP(i,1<<n) dp[i]=-1;
		return count((1<<n)-1);
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
