#include <conio.h>
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

const int maxn=300007;

set<int> mys;
int n,m,ans[maxn];
    
int main(){
    //freopen("Test.txt","r",stdin);
    int l,r,x;   
    scanf("%d%d",&n,&m);
    mys.clear();
    FOR(i,1,n) mys.insert(i);
    reset(ans,0);
    REP(t,m){
        scanf("%d%d%d",&l,&r,&x);
        set<int>::iterator it=mys.lower_bound(l),it2;
        while(it!=mys.end() && *it<=r){
            if(*it!=x){
                it2=it++;
                ans[*it2]=x;
                mys.erase(it2);
            }else it++;
        }
    }
    FOR(i,1,n) printf("%d ",ans[i]);
    //getch();
    return 0;
}
