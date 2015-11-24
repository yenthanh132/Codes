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

int n,h;
ll f[50][50],pw2[50];


ll getval(int n, int h){
    if(h>n || n>pw2[h]-1) return 0;
    if(n==0) return 1;
    if(f[n][h]!=-1) return f[n][h];
    ll ans=0;
    FOR(j,0,n-1)
        FOR(k,0,h-1)
            if(k<h-1) ans=ans + getval(j,h-1)*getval(n-j-1,k) + getval(j,k)*getval(n-j-1,h-1);
            else ans=ans + getval(j,h-1)*getval(n-j-1,h-1);
    f[n][h]=ans;
    return ans;
}

#include <conio.h>
int main(){
    
    cin>>n>>h;
    REP(i,50) REP(j,50) f[i][j]=-1;
    pw2[0]=1; FOR(i,1,35) pw2[i]=pw2[i-1]*2;
    ll res=0;
    FOR(i,h,n) res+=getval(n,i);
    cout<<res;
    //getch();
    return 0;
}
