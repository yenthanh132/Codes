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

int m,n;
char a[1111];
set<int> mys;

int main(){
    
    scanf("%d%d",&m,&n);
    bool ok=1;
    REP(i,m){
        scanf("%s",a+1);
        int x,y;
        FOR(j,1,n) if(a[j]=='S') y=j; else if(a[j]=='G') x=j;
        if(x>y){
            ok=0;
            break;   
        }
        //printf("%s %d %d\n",a+1,x,y);
        mys.insert(y-x);
    }
    int res;
    if(ok) res=sz(mys); else res=-1;
    printf("%d\n",res);
    
    return 0;
}
