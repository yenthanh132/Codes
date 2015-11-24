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
char a[maxn],b[maxn];
int m,n;
ll x,p10,y;

ll mypow(ll v0, int n){
    if(n==0) return 1;
    ll t=mypow(v0,n/2);
    t=(t*t)%oo;
    if(n&1) return (t*v0)%oo; else return t;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%s%s",a+1,b+1);   
        m=strlen(a+1); n=strlen(b+1);
        x=0; p10=1;
        FORD(i,m,1){
            x=(x+p10*(a[i]-'0'))%oo;
            p10=(p10*10)%oo;
        }        
        p10=x;
        y=1;
        FORD(i,n,1){
            y = ( y * mypow(p10, b[i]-'0') ) %oo;
            p10 = mypow(p10, 10); 
        }
        printf("%lld\n",y);
    }
}
