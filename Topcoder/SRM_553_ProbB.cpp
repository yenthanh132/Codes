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

const int maxn = 107;

int s[2][maxn][maxn],f[maxn][maxn],g[maxn][maxn];


class TwoConvexShapes {
public:
    int m,n,res;
    int getv(vector<string> a){
        int ans=0;
        reset(s,0);
	    FOR(i,1,m) FOR(j,1,n){
            s[0][i][j]=s[0][i][j-1]+(a[i-1][j-1]=='B');
            s[1][i][j]=s[1][i][j-1]+(a[i-1][j-1]=='W');
        }
        reset(f,0);
        FOR(j,0,n) if(s[1][1][j]==0 && s[0][1][n]-s[0][1][j]==0) f[1][j]=1;
        FOR(i,2,m) FOR(j,0,n) if(s[1][i][j]==0 && s[0][i][n]-s[0][i][j]==0) 
            FOR(z,0,j) f[i][j]=(f[i][j]+f[i-1][z])%oo;
        FOR(j,0,n) ans=(ans+f[m][j])%oo;
        
        reset(f,0);
        FOR(j,0,n) if(s[1][1][j]==0 && s[0][1][n]-s[0][1][j]==0) f[1][j]=1;
        FOR(i,2,m) FOR(j,0,n) if(s[1][i][j]==0 && s[0][i][n]-s[0][i][j]==0) 
            FOR(z,j+1,n) f[i][j]=(f[i][j]+f[i-1][z])%oo;
        FOR(j,0,n) ans=(ans+f[m][j])%oo;
        
        //----
        reset(f,0); reset(g,0);
        FOR(j,0,n) if(s[0][1][j]==0 && s[1][1][n]-s[1][1][j]==0){
            f[1][j]=1;
            if(1<=j && j<=n-1) g[1][j]=1; 
        }
        FOR(i,2,m) FOR(j,0,n) if(s[0][i][j]==0 && s[1][i][n]-s[1][i][j]==0)
            FOR(z,0,j){
                f[i][j]=(f[i][j]+f[i-1][z])%oo;
                if(1<=j && j<=n-1) g[i][j]=(g[i][j]+f[i-1][z])%oo; else g[i][j]=(g[i][j]+g[i-1][z])%oo;
            }
        
        FOR(j,0,n) ans=(ans+g[m][j])%oo;
        
        reset(f,0); reset(g,0);
        FOR(j,0,n) if(s[0][1][j]==0 && s[1][1][n]-s[1][1][j]==0){
            f[1][j]=1;
            if(1<=j && j<=n-1) g[1][j]=1; 
        }
        FOR(i,2,m) FOR(j,0,n) if(s[0][i][j]==0 && s[1][i][n]-s[1][i][j]==0)
            FOR(z,j+1,n){
                f[i][j]=(f[i][j]+f[i-1][z])%oo;
                if(1<=j && j<=n-1) g[i][j]=(g[i][j]+f[i-1][z])%oo; else g[i][j]=(g[i][j]+g[i-1][z])%oo;
            }
        
        FOR(j,0,n) ans=(ans+g[m][j])%oo;
        
        return ans;
    }
	int countWays(vector <string> a) {
        m=sz(a); n=sz(a[0]);
		res=getv(a);
		return res;
	}
};
int main(){
    TwoConvexShapes t;
    vector<string> a;
    a.pb("?B?"); a.pb("BBB"); a.pb("?B?");
    cout<<t.countWays(a)<<endl;
    system("pause");
    return 0;
}


//<%:testing-code%>

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
