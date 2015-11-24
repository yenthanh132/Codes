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

int cnt[maxn],pos[maxn],a[maxn];
int n,ans[maxn];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    bool ok=1;
    FOR(i,1,99999) if(cnt[i]<cnt[i+1]){
        ok=0;
        break;
    }
    if(!ok) puts("-1");
    else{
        printf("%d",cnt[1]);
        FOR(i,1,n) ans[i]=++pos[a[i]], printf(" %d",ans[i]);            
    }
    //getch();
    return 0;
}
