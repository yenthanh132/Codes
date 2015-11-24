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

const int maxn=100007;

int n;
char s[maxn];
stack<char> mys;

int main(){
    gets(s+1);
    n=strlen(s+1);
    if(n&1) cout<<"No"<<endl;
    else{
        FOR(i,1,n)
            if(!mys.empty() && mys.top()==s[i]) mys.pop();
            else mys.push(s[i]); 
        if(!mys.empty()) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
