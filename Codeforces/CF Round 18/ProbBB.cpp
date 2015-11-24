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

#include <conio.h>
int main(){
    int n,d,m,l,k;
    ll v,v2,t;
    cin>>n>>d>>m>>l;
    t=ll(m)*n-m+l; v2=(t/d)*d; while(v2<=t) v2+=d;
    for(k=0;;k++){
        v=ll(k)*d;
        if(l<v%m) break;
        if(k>int(1e7)){
            v=oo;
            break;
        }
    }
    cout<<min(v,v2);
    //getch();
    return 0;
}
