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

const int maxn=100007;


ll BIT[maxn];
int n,m;

void update(int pos, ll v){
    for(int i=pos; i<=n; i+=i&(-i)) BIT[i]=max(BIT[i],v);
}

ll get(int pos){
    ll res=0;
    for(int i=pos; i; i-=i&(-i)) res=max(res,BIT[i]);
    return res;
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    int w,h;
    FOR(i,1,n){
        scanf("%d",&w);
        update(i,w);
    }
    scanf("%d",&m);
    FOR(i,1,m){
        scanf("%d%d",&w,&h);
        printf("%I64d\n",get(w));
        update(1,h+get(w));
    }
    return 0;
}
