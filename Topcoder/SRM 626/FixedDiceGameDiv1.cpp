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


const int maxn=57;
double f[maxn][maxn*maxn],g[maxn][maxn*maxn];
double a1[maxn*maxn],a2[maxn*maxn];

struct FixedDiceGameDiv1 {
    
    
    
    void calc(int a, int b, double *arr){
        FOR(i,0,a) FOR(j,0,a*b) f[i][j]=0;
        f[0][0]=1;
        FOR(i,0,a-1) FOR(j,0,a*b)
            FOR(v,1,b) f[i+1][j+v]+=f[i][j]/b;
        FOR(j,0,a*b) arr[j]=f[a][j];
    }
    
	double getExpectation(int a, int b, int c, int d) {
        calc(a,b,a1); 
        calc(c,d,a2);
        double res=0,sum=0;
        FOR(v,2,a*b) FOR(v2,1,min(v-1,c*d)){
            res+=v*a1[v]*a2[v2];
            sum+=a1[v]*a2[v2];  
        }
        if(sum==0) return -1;
        return res/sum;
	}
};



// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]
// Powered by CodeProcessor
