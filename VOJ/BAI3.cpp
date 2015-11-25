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

const int maxn=2000007;

int a[maxn],n;
ll res;

ll gcd(ll a, ll b){
    if(a<b) return gcd(b,a);
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    ll r=gcd(a,b);
    return (a/r)*b;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    int j,c,next;
    res=1;
    FOR(i,1,n) if(a[i]){
        c=1;
        j=a[i]; a[i]=0;
        while(a[j]){
            c++;
            next=a[j];
            a[j]=0;
            j=next;
        }
        res=lcm(res,c);
    }
    printf("%d\n",res);
    //getch();
    return 0;
}
