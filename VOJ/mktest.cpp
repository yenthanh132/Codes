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

const int n=2;
int a[100001],b[100001],c[100001];

#include <conio.h>
int main(){
    freopen("test.txt","w",stdout);
    srand(time(NULL));
    FOR(i,1,n) a[i]=rand()%11-5;
    FOR(i,1,n) b[i]=rand()%11-5;
    FOR(i,1,n) c[i]=rand()%11-5;
    cout<<n<<endl;
    FOR(i,1,n) cout<<a[i]<<' '; cout<<endl;
    FOR(i,1,n) cout<<b[i]<<' '; cout<<endl;
    FOR(i,1,n) cout<<c[i]<<' '; cout<<endl;
    
    int res=0;
    FOR(i,1,n) FOR(j,1,n) FOR(k,1,n) if(a[i]+b[j]==c[k]){res++;;}
    cout<<res<<endl;
    //getch();
    return 0;
}
