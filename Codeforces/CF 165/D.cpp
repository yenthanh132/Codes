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

struct segment{
    int l, r, h, f;
    segment(){}
    segment(int a, int b, int c, int d){
        l=a; r=b; h=c; f=d;
    }
    bool operator < (const segment &a) const{
        return l<a.l;
    }
} a[maxn];
int n;
set<segment> mys;

bool cmp(const segment &a, const segment &b){
    return a.h<b.h;
}

int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d%d",&a[i].h,&a[i].l,&a[i].r);
    sort(a+1,a+n+1,cmp);
    mys.insert(segment(-1000000000,1000000000,0,2000000007));
    FOR(i,1,n){
        set<segment>::iterator i1,i2;
        i1=mys.upper_bound(a[i]);
    }
        
