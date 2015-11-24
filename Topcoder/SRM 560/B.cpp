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

int sum[400][400];

bool check(int v, vector<int> &x, vector<int> &y){
    int n=sz(x);
    reset(sum,0);
    REP(i,n){
        sum[x[i]][y[i]]++;
        sum[x[i]+v][y[i]]--;
        sum[x[i]][y[i]+v]--;
        sum[x[i]+v][y[i]+v]++;
    }
    FOR(i,1,400) FOR(j,1,400) sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    FOR(i,1,400) FOR(j,1,400) sum[i][j]=min(sum[i][j],1);
    FOR(i,1,400) FOR(j,1,400) sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    int cnt=0;
    FOR(i,0,400-v) FOR(j,0,400-v)
        if(sum[i+v][j+v]-sum[i][j+v]-sum[i+v][j]+sum[i][j]==v*v) cnt++;
    return cnt==n;
}

class DrawingPointsDivOne {
public:
	int maxSteps(vector <int> x, vector <int> y) {
		int n=sz(x);
		REP(i,n) x[i]=(x[i]+71), y[i]=(y[i]+71);
		if(check(200,x,y)) return -1;
        int l=0, r=200,mid,res=0;
        while(l<=r){
            mid=(l+r)>>1;
            if(check(mid,x,y)){
                res=mid-1;
                l=mid+1;
            }else r=mid-1;
        }
        return res;		
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
