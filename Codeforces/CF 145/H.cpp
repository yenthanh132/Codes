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

int a[maxn],b[maxn],m,n,arr[maxn],mark[maxn];
vector<int> res;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&m);
    FOR(i,1,m) scanf("%d",&a[i]);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&b[i]);
    int p=m+n;
    int M=m, N=n;
    reset(mark,0);
    if(a[m]!=b[n]){
        while(m>0 && a[m]==0){
            arr[p--] = m--;
        }   
        while(n>0 && b[n]==0){
            arr[p--] = m + n--;   
        }
    }
    while(m>0 || n>0){
        int x, y;        
        if(n>0){
            y=n;
            while(y>0 && b[y]==b[n]) mark[p]=b[y], arr[p--]=M+y--;
            n=y;
        }
        if(m>0){
            x=m;
            while(x>0 && a[x]==a[m]) mark[p]=a[x], arr[p--]=x--;   
            m=x;
        }
    }
    FOR(i,1,M+N-1) printf("%d ",arr[i]); printf("%d\n",arr[M+N]);
    p=M+N;
    while(p>0 && mark[p]==0) --p;
    while(p>0){
        res.pb(p);
        int x=p;
        while(x>0 && mark[x]==mark[p]) --x;
        p=x;   
    }
    printf("%d\n",sz(res));
    sort(res.begin(),res.end());
    REP(i,sz(res)-1) printf("%d ",res[i]);
    printf("%d\n",res[sz(res)-1]);
    
    return 0;
}



