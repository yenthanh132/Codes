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

const int maxn=1007;

char s[maxn];
int t,n,a[26],b[26];

int main(){
    scanf("%d",&t);
    REP(i,t){
        scanf("%s",s+1);
        n=strlen(s+1);
        reset(a,0); reset(b,0);
        for(int i=1, j=n; i<j; i++, j--) a[s[i]-'a']++, b[s[j]-'a']++;
        bool ok=1;
        REP(i,26) if(a[i]!=b[i]){
            ok=0;
            break;
        }
        if(ok) puts("YES"); else puts("NO");
    }
    return 0;
}
