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

vector<pii> a;

ll sqr(int v){ return ll(v)*v;}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int x1,x2,y1,y2;
    REP(i,4){
        cin>>x1>>y1>>x2>>y2;
        a.pb(pii(x1,y1)); a.pb(pii(x2,y2));
    }
    sort(a.begin(),a.end());
    vector<pii>::iterator it=unique(a.begin(), a.end());
    a.resize(it-a.begin());
    if(sz(a)!=4){cout<<"NO"; return 0;}
    vector<ll> list;
    FOR(i,0,2) FOR(j,i+1,3)
        list.pb(sqr(a[i].fi-a[j].fi)+sqr(a[i].se-a[j].se));
    sort(list.begin(),list.end());
    if(list[0]==list[1] && list[2]==list[3] && list[0]!=list[4] && list[4]==list[5] && list[5]==list[0]+list[3])
        cout<<"YES";
    else 
        cout<<"NO";
    //getch();
    return 0;
}
