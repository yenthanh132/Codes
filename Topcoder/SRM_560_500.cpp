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


int n;
struct square{int x, y, r;} list[107];

bool giao(double x1,double y1, double x2, double y2){
    return (x2<y1 && x1<=x2) || (x1<y2 && x2<=x1);
}

bool foundpoint(double x, double y, int k){
    REP(i,n) if((list[i].x-x)<=k/2 && (list[i].y-y)<=k/2) return 1;
    return 0;
}

bool hit(const square &a, const square &b){
    int dx=abs(a.x-b.x)-(a.r+b.r)/2;
    if(dx==1){
        double y1=max(a.y-a.r/2.0,b.y-b.r/2.0);
        double y2=min(a.y+a.r/2.0,b.y+b.r/2.0);
        for(double y=y1+0.5; y<y2; y+=1) 
            if(!foundpoint((a.x+b.x)/2.0,y,a.r)) return 1;
    }
    int dy=abs(a.y-b.y)-(a.r+b.r)/2;
    if(dy==1){
        double x1=max(a.x-a.r/2.0,b.x-b.r/2.0);
        double x2=min(a.x+a.r/2.0,b.x+b.r/2.0);
        for(double x=x1+0.5; x<x2; x+=1) 
            if(!foundpoint(x,(a.y+b.y)/2,a.r)) return 1;
    }
    return 0;
}

bool stop(){
    REP(i,n-1) FOR(j,i+1,n-1) if(hit(list[i],list[j])) return 1;
    return 0;
}

void inc_square(){
    REP(i,n) list[i].r++;
}

class DrawingPointsDivOne {
public:
	int maxSteps(vector <int> x, vector <int> y) {
		n=sz(x);
		int res=1;
		REP(i,n){
            list[i].x=x[i];
            list[i].y=y[i];
            list[i].r=0;
        }
        inc_square();
        while(!stop()){
            res++;
            inc_square();
            if(res>1000) break;
        }
        if(res>1000) return -1; else return res-1;
	}
};


<%:testing-code%>


//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
