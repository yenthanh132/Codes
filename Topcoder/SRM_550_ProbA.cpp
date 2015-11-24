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

const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};

bool d[201][201];

class RotatingBot {
public:
	int minArea(vector <int> a) {
		int minx,maxx,miny,maxy,x,y;
		x=y=minx=miny=maxx=maxy=100;
		int k=0,n=sz(a);
		reset(d,0); d[x][y]=1;
		REP(i,n){
            REP(j,a[i]){
                x+=dx[k]; y+=dy[k];
                minx=min(minx,x); maxx=max(maxx,x);
                miny=min(miny,y); maxy=max(maxy,y);
                if(d[x][y]) return -1;
                d[x][y]=1;
            }
            k=(k+1)%4;
        }
        x=y=100; k=0;
        reset(d,0); d[x][y]=1;		
		REP(i,n){
            REP(j,a[i]){
                x+=dx[k], y+=dy[k];
                d[x][y]=1;
            }
            if(i<n-1){
                int xt=x+dx[k],yt=y+dy[k];
                if(d[xt][yt]==0 && minx<=xt && xt<=maxx && miny<=yt && yt<=maxy) return -1;
            }
            k=(k+1)%4;
        }
        return(maxx-minx+1)*(maxy-miny+1);
    }
};



//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
