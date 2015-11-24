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

int m,n,k;
vector<int> res;
deque<int> d1,d2;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    REP(i,k) res.pb(1), d1.pb(n);
    
    FOR(i,n,n+m){
        while(d1.front()<i){
            d2.pb(d1.front()+m+1);
            d1.pop_front();
        }
        while(d2.front()<=i){
            d1.pb(d2.front()+n-1);
            d2.pop_front();
        }
        if(d1.back()==i){
            res.pb(i);
            d1.pb(i+n-1);
        }
        while(sz(d1)<k){
            res.pb(i);
            d1.pb(i+n-1);
        }
    }
    
    printf("%d\n",sz(res));
    REP(i,sz(res)) printf("%d ",res[i]);    
    
    //getch();
    return 0;
}
    
