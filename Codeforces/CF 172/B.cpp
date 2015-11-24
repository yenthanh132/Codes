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

#include <conio.h>
const int maxn=100007;

int n,a[maxn],res,Left[maxn],Right[maxn];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    res=0;
    FOR(i,1,n){
        int j=i-1;
        while(j>0 && a[j]<a[i]) j=Left[j];
        if(j>0) res=max(res,a[i]^a[j]);
        Left[i]=j;
    }
    FORD(i,n,1){
        int j=i+1;
        while(j<=n && a[j]<a[i]) j=Right[j];
        if(j<=n) res=max(res,a[i]^a[j]);
        Right[i]=j;
    }
    printf("%d\n",res);
    return 0;
}
    
