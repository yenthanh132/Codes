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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

class UnfoldingTriangles {
public:
	int solve(vector <string>, int);
};

int UnfoldingTriangles::solve(vector <string> grid, int unfoldLimit) {
	int m=sz(grid), n=grid[0].size(), res=-1;
	for(int i=1; i<m; i++)
		for(int j=1;j<n;j++){
            int t=0;
            bool ok=true;
            for(int k=1;min(i,j)-k+1>=0 && ok && t<=unfoldLimit;k++){
                if(i+1<m && grid[i+1][j-k+1]=='#') ok=false;
                if(j+1<n && grid[i-k+1][j+1]=='#') ok=false;
                int c=0;
                for(int z=1,x=i-k+1,y=j;z<=k;z++,x++,y--) 
                    if(grid[x][y]=='.'){ ok=false; break; }
                    else if(grid[x][y]=='/') c++;
                if(c==k && ok) res=max(res,k*(k+1)/2);
                t+=c;
            }
        }
    return res;
}
