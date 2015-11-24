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
char s[maxn];
int n1,n2,c1,c2;

int main(){
    scanf("%s",s);
    n1=strlen(s);
    c1=c2=0;
    REP(i,n1) if(s[i]=='1') c1++;
    scanf("%s",s);
    n2=strlen(s);
    REP(i,n2) if(s[i]=='1') c2++;
    if(n1==n2 && ((c1>0 && c2>0) || (c1==0 && c2==0))) puts("YES"); else puts("NO");
    return 0;
}
