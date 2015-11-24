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

const int maxn=207;

int test,c[52];
char s[maxn];

int main(){
    scanf("%d",&test);
    REP(index,test){
        scanf("%s",s);
        reset(c,0);
        REP(i,strlen(s)) if(s[i]>'Z') c[s[i]-'a'+26]++; else c[s[i]-'A']++;
        int res=0;
        REP(i,52) res+=(c[i]+1)/2;
        printf("%d\n",res);
    }
    return 0;
}
