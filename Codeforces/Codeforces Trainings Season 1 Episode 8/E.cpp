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

double R,B,M;

ll fix(ll v){
    if(v%10000>=5000) return v/10000+1;
    else return v/10000;   
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%lf%lf%lf",&R,&B,&M);
        ll b=ll(B*100+1e-9); 
        ll m=ll(M*100+1e-9);
        ll r=ll(R*100+1e-9);
        int cnt=0;
        while(1){
            ++cnt;
            if(cnt>1200) break;
            b+=fix(b*r);
            b-=m;
            if(b<=0) break;
        }
        if(cnt>1200) puts("impossible");
        else printf("%d\n",cnt);           
    }   
}
