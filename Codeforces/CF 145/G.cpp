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

int n,c;
vector<int> list[20];

void init(int l, int r, int d){
    if(l==r) return;
    c=max(c,d);   
    int mid=(l+r)/2;
    FOR(v,l,mid) list[d].pb(v);
    init(l,mid,d+1); init(mid+1,r,d+1);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n; 
    c=0;
    init(1,n,1);
    cout<<c<<endl;
    FOR(i,1,c){
        cout<<sz(list[i]);
        REP(j,sz(list[i])) cout<<' '<<list[i][j];
        cout<<endl;
    }
    return 0;
}
