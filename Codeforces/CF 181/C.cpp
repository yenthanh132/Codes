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

const int maxn=1000007;

ll gt[maxn],ngt[maxn];
int a,b,n;
    
ll mypow(ll v0, ll n){
    if(n==0) return 1;
    ll t=mypow(v0,n/2);
    t=(t*t)%oo;
    if(n&1) return (t*v0)%oo; else return t;
}

ll C(ll k, ll n){
    return gt[n]*ngt[k]%oo*ngt[n-k]%oo;
}

bool check(int v){
    while(v){
        if(v%10!=a && v%10!=b) return 0;
        v/=10;
    }
    return 1;
}

#include <conio.h>
int main(){

    cin>>a>>b>>n;
    gt[0]=1; ngt[0]=1;
    FOR(i,1,n){
        gt[i]=(gt[i-1]*i)%oo;
        ngt[i]=mypow(gt[i],oo-2);
    }
    ll res=0;
    FOR(i,0,n){
        int sum=i*a+(n-i)*b;
        if(check(sum)) res=(res+C(i,n))%oo;
    }
    cout<<res<<endl;
    //getch();
    return 0;
}
           
