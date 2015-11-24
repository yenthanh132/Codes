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

int t,x,y;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    REP(tt,t){
        scanf("%d%d",&x,&y);
        if(x<0) x=-x;
        if(y<0) y=-y;
        int res=min(x,y);
        x-=res; y-=res;
        res*=2;
        if(x>0){
            res+=x*2;
            if(x&1) ++res;
        }
        if(y>0){
            res+=y*2-1;
            if(y%2==0) ++res;
        }
        printf("%d\n",res);
    }
}
