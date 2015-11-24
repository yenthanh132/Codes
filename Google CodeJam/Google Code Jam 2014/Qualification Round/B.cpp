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

int T;
double F,C,X;

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    
    scanf("%d",&T);
    FOR(tt,1,T){
        printf("Case #%d: ",tt);
        scanf("%lf %lf %lf",&C,&F,&X);
        double s=0,res=X/2;
        for(int i=1; ; ++i){
            s+=C/(2+(i-1)*F);
            double val=s+X/(2.0+i*F);
            if(val>=res) break;
            res=val;
        }
        printf("%0.7lf\n",res);
    }
}
