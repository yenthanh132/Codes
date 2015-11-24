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

const int base = 73471;
const int maxn = 2007;

ll val[maxn],pw[maxn],sbegin,send;
char s[maxn],s1[maxn],s2[maxn];
int n,n1,n2,res;
vector<ll> list;
vector<int> pos;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%s%s%s",s,s1,s2);
    pw[0]=1; val[0]=0;
    n=strlen(s); n1=strlen(s1); n2=strlen(s2);
    FOR(i,1,n){
        val[i]=val[i-1]*base+s[i-1];
        pw[i]=pw[i-1]*base;
    }
    sbegin=send=0;
    REP(i,n1) sbegin=sbegin*base+s1[i];
    REP(i,n2) send=send*base+s2[i];
    ll v;
    FOR(i,1,n){
        if(i>=n1 && val[i]-val[i-n1]*pw[n1]==sbegin) pos.pb(i-n1);
        if(i>=n2 && val[i]-val[i-n2]*pw[n2]==send)
            REP(j,sz(pos)) if(pos[j]<=i-n2){
                v=val[i]-val[pos[j]]*pw[i-pos[j]];
                list.pb(v);
            }
    }
    sort(list.begin(),list.end());
    res=unique(list.begin(),list.end())-list.begin();
    printf("%d\n",res);
    //getch();
    return 0;
}
