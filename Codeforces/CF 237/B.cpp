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
const int dy[4]={0,1,0,-1};

double a,d;
int n;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);  
    scanf("%lf%lf%d",&a,&d,&n);
    int m=int(floor(d/(a*4) - 1e-9));  
    d-=m*(a*4);
    while(fabs(d-a*4)>1e-9 && d>a*4) d-=a*4;
    int k=0;
    double x=0,y=0,x0,y0;
    REP(i,n){
        double t=d;
        while(fabs(t)>1e-9){
            x0=x+dx[k]*t; y0=y+dy[k]*t;
            
            if(x0<0 || x0>a || y0<0 || y0>a){
                if(x0<0) t-=x, x0=0;
                if(x0>a) t-=a-x, x0=a;
                if(y0<0) t-=y, y0=0;
                if(y0>a) t-=a-y, y0=a;
                x=x0; y=y0;
                k=(k+1)%4;
            }else{
                x=x0; y=y0;
                break;     
            }       
            
        }
        printf("%0.9lf %0.9lf\n",x,y);
    }
    return 0;
}
