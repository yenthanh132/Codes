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

ll a[100007];
int n,k;

void swap(){
    ll maxv=a[1];
    FOR(i,2,n) maxv=max(maxv,a[i]);
    FOR(i,1,n) a[i]=maxv-a[i];
}

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}


int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    read(n); read(k);
    FOR(i,1,n) read(a[i]);
    if(k>=1) swap();
    if(k>=2){
        swap();
        if(k&1) swap();
    }
    FOR(i,1,n) printf("%lld ",a[i]);
    return 0;
}
