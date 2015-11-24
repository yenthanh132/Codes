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

char s[500][500], a,b;

int main(){
    int n;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%s",s[i]+1);
    bool ok=1;
    int x=1, y=n;
    a=s[1][1]; b=s[1][2];
    if(a==b) ok=0;
    FOR(i,1,n){
        FOR(j,1,n) if(j!=x && j!=y && s[i][j]!=b) ok=0;
        if(s[i][x]!=a || s[i][y]!=a) ok=0;
        x++;
        y--;
    }   
    if(ok) puts("YES"); else puts("NO");
}
