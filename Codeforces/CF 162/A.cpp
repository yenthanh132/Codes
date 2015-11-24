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
int n,lst1[maxn],lst2[maxn],cl,cr;

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%s",s+1);
    n=strlen(s+1);
    cl=cr=0;
    FOR(i,1,n) if(s[i]=='r') lst1[++cl]=i; else lst2[++cr]=i;
    FOR(i,1,cl) printf("%d\n",lst1[i]);
    FORD(i,cr,1) printf("%d\n",lst2[i]);
    return 0;
}
    
