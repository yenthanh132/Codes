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

string key,str;
char a[101][101];
int m,n;
vector<pii> list;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>key;
    while(key!="THEEND"){
        cin>>str;
        n=sz(key);
        m=sz(str)/n;
        list.clear();
        REP(i,n) list.pb(pii(key[i],i));
        sort(list.begin(),list.end());
        int i=0,j,cnt=0,col;
        while(i<sz(str)){
            j=i+m;
            col=list[cnt++].se;
            REP(x,m) a[x][col]=str[i++];
            i=j;
        }
        REP(x,m) REP(y,n) cout<<a[x][y];
        cout<<endl;
        cin>>key;
    }
    //getch();
    return 0;
}
