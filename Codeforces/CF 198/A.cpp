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

ll s1[maxn],s2[maxn];
int a[maxn],n;

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    s1[1]=0;
    FOR(i,2,n) s1[i]=s1[i-1]+1ll*(i-1)*(a[i]-a[i-1]);
    s2[n]=0;
    FORD(i,n-1,1) s2[i]=s2[i+1]+1ll*(n-i)*(a[i+1]-a[i]);
    
    ll num=0,den=0;
    FOR(i,1,n) num+=s1[i]+s2[i]+a[i];
    den=n;
    ll d=gcd(num,den);
    cout<<num/d<<' '<<den/d<<endl;
    //getch();
    return 0;
}
    
