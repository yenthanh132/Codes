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

int n,m,k;
ll a[maxn];
int v[maxn];
pii q[maxn];
ll d[maxn], d2[maxn];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%I64d",&a[i]);
    FOR(i,1,m) scanf("%d%d%d",&q[i].fi,&q[i].se,&v[i]);
    int l,r;
    FOR(i,1,k){
        scanf("%d%d",&l,&r);
        d[l]++; d[r+1]--;
    }
    ll mul=0;
    FOR(i,1,m){
        mul+=d[i];
        d2[q[i].fi]+=mul*v[i];
        d2[q[i].se+1]-=mul*v[i];
    }
    
    ll val=0;
    FOR(i,1,n){
        val+=d2[i];
        printf("%I64d ",a[i]+val);
    }
    
    //getch();
    return 0;
}
