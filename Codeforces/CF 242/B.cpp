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

int x[1007],y[1007];
int k[1007],s,n;

bool check(int d2){
    int t=0;
    FOR(i,1,n) if(x[i]*x[i] + y[i]*y[i] <= d2){
        t+=k[i];
        if(t+s>=1000000) return 1;
    }   
    return 0;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    scanf("%d%d",&n,&s);
    int t=0;
    FOR(i,1,n) scanf("%d%d%d",&x[i],&y[i],&k[i]), t+=k[i];
    if(s+t<1000000){
        puts("-1");
        return 0;           
    }
    int l=0, r=oo, mid,res;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    printf("%0.9lf\n",sqrt(res));
    
    return 0;
}
