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

int n,d[1000007];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int res=0,v;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&v), res^=v;   
    
    
    FOR(i,2,n){
        int t0 = n/i;
        int t1 = n%i;
        d[0]+=t0;
        d[i]-=t0;
        d[1]++;
        d[t1+1]--;
    }
    v=0;
    FOR(t,0,n){
        v+=d[t];
        if(v&1) res^=t;   
    }
    printf("%d\n",res);
    
}
