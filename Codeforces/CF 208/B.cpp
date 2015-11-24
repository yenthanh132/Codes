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

const int maxn=300007;

string s1,s2;
int n;

int main(){
    ios::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin>>n;
    s1="<3";
    FOR(i,1,n){
        string st;
        cin>>st;
        s1+=st+"<3";
    }

    cin>>s2;
    int p=0;
    int m=sz(s1);
    REP(i,sz(s2))
        if(p<m && s1[p]==s2[i]) ++p;
    if(p>=m) puts("yes");
    else puts("no");
    return 0;
}
