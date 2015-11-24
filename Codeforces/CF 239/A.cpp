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


int a,b;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    cin>>a>>b;
    FOR(x,0,1500) FOR(y,0,1500) if(x!=0 && y!=0)
        if(x*x+y*y==a*a)
            FOR(x2,-3000,3000) FOR(y2,-3000,3000) if (x2!=0 && y2!=0)
                if((x2-x)*(x2-x)+(y2-y)*(y2-y)==b*b && ((x-x2)*x + (y-y2)*y ==0)){
                    puts("YES");
                    printf("0 0 %d %d %d %d\n",x,y,x2,y2);
                    return 0;                    
                }
                    
    puts("NO");
    
    
    return 0;   
}
