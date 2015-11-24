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
#define oo 2000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unsigned long long r,t;

unsigned long long val(ll v){
    unsigned long long s1 = 2*r*v;
    if(s1/2/r!=v) return oo;
    if(s1>t) return oo;
    unsigned long long s2 = v*(2*v-1);
    if(s2/v!=2*v-1) return oo;
    if(s2>t) return oo;
    return s1+s2;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large2.out","w",stdout);
    
    unsigned long long left,right,mid,res;
    
    int T;
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%llu %llu",&r,&t);
        
        res=0; left=1; right=(unsigned long long)(sqrt(t));
        while(left<=right){
            mid=(left+right)/2;
            if(val(mid)<=t){
                res=mid;
                left=mid+1;
            }else right=mid-1;
        }
        
        printf("Case #%d: %llu\n",tt,res);
    }
    
    return 0;
}
    
    
    

    
