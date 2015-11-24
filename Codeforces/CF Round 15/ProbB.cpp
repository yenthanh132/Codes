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
    //freopen("test.txt","r",stdin);
    int t;
    ll m,n,x1,y1,x2,y2,N,M,w,h,a,b,c,d;
    cin>>t;
    REP(index,t){
        cin>>n>>m>>a>>b>>c>>d;
        x1=min(a,c); x2=max(a,c);
        y1=min(b,d); y2=max(b,d);
        N=(x2-x1+1); M=y2-y1+1;
        w=n-N+1; h=m-M+1;
        x1=w; y1=h; x2=n-w+1; y2=m-h+1;
        cout<<m*n-(w*h*2-max(ll(0),x1-x2+1)*max(ll(0),y1-y2+1))<<endl;
    }
    //getch();
    return 0;
}
        
