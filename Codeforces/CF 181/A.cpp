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

vector<int> a,list[3];
int cnt;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int n,v;
    cin>>n;
    cnt=0;
    REP(i,n){
        cin>>v;
        if(v==0) list[2].pb(v);
        else{
            if(v<0) a.pb(v);
            else list[1].pb(v);
        }
    }
    list[0].pb(a.back()); a.pop_back();
    if(list[1].empty()){
        list[1].pb(a.back()); a.pop_back();    
        list[1].pb(a.back()); a.pop_back();
    }
    REP(j,sz(a)) list[2].pb(a[j]);
    REP(i,3){
        cout<<sz(list[i]);
        REP(j,sz(list[i])) cout<<' '<<list[i][j];
        cout<<endl;
    }
    //getch();
    return 0;
}
