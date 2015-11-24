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
const double lim=1e-6;
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int n,t;
    vector<pii> a;
    cin>>n>>t;
    int u,v;
    REP(i,n){
        cin>>u>>v;
        a.pb(pii(u,v));
    }
    sort(a.begin(),a.end());
    int res=2;
    REP(i,n-1){
        double val=(a[i+1].fi-1.0*a[i+1].se/2)-(a[i].fi+1.0*a[i].se/2);
        if(fabs(val-t)<lim) res++; else if(val>t) res+=2;
    }
    cout<<res;
    //getch();
    return 0;
}
