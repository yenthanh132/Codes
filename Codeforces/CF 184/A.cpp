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

const int maxn=106;

int n,v,m,a[maxn];
vector<int> list;

#include <conio.h>

bool ok(int a, int b){
    while(a && b){
        int v1=a%10, v2=b%10;
        if(v1*v2) return 0;
        a/=10; b/=10;
    }
    return 1;
}

int main(){
    cin>>n;
    m=0;
    REP(i,n){
        cin>>v;
        if(v==0) list.pb(v);
        else a[++m]=v;
    }
    FOR(i,1,m) FOR(j,i+1,m) FOR(z,j+1,m) if(ok(a[i],a[j]) && ok(a[j],a[z]) && ok(a[i],a[z])){
        list.pb(a[i]);
        list.pb(a[j]);
        list.pb(a[z]);
        goto printout;
    }
    
    FOR(i,1,m) FOR(j,i+1,m) if(ok(a[i],a[j])){
        list.pb(a[i]);
        list.pb(a[j]);
        goto printout;
    }
    
    if(m>=1) list.pb(a[1]);
    
    printout:
        cout<<sz(list)<<endl;
        REP(i,sz(list)) cout<<list[i]<<' ';
        cout<<endl;
        
    //getch();
    return 0;
}  
