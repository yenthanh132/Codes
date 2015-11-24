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

vector<int> list;

bool check(int v, int n){
    
    bool d[20];
    int c=0;
    REP(i,n){
        d[i]=((v>>i)&1);
        if(d[i]==1) c++;
    }
    if(c<n*2/3) return 0;
    REP(a,n-1) if(d[a]) FOR(b,a+1,n) if(d[b] && 3*b-2*a>=0 && 3*b-2*a<10 && d[3*b-2*a]) return 0;
    if(c==7) cout<<v<<endl;
    return 1;
}

bool check(int v1,int v2,int n){
    bool d[20];
    REP(i,10) d[i]=((v1>>i)&1); 
    REP(j,10) d[j+10]=((v2>>j)&1);
    REP(a,19) if(d[a]) FOR(b,a+1,20) if(d[b] && 3*a-2*b>=0 && 3*a-2*b<20 && d[3*a-2*b]) return 0;
    return 1;
}

void init(){
    REPD(i,1<<20)
        if(check(i,20)) list.pb(i);
    cout<<sz(list)<<endl;
    
    
}

#include <conio.h>
int main(){
    init();
    getch();
    return 0;
}
