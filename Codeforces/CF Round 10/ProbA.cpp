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

vector<pii> list;
int n,p1,p2,p3,t1,t2,res;

#include <conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>p1>>p2>>p3>>t1>>t2;
    int u,v;
    REP(i,n){
        cin>>u>>v;
        list.pb(pii(u,v));
    }
    res=(list[n-1].se-list[0].fi)*p1;
    REP(i,n-1){
        int v=list[i+1].fi-list[i].se;
        res-=(p1-p2)*max(0,v-t1);
        res-=(p2-p3)*max(0,v-t1-t2);
    }
    cout<<res;
    //getch();
    return 0;
}
