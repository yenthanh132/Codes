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

string s;
bool col[9];

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int res=0;
    REP(i,8){
        cin>>s;
        vector<int> l;
        REP(j,sz(s)) if(s[j]=='B') l.pb(j);
        if(sz(l)<8) REP(j,sz(l)) col[l[j]]=1; else res++;
    }
    if(res<8) REP(i,8) if(col[i]) res++;
    cout<<res;
    return 0;
}
