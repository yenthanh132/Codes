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
const double eps=1e-9;

struct party{double a,b;} a[maxn];
int m,n,s,k,t[maxn];

double getx(party &x, party &y){
    return (y.b-x.b)/(x.a-y.a);
}

bool equal(double a, double b){
    return fabs(a-b)<eps;
}

bool smaller_or_equal(double a, double b){
    return equal(a,b) || a<b;
}
    
void init(){
    k=1;
    a[1].a=-1; a[1].b=t[1];
    party z;
    FOR(i,2,m){
        z.a=-1.0/i; z.b=1.0*t[i]/i;
        while(k>=2 && smaller_or_equal(getx(z,a[k-1]), getx(a[k],a[k-1]))) k--;
        a[++k]=z;
    }
}

double val(int pos, int &x){
    return a[pos].a*x+a[pos].b;
}


double getmin(int &s){
    int l, r, mid;
    double ans;
    l=1; r=k;
    ans=-1e-15;
    while(l<=r){
        mid=(l+r)>>1;
        ans=max(ans,val(mid,s));
        if(mid>l && (val(mid-1,s)>val(mid,s)+eps)) r=mid-1; else l=mid+1;
    }
    return 1/ans;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&m);
    FOR(i,1,m) scanf("%d",&t[i]);
    init();    
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&s);
        printf("%0.6lf\n",getmin(s));
    }
    //getch();
    return 0;
}        
