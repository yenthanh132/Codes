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

const int maxn=1007;

ll mypow(int v0, int n){
    if(n==0) return 1;
    ll t=mypow(v0,n/2);
    t=(t*t)%oo;
    if(n&1) return (t*v0)%oo; else return t;
}

int n,m,a[maxn];
ll gt[maxn];
vector<int> list;

#include <conio.h>
int main(){
    //freopen("Test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    ll res=1;
    if(a[1]>1) list.pb(a[1]-1);
    if(a[m]<n) list.pb(n-a[m]);
    FOR(i,2,m) if(a[i]>a[i-1]+1){
        res=(res*mypow(2,a[i]-a[i-1]-2))%oo;
        list.pb(a[i]-a[i-1]-1);
    }
    gt[0]=1;
    FOR(i,1,n) gt[i]=(gt[i-1]*i)%oo;
    int sum=0;
    REP(i,sz(list)){
        sum+=list[i];
        res=(res*mypow(gt[list[i]],oo-2))%oo;
    }
    res=(res*gt[sum])%oo;
    
    cout<<res<<endl;
    
    //getch();
    return 0;
}
       
    
    
