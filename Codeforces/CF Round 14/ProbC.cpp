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

struct seg{ll x1,y1,x2,y2,len;};

ll val(ll x1, ll y1, ll x2, ll y2, ll x, ll y){
    return((y2-y1)*(x-x1)+(x1-x2)*(y-y1));
}

bool vuonggoc(seg &a, seg &b){
    return((a.x2-a.x1)*(b.x2-b.x1)+(a.y2-a.y1)*(b.y2-b.y1)==0);
}

bool songsong(seg &a, seg &b){
    return((a.x2-a.x1)*(b.y2-b.y1)-(b.x2-b.x1)*(a.y2-a.y1) == 0 && val(a.x1,a.y1,a.x2,a.y2,b.x1,b.y1)!=0);
}

bool mycmp(const seg &a, const seg &b){
    return (a.len<b.len) || (a.len==b.len && atan2(abs(a.y2-a.y1),abs(a.x2-a.x1))<atan2(abs(b.y2-b.y1),abs(b.x2-b.x1)));
}

ll sqr(ll v){ return v*v;}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    seg a[4]; 
    REP(i,4) cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2, a[i].len=sqr(a[i].x1-a[i].x2)+sqr(a[i].y1-a[i].y2);
    sort(a,a+4,mycmp);
    vector<pii> list;
    REP(i,4) list.pb(pii(a[i].x1,a[i].y1)), list.pb(pii(a[i].x2,a[i].y2));
    sort(list.begin(),list.end());
    vector<pii>::iterator it=unique(list.begin(),list.end());
    if(int(it-list.begin())==4 && a[0].len==a[1].len && a[2].len==a[3].len
    && songsong(a[0],a[1]) && songsong(a[2],a[3]) && vuonggoc(a[0],a[2]))
        cout<<"YES";
    else cout<<"NO";
    //getch();
    return 0;
}
