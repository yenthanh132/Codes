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

const int maxv=200;
int r,n,m,k;
int v[20],a[20],res[20];
bool dp[maxv+1];
 
void generate(){
    FOR(i,1,n) a[i]=rand()%(m-2+1)+2;
}

bool checkOk(){
    reset(dp,0);  
    dp[1]=1;
    FOR(i,1,n) FORD(v,maxv,1) if(dp[v] && v*a[i]<=maxv) dp[v*a[i]]=1;
    FOR(i,1,k) if(!dp[v[i]]) return 0;
    return 1;
}

void printResult(){
    FOR(i,1,n) printf("%d",res[i]); puts("");
}

int main(){
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C-small-1-attempt0.out","w",stdout);
    int T;
    srand(time(NULL));
    scanf("%d",&T);
    FOR(tt,1,T){
        printf("Case #%d:\n",tt);
        scanf("%d%d%d%d",&r,&n,&m,&k);
        REP(index,r){
            FOR(i,1,k) scanf("%d",&v[i]);
            FOR(i,1,n) res[i]=2;
            REP(i,200){
                generate();
                if(checkOk()){
                    FOR(i,1,n) res[i]=a[i];
                    break;
                }
            }
            printResult();
        }
    }
    
    return 0;
}
            
