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

ll mypow(int v0, int n){
    if(n==0) return 1;
    ll t=mypow(v0,n/2);
    t=t*t%oo;
    if(n&1) return (t*v0)%oo; else return t;
}

const int maxn=100007;
int n,k;
ll x,mul,res;
char a[maxn];

#include <conio.h>
int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    cin>>k;
    res=0;
    x=mypow(2,n);
    mul=(mypow(x,k)-1)*mypow(x-1,oo-2) % oo;
    ll mul2=1;
    FOR(i,1,n){
        if(a[i]=='0' || a[i]=='5')
            res = (res + (mul2 * mul))%oo;
        mul2=mul2*2 %oo;
    }
    cout<<res<<endl;
    //getch();
}
