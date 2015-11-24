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

ll cal(int v){
    int a[10];
    int n=0;
    while(v){
        a[++n]=v%10;
        v/=10;
    }
    ll t=1;
    for(int i=n; i>0; i-=2) t=t*a[i];
    for(int i=n-1; i>0; i-=2) 
        if(a[i]==0 || t%a[i]!=0) return -1; else t/=a[i];
    return t;
}

int solve(int l, ll v){
    ll t;
    ll lbound,ubound;
    lbound=1;
    FOR(i,2,l) lbound*=10;
    ubound=lbound*10-1;
    int res=0;
    FOR(i,lbound,ubound) if(cal(i)==v) res++;
    return res;
}
    
int main(){
    int test;
    cin>>test;
    int l;
    ll v;
    REP(i,test){
        cin>>l>>v;
        cout<<solve(l,v)<<endl;
    }
    return 0;
}
