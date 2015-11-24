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

int main(){
    string s;
    getline(cin,s);
    int i=sz(s)-1;
    while(s[i]==' ' || s[i]=='?') i--;
    if(s[i]=='a' || s[i]=='A' || s[i]=='i' || s[i]=='i'     
    || s[i]=='o' || s[i]=='O' || s[i]=='e' || s[i]=='E'
    || s[i]=='y' || s[i]=='Y' || s[i]=='u' || s[i]=='U') cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
