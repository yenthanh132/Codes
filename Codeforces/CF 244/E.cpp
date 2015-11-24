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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=1000007;

int a[maxn],n,m;
ll res,sum;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    
    sum=0;
    ll cl=0, cr=0;
    FORD(i,n,1){
        if(i<n) sum+=cr*(a[i+1]-a[i]);
        if((n-i)%m==0) ++cr;
    }
    res=sum;
    cl=0;
    
    if((n-1)%m==0) --cr; 
    FOR(i,2,n){        
        if((i-2)%m==0) ++cl;
        sum+=cl*(a[i]-a[i-1]);        
        sum-=cr*(a[i]-a[i-1]);    
        if((n-i)%m==0) --cr;
        res=min(res,sum);
    }
    
    cout<<res*2<<endl;
    
    return 0;
}
