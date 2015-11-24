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

pii a[24],trace[1<<24];
int n,xs,ys,f[1<<24],d1[24],d2[24][24];

int sqr(int v){return v*v;};
int dis(int i){return(sqr(a[i].fi-xs)+sqr(a[i].se-ys));}
int dis(int i, int j){ return(sqr(a[i].fi-a[j].fi)+sqr(a[i].se-a[j].se));}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>xs>>ys;
    cin>>n;
    REP(i,n) cin>>a[i].fi>>a[i].se;
    
    REP(i,n) d1[i]=dis(i);
    REP(i,n) REP(j,n) d2[i][j]=dis(i,j);
    
    REP(i,1<<n) f[i]=oo;
    f[0]=0;
    int x, y;
    REP(i,(1<<n)-1){
        x=0;
        while((i>>x)&1) x++;
        if(f[i|(1<<x)]>f[i]+d1[x]*2){
            f[i|(1<<x)]=f[i]+d1[x]*2;
            trace[i|(1<<x)]=pii(x+1,0);
        }
        FOR(y,x+1,n-1) if(!((i>>y)&1) && f[i|(1<<x)|(1<<y)]>f[i]+d1[x]+d1[y]+d2[x][y]){
            f[i|(1<<x)|(1<<y)]=f[i]+d1[x]+d1[y]+d2[x][y];
            trace[i|(1<<x)|(1<<y)]=pii(x+1,y+1);
        }
    }
    
    cout<<f[(1<<n)-1]<<endl;
    vector<int> list;
    int v=(1<<n)-1;
    pii t;
    while(v){
        t=trace[v];
        list.pb(0);
        list.pb(t.fi);
        if(t.se) list.pb(t.se);
        
        v-=(1<<t.fi-1);
        if(t.se) v-=(1<<t.se-1);
    }
    list.pb(0);
    REP(i,sz(list)) cout<<list[i]<<' ';
    //getch();
    return 0;
}
