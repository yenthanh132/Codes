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

string s1,s2;
int c[52];

int id(char ch){
    if(ch<'a') return ch-'A';
    else return ch-'a'+26;
}

int main(){
    getline(cin,s1);
    getline(cin,s2);
    REP(i,sz(s1)) if(s1[i]!=' ') c[id(s1[i])]++;
    bool ok=1;
    REP(i,sz(s2)) if(s2[i]!=' '){
        c[id(s2[i])]--;
        if(c[id(s2[i])]<0) ok=0;
    }
    if(ok) puts("YES"); else puts("NO");
    return 0;
}
