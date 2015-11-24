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

const int maxn=5007;
int a[maxn],b[maxn],n,m,g[maxn];

int gcd(int a, int b){
    if(a<b) return gcd(b,a);   
    if(b==0) return a;
    return gcd(b,a%b);
}

bool found(int v){
    int l=1, r=m, mid;
    while(l<=r){
        mid=(l+r)/2;
        if(b[mid]==v) return 1;
        else if(v<b[mid]) r=mid-1;
        else l=mid+1;
    }   
    return 0;
}

int cal(int v){
    int res=0,s;
    for(int i=2; i*i<=v; ++i) if(v%i==0){
        s=0;
        while(v%i==0){
            v/=i;
            ++s;   
        }
        if(found(i)) s=-s;
        res+=s;
    }   
    if(v>1){
        s=1;
        if(found(v)) s=-s;
        res+=s;   
    }
    return res;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,m) scanf("%d",&b[i]);
    
    g[0]=0;
    int mul=1;
    int res=0;
    FOR(i,1,n) g[i]=gcd(g[i-1],a[i]), res+=cal(a[i]);    
       
    FORD(i,n,1){
        int gx = g[i]/mul;
        int vx=cal(gx);
        if(vx<0){
            res-=vx*i;
            mul*=gx;
        }
    }
    
    printf("%d\n",res);
}
