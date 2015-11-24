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

const int maxn=207;
int x[maxn],y[maxn];
int m,n;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m;
    x[1]=0; y[1]=0;
    x[m]=100000000; y[m]=0;
    int len=1000, yt=0,xt;
    FOR(i,2,m-1){
        yt+=len; len--;
        x[i]=i;
        y[i]=yt;
    }
    len=1000; xt=0;
    yt=1;
    FOR(i,m+1,n){
        y[i]=yt++;
        xt+=len; len--;
        x[i]=xt;
    }
    FOR(i,1,n) cout<<x[i]<<' '<<y[i]<<endl;
    return 0;
}

