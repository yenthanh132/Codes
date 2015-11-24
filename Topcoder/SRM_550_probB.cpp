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

ll pow2[45];

char getv(ll t,ll x, ll y){
    if((x+y)&1) return '.';
    if(x<y) return '.';
    ll i=(x+y)/2+1,j=(x-y)/2+1;
    if(i>t) return '.';
    ll len;
    FORD(k,40,2){
        len=pow2[k];
        if(i<=len/2 && j>len/2) return '.';
        if(i>len/2) i-=len/2;
        if(j>len/2) j-=len/2;
    }
    if(i==1 && j==1) return 'A';
    else if(i==2) return 'B';
    else return '.';
}

class CheckerExpansion {
public:
	vector <string> resultAfter(long long t, long long x0, long long y0, int w, int h) {
		vector<string> ans;
		string st;
		pow2[0]=1; FOR(i,1,40) pow2[i]=pow2[i-1]*2;
		REPD(y,h){
            st="";
            REP(x,w) st=st+getv(t,x0+x,y0+y);
            ans.pb(st);
        }
        return ans;
	}
};


int main(){
    cout<<getv(1,0,0)<<endl;
    system("pause");
}
