#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define reset(a,b) memset(a,b,sizeof(a))

using namespace std;

class TwoRectangles {
public:
	string describeIntersection(vector <int>, vector <int>);
};

string TwoRectangles::describeIntersection(vector <int> A, vector <int> B) {
	int arr[1001][1001];
	reset(arr,0);
	FOR(x,A[0],A[2]) FOR(y,A[1],A[3]) arr[x][y]++;
	FOR(x,B[0],B[2]) FOR(y,B[1],B[3]) arr[x][y]++;
	bool rec=false;
	int maxv=0,count2=0;
	FOR(x,0,1000) FOR(y,0,1000){
        maxv=max(maxv,arr[x][y]);
        if(arr[x][y]==2) count2++;
        if(x<1000 && y<1000 && arr[x][y]==2 && arr[x+1][y]==2 && arr[x][y+1]==2) rec=true;
    }
	if(maxv<2) return "none";
	else if(count2==1) return "point";
	else if(!rec) return "segment";
	else return "rectangle";
}
