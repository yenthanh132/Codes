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


const int maxn=100007;
ll f[maxn][3][8];

class AlternateColors2 {
public:
    
    bool ok(int c1, int c2, int id){
        int i=(c1+1)%3;
        while(((id>>i)&1)==0) i=(i+1)%3;
        return i==c2;
    }
    
    ll count(int id, int len){
        int bits=0;
        REP(i,3) if((id>>i)&1) bits++;
        if(bits>len || (len>0 && bits==0)) return 0;
        if(bits==1) return 1; else if(bits==2) return len-1;
        else return 1ll*(len-2)*(len-1)/2;
    }
    
	long long countWays(int n, int k) {
		  reset(f,0);
		  REP(i,1<<3) f[1][0][i]=1;
		  FOR(i,2,k)
		      REP(id,1<<3) if(id)
                   REP(c1,3) if(f[i-1][c1][id])
                        REP(c2,3)
                            if(ok(c1,c2,id)){
                                f[i][c2][id]+=f[i-1][c1][id];
                                //if(i==2) cout<<"-"<<id<<' '<<c1<<' '<<c2<<' '<<f[i-1][c1][id]<<endl;
                                f[i][c2][id-(1<<c2)]+=f[i-1][c1][id];
                                }
        int len=n-k;
        ll res=0;
        REP(id,1<<3){
        //cout<<id<<' '<<f[k][0][id]<<' '<<count(id,len)<<endl;
            res+=f[k][0][id] * count(id,len);     }
        return res;  
	}
};


//<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!

int main(){
    AlternateColors2 t;
    cout<<t.countWays(6,4);
    system("pause");
    return 0;
}

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
