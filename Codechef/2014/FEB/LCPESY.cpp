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

char s[10007];
int n,c[2][300];

int main(){
    int T;
    scanf("%d",&T);
    REP(tt,T){
        reset(c,0);
        REP(i,2){
            scanf("%s",s);
            REP(j,strlen(s)) ++c[i][s[j]];
        }
        int res=0;
        REP(i,256) res+=min(c[0][i],c[1][i]);
        printf("%d\n",res);
    }   
    return 0;
}
