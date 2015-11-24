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


class TheSquareRootDilemma {
public:
    
    int p[maxn],val[maxn],c;
    
    
	int countPairs(int N, int M) {
        int res=0,v,mul;
	    FOR(i,1,N){
            v=i;
            c=0;
            mul=1;
            for(int j=2; j*j<=v; j++)
                if(v%j==0){
                    p[++c]=0;
                    val[c]=j;
                    while(v%j==0){
                        p[c]++;
                        v/=j;
                    }
                    if(p[c]&1) mul*=j;
                }
            if(v>1) mul*=v, p[++c]=1, val[c]=v;
            res+=int(sqrt(M/mul)+1e-9);
        }
        return res;
    }
                
};


int main(){
TheSquareRootDilemma t;
cout<<t.countPairs(1,99855)<<endl;
system("pause");
return 0;
}

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
