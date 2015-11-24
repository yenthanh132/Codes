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

int a,b,c;
bool prime[2007];
vector<int> plist;
const int mod=1<<30;



ll res(int a, int b, int c, int q){
    if(a==1 && b==1 && c==1) return 1;
    int v=plist[q],x,y,z,t;
    x=y=z=0;
    t=a; while(t) x+=t/v; t/=v;
    t=b; while(t) y+=t/v; t/=v;
    t=c; while(t) z+=t/v; t/=v;
    return res(a/
    
    
}

int main(){
    reset(prime,0);
    prime[2]=1;
    for(int i=3; i<=2000; i+=2) prime[i]=1;
    for(int i=2; i*i<=2000; i++) if(prime[i])
        for(int j=i*i; j<=2000; j+=i*2) prime[j]=0;
    FOR(i,2,2000) if(prime[i]) plist.pb(i),cout<<i<<' ';
    
    cin>>a>>b>>c;
    return 0;
}
