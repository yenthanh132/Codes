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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=10007;
int t,n,a[maxn];
ll smin[maxn];

ll count(){
    ll res=0, s=0, maxs=0, mins, sleft;
    FOR(i,1,n){
        s+=a[i];
        smin[i]=s-maxs;
        maxs=max(maxs,s);
    }
    s=0; mins=oo; sleft=oo;
    FOR(i,1,n){
        s+=a[i];
        if(i>1) res=max(res,s-mins);
        sleft=min(sleft,smin[i]);
        mins=min(mins,s+sleft);
    }
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&t);
    REP(tt,t){
        scanf("%d",&n);
        ll res=-oo;
        FOR(i,1,n) scanf("%d",&a[i]);
        res=max(res,count());
        reverse(a+1,a+n+1);
        res=max(res,count());
        printf("%lld\n",res);
    }
    //getch();
    return 0;
}
    
        
            
            
