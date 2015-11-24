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

const int maxn=50;

int p;
ll n,t,sum,a[maxn][maxn],res;

ll getvalue(ll n, ll t, int p){
    int m;
    if(t==0 || n==0) return 0;
    cout<<n<<' '<<t<<endl;
    sum=1;
    FOR(i,1,40){
        if(sum+(1ll<<i)>n){
            m=i-1;
            break;
        }
        sum+=(1ll<<i);
    }
    ll res=0;
    FOR(i,0,m) res+=a[i][p];
    if(t==1) return res + getvalue(n-(1ll<<m),t,p) - (res - a[m][p]);
     else return res+getvalue(n-sum,t/2,p-1);
}
            

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    cin>>n>>t;
    ll t2=t;
    p=0;
    while(t%2==0) t/=2, p++;
    if(t!=1) cout<<0<<endl;
    else{
        reset(a,0);
        a[0][0]=1;
        FOR(i,1,41){
            a[i][0]=1;
            FOR(j,1,41) a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
        t=t2;
        res=0;
        res=getvalue(n,t,p);
        cout<<res<<endl;
    }
    
    getch();
    return 0;
}
