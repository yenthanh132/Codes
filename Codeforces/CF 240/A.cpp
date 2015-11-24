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


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    if(k<n/2 || (n==1 && k>0)){
        puts("-1");
        return 0;   
    }
    int v=k-(n-2)/2;
    if(v>=1){
        printf("%d %d ",v,v*2);
        n-=2;   
    }
    v=round(1e9);
    while(n>=2){
        printf("%d %d ",v,v-1);
        n-=2;
        v-=2;
    }
    if(n&1) printf("%d",v);
        
    return 0;
        
    
   
}
