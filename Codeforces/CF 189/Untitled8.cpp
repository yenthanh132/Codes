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

#include <conio.h>
int main(){
    int n,a[100];
    freopen("test.txt","r",stdin);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    
    stack<pii> mys;
    int res=0;
    FORD(i,n,1){
        int step=0;
        while(!mys.empty() && a[i]>mys.top().fi){
            step=max(step+1,mys.top().se);
            mys.pop();
        }
        res=max(res,step);
        mys.push(pii(a[i],step));
    }
          
    cout<<res<<endl;
    getch();
}
