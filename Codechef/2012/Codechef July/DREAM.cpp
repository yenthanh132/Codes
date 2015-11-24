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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n,k;
vector<pii> a;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    int v;
    REP(i,n){
        scanf("%d",&v);
        a.pb(pii(v,i));
    }
    sort(a.begin(),a.end());
    int i=0,j,c=0;
    while(i<n){
        c++;
        j=i;
        while(j<n-1 && a[j+1].fi==a[i].fi && a[j+1].se-a[i].se<k) j++;
        i=j+1;
    }
    printf("%d",c);
    //getch();
    return 0;
}
