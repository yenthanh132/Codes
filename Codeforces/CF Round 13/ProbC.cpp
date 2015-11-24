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
#define oo 1e18+7

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 5001;

ll f[2][maxn],n,m;
vector<int> a,b;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    a.resize(n);
    REP(i,n) scanf("%d",&a[i]);
    b=a;
    sort(b.begin(),b.end());
    vector<int>::iterator it=unique(b.begin(),b.end());
    b.resize(it-b.begin()); m=it-b.begin();
    int flag=0;
    ll minv;
    REP(j,m) f[0][j]=abs(a[0]-b[j]);
    FOR(i,1,n-1){
        minv=oo;
        flag^=1;
        REP(j,m){
            minv=min(minv,f[flag^1][j]);
            f[flag][j]=minv+abs(a[i]-b[j]);
        }
    }
    minv=oo;
    REP(j,m) minv=min(minv,f[flag][j]);
    printf("%I64d",minv);
    //getch();
    return 0;
}
