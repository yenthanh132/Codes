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



class FoxAndFlowerShopDivOne {
public:
    int left[31][1801],right[31][1801],top[31][1801],bot[31][1801],s[2][31][31];
    
    int get(int v, int x1, int y1, int x2, int y2){
        return s[v][x2][y2]-s[v][x1-1][y2]-s[v][x2][y1-1]+s[v][x1-1][y1-1];
    }
    
	int theMaxFlowers(vector <string> a, int maxD) {
		int res,n=sz(a);
        
        FOR(i,1,n) FOR(j,1,n){
            s[0][i][j]=s[0][i-1][j]+s[0][i][j-1]-s[0][i-1][j-1]+int(a[i-1][j-1]=='L');
            s[1][i][j]=s[1][i-1][j]+s[1][i][j-1]-s[1][i-1][j-1]+int(a[i-1][j-1]=='P');
        }
        FOR(x,1,n) REP(v,1801) left[x][v]=right[x][v]=bot[x][n]=top[x][n]=-oo;
        int v,cost;
        FOR(x1,1,n) FOR(y1,1,n) FOR(x2,x1,n) FOR(y2,y1,n){
            v=get(0,x1,y1,x2,y2)-get(1,x1,y1,x2,y2)+900;
            cost=get(0,x1,y1,x2,y2)+get(1,x1,y1,x2,y2);
            left[y1][v]=max(left[y1][v],cost);
            right[y2][v]=max(right[y2][v],cost);
            top[x1][v]=max(top[x1][v],cost);
            bot[x2][v]=max(bot[x2][v],cost);
        }
        FOR(x,2,n) REP(v,1801) left[x][v]=max(left[x][v],left[x-1][v]), top[x][v]=max(top[x][v],top[x-1][v]);
        FORD(x,n-1,1) REP(v,1801) right[x][v]=max(right[x][v],right[x+1][v]), bot[x][v]=max(bot[x][v],bot[x+1][v]);
        
        FOR(x,1,n-1) FOR(v,900-maxD,900+maxD) FOR(v2,900-maxD,900+maxD) if(abs(v-v2)<=maxD){
            res=max(res,left[x][v]+right[x+1][v]);
            res=max(res,top[x][v]+bot[x+1][v]);
        }
        
        
        return res;
	}
};


<%:testing-code%>

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
