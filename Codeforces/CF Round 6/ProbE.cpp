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
#define FOR(a,b,c) for (int a=b,_c=(c);a<=_c;a++)
#define FORD(a,b,c) for (int a=b,_c=(c);a>=_c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#include <conio.h>

const int maxn = 100005;

int n,k,a[maxn],maxlen;
set<pii> tree;
vector<pii> list;

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    maxlen=0;
    int l=1;
    FOR(i,1,n){
        tree.insert(pii(a[i],i));
        while(tree.begin()->fi + k < tree.rbegin()->fi) tree.erase(tree.find(pii(a[l],l))), l++;
        if(maxlen<i-l+1){
            maxlen=sz(tree);
            list.clear();
            list.pb(pii(l,i));
        }else if(maxlen==i-l+1) list.pb(pii(l,i));
    }
    printf("%d %d\n",maxlen,sz(list));
    REP(i,sz(list)) printf("%d %d\n",list[i].fi,list[i].se);
    //getch();
    return 0;
}
