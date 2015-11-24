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

const int maxn=200007;

int n,a[maxn],d[maxn],q;
vector<int> list;
int main(){
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&a[i]);
    int u,v;
    FOR(i,1,q){
        scanf("%d%d",&u,&v);
        d[u]++;
        d[v+1]--;
    }
    v=0;
    FOR(i,1,n){
        v+=d[i];
        list.pb(v);
    }
    sort(list.begin(),list.end());
    sort(a+1,a+n+1);
    ll res=0;
    FOR(i,1,n) res+=1ll*a[i]*list[i-1];
    cout<<res<<endl;
}
