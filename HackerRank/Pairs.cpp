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

int n,a[maxn],c[maxn],k;

int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int m=1; c[m]=1;
    FOR(i,2,n) if(a[i]!=a[i-1]){
        a[++m]=a[i];
        c[m]=1;
    }else c[m]++;
    ll res=0;
    n=m;
    FOR(i,2,n){
        int v=a[i]-k,l=1,r=i-1,mid;   
        while(l<=r){
            mid=(l+r)/2;
            if(v<a[mid]) r=mid-1;
            else if(v>a[mid]) l=mid+1;
            else if(v==a[mid]){
                res+=1ll*c[i]*c[mid];
                break;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
    
