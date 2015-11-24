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

#include <conio.h>
int main(){
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    freopen("input.txt","r",stdin);
    int test,a,b,k;
    scanf("%d",&test);
    FOR(tt,1,test){
        printf("Case #%d: ",tt);
        int res=0;
        scanf("%d%d%d",&a,&b,&k);
        REP(i,a) REP(j,b) 
            if((i&j)>=k){
                ++res;
                cout<<i<<' '<<j<<endl;
            }
        printf("%d\n",res);   
    }
    getch();
    return 0;
}
