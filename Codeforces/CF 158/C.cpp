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

int n,x,sub;
ll a[maxn];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&x);
    FOR(i,1,n) scanf("%I64d",&a[i]);
    int minv=a[x],pos=x;
    FORD(i,x-1,1) if(minv>a[i]){
        minv=a[i];
        pos=i;
    }
    FORD(i,n,x+1) if(minv>a[i]){
        minv=a[i];
        pos=i;
    }
    ll v=1ll*minv*n;
    if(pos<x){
        FOR(i,pos+1,x) a[i]--, v++;
    }else if(pos>x){
        FOR(i,1,x) a[i]--, v++;
        FOR(i,pos+1,n) a[i]--, v++;
    }
    a[pos]=v;
    FOR(i,1,n) if(i!=pos) a[i]-=minv;
    FOR(i,1,n) printf("%I64d ",a[i]); puts("");
    
    //getch();
    return 0;
}
