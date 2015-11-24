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

int n,c;
int pos[5007];
vector<pii> list;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    c=0;
    reset(pos,0);
    int v;
    FOR(i,1,n*2){
        scanf("%d",&v);
        if(pos[v]!=0){
            list.pb(pii(pos[v],i));
            pos[v]=0;
            c++;
        }else pos[v]=i;
    }
    if(c<n) puts("-1");
    else{
        REP(i,n) printf("%d %d\n",list[i].fi,list[i].se);
    }
    return 0;
}
