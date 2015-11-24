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

const int maxn=1007;

int m,n,k,a[maxn];

int main(){
    cin>>n>>m>>k;
    FOR(i,1,m) a[i]=oo;
    int p,v;
    REP(index,n){
        cin>>p>>v;
        a[p]=min(a[p],v);
    }
    int res=0;
    FOR(i,1,m){
        res+=a[i];
        if(res>oo) res=oo;
    }
    cout<<min(res,k)<<endl;
}
