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

const int base=73471;
const int maxn=100007;

int a[maxn],next[maxn],n,leftmost;
ll hashval[maxn],hashpw[maxn];
vector<pii> list;

ll gethash(int l, int r){
    return(hashval[r]-hashval[l-1]*hashpw[r-l+1]);
}

bool equal(int i, int next){
    ll v1=gethash(i,next-1);
    ll v2=gethash(next,next*2-i-1);
    return(v1==v2);
}

void solve(){
    map<int,int> pos;
    FORD(i,n,1){
        if(pos[a[i]]!=0) next[i]=pos[a[i]]; else next[i]=-1;
        pos[a[i]]=i;
    }
    FOR(i,1,n) if(next[i]!=-1 && equal(i,next[i])) list.pb(pii(next[i]-i,i));
    sort(list.begin(),list.end());
    REP(i,sz(list)) if(list[i].se>=leftmost) leftmost=list[i].se+list[i].fi;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n); FOR(i,1,n) scanf("%d",a+i);
    
    hashpw[0]=1; FOR(i,1,n) hashpw[i]=hashpw[i-1]*base;
    hashval[0]=0; FOR(i,1,n) hashval[i]=hashval[i-1]*base+a[i];

    leftmost=1;
    solve();
    printf("%d\n",n-leftmost+1);
    FOR(i,leftmost,n) printf("%d ",a[i]);
    //getch();
    return 0;
}
    
