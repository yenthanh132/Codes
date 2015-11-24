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
    int a1,b1,c1,a2,b2,c2;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    int d=a1*b2-a2*b1, dx=b1*c2-b2*c1, dy=c1*a2-c2*a1;
    if((a1==b1 && a1==0 && c1!=0) || (a2==b2 && a2==0 && c2!=0)){cout<<0; return 0;}
    if(d==0)
        if(dx==dy && dx==0) cout<<-1;
        else cout<<0;
    else cout<<1;
    return 0;
}
