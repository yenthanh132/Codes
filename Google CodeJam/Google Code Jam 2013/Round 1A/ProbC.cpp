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

const int maxr=8007;
int r,n,m,k;
int v[maxr][20],a[20],res[maxr][20],d[20];
set<ll> mys;
bool marked[maxr];
 
void duyet(int i){
    if(i>n){
        ll v=1;
        FOR(j,1,n) if(d[j]) v*=a[j];
        mys.insert(v);
        return;
    }
    REP(v,2){
        d[i]=v;
        duyet(i+1);
    }
}
 
void generate(){
    FOR(i,1,n) a[i]=rand()%(m-2+1)+2;
    mys.clear();
    duyet(1);
}

bool checkOk(int i){
    FOR(j,1,n) if(mys.find(v[i][j])==mys.end()) return 0;
    return 1;   
}

int main(){
    freopen("C-small-2-attempt2.in","r",stdin);
    freopen("C-small-2-attempt2.out","w",stdout);
    int T;
    srand(time(NULL));
    scanf("%d",&T);
    FOR(tt,1,T){
        printf("Case #%d:\n",tt);
        scanf("%d%d%d%d",&r,&n,&m,&k);
        FOR(index,1,r){
            FOR(i,1,k) scanf("%d",&v[index][i]);
            FOR(i,1,n) res[index][i]=rand()%(m-2+1)+2;
        }
        int cnt=0;
        reset(marked,1);
        while(true){
            generate();
            FOR(i,1,r) if(marked[i])
                if(checkOk(i)){
                    marked[i]=0;
                    FOR(j,1,n) res[i][j]=a[j];
                    cnt++;
                    if(cnt>=7500) goto end;
                }
        }
        end:
        FOR(i,1,r){
            FOR(j,1,n) printf("%d",res[i][j]);
            puts("");
        }
    }
    return 0;
}
            
