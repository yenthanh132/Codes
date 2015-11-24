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

//fast input
template<typename T>
void readNumber(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}

int f[1000007];

int main(){
    int test,v,n,g;
    f[0]=f[1]=1;
    FOR(i,2,1000000) f[i]=(f[i-1]+f[i-2])%oo;
    FOR(i,1,1000000){
        v=f[i]; f[i]=0;
        while(v){
            f[i]+=v%2;
            v>>=1;
        }
    }
    readNumber(test);
    REP(index,test){
        readNumber(n); readNumber(g);
        if(f[n]==g) puts("CORRECT"); else puts("INCORRECT");
    }
    return 0;
}
        
