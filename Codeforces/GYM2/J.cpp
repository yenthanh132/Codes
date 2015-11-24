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

string a,b;
int ca[26],cb[26];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    while(getline(cin,a)){
        getline(cin,b);
        reset(ca,0); reset(cb,0);
        REP(i,sz(a)) ca[a[i]-'a']++;
        REP(i,sz(b)) cb[b[i]-'a']++;
        REP(ch,26) REP(k,min(ca[ch],cb[ch])) putchar(ch+'a');
        puts("");
    }
    //getch();
    return 0;
}
