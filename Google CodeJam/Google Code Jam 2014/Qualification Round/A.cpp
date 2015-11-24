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

int a[5][5],T,x,c[20];

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    FOR(tt,1,T){
        reset(c,0);
        
        scanf("%d",&x);
        FOR(i,1,4) FOR(j,1,4) scanf("%d",&a[i][j]);
        FOR(j,1,4) ++c[a[x][j]];
        
        scanf("%d",&x);
        FOR(i,1,4) FOR(j,1,4) scanf("%d",&a[i][j]);
        FOR(j,1,4) ++c[a[x][j]];
        
        int res,cnt=0;
        FOR(v,1,16) if(c[v]==2){
            res=v;
            ++cnt;
        }
        printf("Case #%d: ",tt);
        
        if(cnt==0) puts("Volunteer cheated!");
        else if(cnt>1) puts("Bad magician!");
        else printf("%d\n",res);
    }   
    return 0;
}
