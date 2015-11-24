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

int v,n,a[maxn];
ll s[maxn],l[maxn],r[maxn],res,maxt;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n-1) scanf("%d",&a[i]);
    
    l[1]=0;
    FOR(i,2,n) if(a[i-1]>1) l[i]=l[i-1]+(a[i-1]/2)*2; else l[i]=0;
    r[n]=0;
    FORD(i,n-1,1) if(a[i]>1) r[i]=r[i+1]+(a[i]/2)*2; else r[i]=0;
    s[0]=s[1]=0;
    FOR(i,2,n) s[i]=s[i-1]+((a[i-1]&1)?a[i-1]:a[i-1]-1);
    
    res=maxt=0;
    FOR(i,1,n){
        maxt=max(maxt,l[i]-s[i]);
        res=max(res,r[i]+s[i]+maxt);
    }
    
    printf("%I64d",res);
    //getch();
    return 0;
}
