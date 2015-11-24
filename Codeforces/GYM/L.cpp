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

double sqr(double a){return a*a;}

double cal(double x, double y, double c, double len){
    double hx=sqrt(sqr(x)-sqr(len));
    double hy=sqrt(sqr(y)-sqr(len));
    return hx*hy/(hx+hy);
}

int main(){
    double x,y,c;
    while(cin>>x>>y>>c){
        double left=0, right=min(x,y), mid;
        while(fabs(right-left)>1e-5){
            mid=(left+right)/2;
            if(cal(x,y,c,mid)<c)
                right=mid;
            else left=mid;
        }
        printf("%0.3lf\n",(left+right)/2);
    }
    
    return 0;
    
}
