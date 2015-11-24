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

const int maxn=200007;

int n,k,a[maxn],x,y;
ll s[maxn],f[maxn],p[maxn],res;

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&a[i]);
    s[0]=0;
    FOR(i,1,n){
        s[i]=s[i-1]+a[i];
        ll val=0;
        if(i>=k) val=s[i]-s[i-k]; 
        if(val>f[i-1]){
            f[i]=val;
            p[i]=i-k+1;
        }else{
            f[i]=f[i-1];
            p[i]=p[i-1];
        }
    }
    s[n+1]=0;
    res=-1;
    FORD(i,n,1){
        s[i]=s[i+1]+a[i];
        if(n-i+1>=k && i>k){
            ll val=s[i]-s[i+k];
            if(res<val+f[i-1] || (res==val+f[i-1] && i<y)){
                res=val+f[i-1];
                x=p[i-1];
                y=i;
            }
        }
    }
    
    cout<<x<<' '<<y<<endl;
    
    //getch();
    return 0;
}
 
