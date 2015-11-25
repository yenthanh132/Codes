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

int n,k;
vector<string> a,b;

int count(vector<string>& a){
    sort(a.begin(),a.end());
    int res=k;
    FOR(i,1,n-1) REP(j,k) if(a[i][j]!=a[i-1][j]) {res+=k-j;break;}
    return res;
}

int main(){
    scanf("%d%d\n",&n,&k);
    char buf[207];
    string s;
    FOR(i,1,n){
        gets(buf);
        a.pb(string(buf,buf+k));
        s=string(buf+k,buf+2*k);
        reverse(s.begin(),s.end());
        b.pb(s);
    }
    printf("%d\n",count(a)+count(b));   
    return 0;
}
