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

const int maxn=5007;
const int base=73471;

int n;
char s[maxn*2],t[maxn];
int S[maxn*2],T[maxn];
map<ll,bool> mm;
ll val[maxn*2],basepow;
bool ok;

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%s",t);
    scanf("%s",s+1);
    n=strlen(s+1);
    FOR(i,1,n-1) s[i+n]=s[i];
    
    basepow=1;
    FOR(i,1,n) basepow*=base;
    FOR(i,1,n*2-1) S[i]=s[i]-'0';
    REP(i,n) T[i]=t[i]-'0';
    
    val[0]=0;
    FOR(i,1,n*2-1) val[i]=val[i-1]*base+S[i];
    FOR(i,n,n*2-1) mm[val[i]-val[i-n]*basepow]=1;
    ok=0;
    FOR(i,1,n){
        ll val=0;
        bool stop=0;
        REP(j,n){
            if(S[i+j]==1 && T[j]==0){
                stop=1;
                break;
            }
            val=val*base+max(S[i+j],T[j]);
        }
        if(stop) break;
        REP(j,n) cout<<max(S[i+j],
        if(mm[val]){
            ok=1;
            break;
        }
    }
    if(ok) puts("Yes"); else puts("No");
    getch();
    return 0;
}
    
