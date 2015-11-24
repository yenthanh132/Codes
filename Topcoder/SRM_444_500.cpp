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

class FourBlocks {
public:
	int maxScore(vector <string>);
};

int FourBlocks::maxScore(vector <string> grid) {
	int m=sz(grid), n=sz(grid[0]), f[10][25][10][25];
	reset(f,0);
	REP(i,m-1) REP(j,n-1) if(grid[i][j]=='.' && grid[i][j+1]=='.' && grid[i+1][j]=='.' && grid[i+1][j+1]=='.')
	   f[i][j][i+1][j+1]=16;
	REP(i,m) REP(j,n) f[i][j][i][j]=1;
	FOR(leni,1,m) FOR(lenj,1,n)
	   FOR(i,0,m-leni) FOR(j,0,n-lenj){
            int ii=i+leni-1, jj=j+lenj-1;
            FOR(x,i,ii-1) 
                f[i][j][ii][jj]=max(f[i][j][ii][jj], f[i][j][x][jj]+f[x+1][j][ii][jj]);
            FOR(y,j,jj-1)
                f[i][j][ii][jj]=max(f[i][j][ii][jj], f[i][j][ii][y]+f[i][y+1][ii][jj]);
        }
    return f[0][0][m-1][n-1];
}

#include <conio.h>
int main(){
    FourBlocks test;
    string ds[10]={".1........1.......1.....", 
                   "..1..............1...1..", 
                   "......1.1..1....1.......", 
                   ".....................1..", 
                   "........................", 
                   "......11.......1........", 
                   "..1..........11.........", 
                   "...........1............"};
    vector<string> a;
    REP(i,8) a.pb(ds[i]);
    cout<<test.maxScore(a);
    getch();
}
    
