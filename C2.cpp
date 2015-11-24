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

int dp(ll n){
    if(n==0) return 0;
    ll mul=0;
    int c=0;
    while(mul*10+1<=n){
        mul=mul*10+1;
        ++c;
    }

    int cost=0,res;
    ll v=0;
    while(v+mul<=n){
        cost+=c;
        v+=mul;
    }
    res=cost+dp(n-v);

    cost=c+1;
    v=mul*10+1;
    while(v-mul>=n){
        cost+=c;
        v-=mul;
    }
    res=min(res,cost+dp(v-n));
    return res;
}

int main(){
    ll n;
    cin>>n;
    cout<<dp(n)<<endl;
}

