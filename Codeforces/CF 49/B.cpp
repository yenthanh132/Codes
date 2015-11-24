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

#include <conio.h>
int main(){
    int m,n;
    cin>>m>>n;
    int res1,res2;
    ll area=0;
    int y,y0,x,x0;
    x=1;
    while(x<=m){
        y=int(floor(x*1.25)+1e-9);
        y0=int(ceil(x*0.8)+1e-9);
        if(y>n) y=n;
        if(y>=y0)
            if(1ll*x*y > area || (1ll*x*y==area && x>res1)){
                area=1ll*x*y;
                res1=x;
                res2=y;
            }
        x*=2;   
    }
    y=1;
    while(y<=n){
        x=int(floor(y*1.25)+1e-9);
        x0=int(ceil(y*0.8)+1e-9);
        if(x>m) x=m;
        if(x>=x0)
           if(1ll*x*y > area || (1ll*x*y==area && x>res1)){
                area=1ll*x*y;
                res1=x;
                res2=y;
            }
        y*=2;    
    }
    cout<<res1<<' '<<res2<<endl;
    //getch();
}
