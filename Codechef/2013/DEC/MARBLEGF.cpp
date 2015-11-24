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

const int maxn=1000007;

ll BIT[maxn];
int n,q;

void update(int p, int v){
    for(int i=p; i<=n; i+=i&(-i)) BIT[i]+=v;
}

ll get(int p){
    ll res=0;
    for(int i=p; i; i-=i&(-i)) res+=BIT[i];
    return res;
}
    
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char buf[10];
    int u,v;
    scanf("%d%d",&n,&q);
    FOR(i,1,n){
        scanf("%d",&v);
        update(i,v);   
    }
    FOR(i,1,q){
        scanf("%s%d%d",buf,&u,&v);
        if(buf[0]=='S'){
            printf("%lld\n",get(v+1)-get(u));
        }else if(buf[0]=='G'){
            update(u+1,v);
        }else
            update(u+1,-v);
    }
}
