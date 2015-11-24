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

const int maxn=100007;

int n,a[maxn],uoc[maxn],c;
ll res,ans;

ll mypow(int v0, int n){
    if(n==0) return 1;
    ll t=mypow(v0,n/2);
    t=(t*t)%oo;
    if(n&1) return (t*v0)%oo; else return t;
}

//#include <conio.h>
int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    res=0;
    FORD(v,a[n],1){
        int l,r; c=0;
        for(int i=1; i*i<=v; i++) if(v%i==0){
            uoc[++c]=i;
            if(i*i!=v) uoc[++c]=v/i;
        }
        sort(uoc+1,uoc+c+1);
        r=0;
        FORD(i,c,1){
            l=lower_bound(a+1,a+n+1,uoc[i])-a;
            if(r==0) ans=(mypow(i,n-l+1)-mypow(i-1,n-l+1)+oo)%oo;
            else ans=(ans*mypow(i,r-l))%oo;
            r=l;
        }
        res=(res+ans)%oo;
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
                
