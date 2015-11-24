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

char s[maxn],r[maxn];
int n,c1[32],c2[32];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int test;
    scanf("%d",&test);
    REP(i,test){
        reset(c1,0); reset(c2,0);
        scanf("%s %s",s,r);
        n=strlen(s);
        REP(i,n) c1[s[i]-'a']++;
        n=strlen(r);
        REP(i,n) c2[r[i]-'a']++;
        bool ok=0,equal=1;
        REP(i,26){
            if(c1[i]*c2[i]==0 && c1[i]+c2[i]>0){
                ok=1;
                break;
            }
            if(c1[i]!=c2[i]) equal=0;
        }
        ok=ok||equal;
        if(ok) puts("YES"); else puts("NO");
    }
    //getch();
    return 0;
}
