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

const int base=73471;

vector<ll> res;

string s[100];
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int w,h;

void duyet(int x, int y){
    queue<pii> myqueue;
    vector<pii> list;
    myqueue.push(pii(x,y));
    int minx, miny, maxx,maxy;
    minx=maxx=x; miny=maxy=y;
    s[x][y]='.';
    pii u;
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        list.pb(u);
        REP(k,4){
            int xt=u.fi+dx[k], yt=u.se+dy[k];
            if(xt<1 || xt>h || yt<0 || yt>=w || s[xt][yt]=='.') continue;
            s[xt][yt]='.';
            myqueue.push(pii(xt,yt));
        }
    }
    if(sz(list)<=40) return;
    sort(list.begin(),list.end());
    ll ans=0;
    REP(i,sz(list)) ans=ans*base+list[i].fi, ans=ans*base+list[i].se;
    res.pb(ans);
    cout<<sz(list)<<' '<<ans<<endl;
}

#include <conio.h>
int main(){
    freopen("font\\Arial.in","r",stdin);
    //freopen("font\\out.txt","w",stdout);
    cin>>w>>h;
    FOR(i,1,h) getline(cin,s[i]);
     REP(j,w) FOR(i,1,h) if(s[i][j]=='#') duyet(i,j);
    getch();
    return 0;
}
    
