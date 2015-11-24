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

int a[333][333],m,n,k;
vector<pii> res[333*333];

void inc(int &x, int &y, int &t){
        y+=t;
        if(y>n){
            x++;
            y=n;
            t=-1;
        }
        if(y<1){
            y=1;
            x++;
            t=1;
        }
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>m>>n>>k;
    int x=1, y=1, t=1;
    FOR(i,1,k){
        res[i].pb(pii(x,y));
        inc(x,y,t);
        res[i].pb(pii(x,y));
        inc(x,y,t);
        if(i==k){
            while(x<=m){
                res[i].pb(pii(x,y));
                inc(x,y,t);
            }
        }
    }
    FOR(i,1,k){
        printf("%d",sz(res[i]));
        REP(j,sz(res[i])) printf(" %d %d",res[i][j].fi,res[i][j].se);
        puts("");
    }
}

