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

ll p10[11];

ll sum(ll n){
    return n*(n+1)/2;     
}

unsigned long long cal(int n){
    if(n==0) return 0;
    ll res=0;
    FOR(i,0,9) if(p10[i+1]>n){
        res+=(sum(n)-sum(p10[i]-1))*(i+1);
        return res;
    }else
        res+=(sum(p10[i+1]-1)-sum(p10[i]-1))*(i+1);
}

int main(){
    p10[0]=1;
    FOR(i,1,10) p10[i]=p10[i-1]*10;
    
    int T;
    scanf("%d",&T);
    REP(tt,T){
        int u,v;
        cin>>u>>v;
        cout<<(cal(v)-cal(u-1))%oo<<endl;
    }
    
    return 0;
}
