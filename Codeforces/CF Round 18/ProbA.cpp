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

int nhan1(int x1,int y1, int x2, int y2){
    return x1*x2+y1*y2;
}

int nhan2(int x1, int y1, int x2, int y2){
    return x1*y2-x2*y1;
}

int sqr(int v){return v*v;}

bool square(int x1, int y1, int x2, int y2, int x3, int y3){
    int a1=sqr(x2-x1)+sqr(y2-y1), a2=sqr(x3-x1)+sqr(y3-y1), a3=sqr(x3-x2)+sqr(y3-y2);
    if(a1>a2) swap(a1,a2); if(a2>a3) swap(a2,a3);
    return(a3==a1+a2 && nhan2(x2-x1,y2-y1,x3-x1,y3-y1)!=0);
}

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int main(){
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(nhan2(x2-x1,y2-y1,x3-x1,y3-y1)==0){
        cout<<"NEITHER";
        return 0;
    }
   
    if(square(x1,y1,x2,y2,x3,y3)){
        cout<<"RIGHT";
        return 0;
    }
    REP(k,4) if(square(x1+dx[k],y1+dy[k],x2,y2,x3,y3) || square(x1,y1,x2+dx[k],y2+dy[k],x3,y3) || square(x1,y1,x2,y2,x3+dx[k],y3+dy[k])){
        cout<<"ALMOST";
        return 0;
    }
    cout<<"NEITHER";
    return 0;
}
    
    
    
    
