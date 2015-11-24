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

const int maxn=100007;

int n,s[maxn],a[maxn],b[maxn],id[maxn];

bool cmp(const int &a, const int &b){
    return s[a]<s[b];
}

#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&s[i]), id[i]=i;
    sort(id+1,id+n+1,cmp);
    FOR(i,1,n/3) a[id[i]]=i-1, b[id[i]]=s[id[i]]-a[id[i]];
    FOR(i,n/3+1,2*n/3) b[id[i]]=i-1, a[id[i]]=s[id[i]]-b[id[i]];
    FOR(i,2*n/3+1,n) b[id[i]]=n-i, a[id[i]]=s[id[i]]-b[id[i]];
    puts("YES");
    FOR(i,1,n) printf("%d ",a[i]);
    puts("");
    FOR(i,1,n) printf("%d ",b[i]);
    //getch();
    return 0;
}
    
