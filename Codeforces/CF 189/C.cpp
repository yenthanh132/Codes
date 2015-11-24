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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=100007;
const double eps=1e-9;

struct edge{
    ll a,b;
    edge(){}
    edge(ll _b, ll _f){
        a=_b; b=_f;
    }
} mys[maxn];
int last;

double giaodiem(const edge &x, const edge &y){
    return 1.0*(y.b-x.b)/(x.a-y.a);
}

bool equal(double a, double b){
    return fabs(a-b)<eps;
}

void push(ll B, ll F){
    edge e = edge(B,F);
    while(last>1){
        double x1=giaodiem(mys[last-1],e);
        double x2=giaodiem(mys[last-1],mys[last]);
        if(equal(x1,x2) || x1<x2) last--;
        else break;
    }
    mys[++last]=e;
}

ll find(ll x){
    int left=1, right=last, mid;
    ll res=oo;
    while(left<=right){
        mid=(left+right)/2;
        res=min(res, mys[mid].a * x + mys[mid].b);
        if(mid>left && mys[mid-1].a * x + mys[mid-1].b < mys[mid].a * x + mys[mid].b) right=mid-1; else left=mid+1;
    }
    return res;
}

int a[maxn],b[maxn],n;
ll f[maxn];

#include <conio.h>
int main(){
    
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);   
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) scanf("%d",&b[i]);
    
    f[1]=0;
    mys[last=1]=edge(b[1],f[1]);
    FOR(i,2,n){
        f[i]=find(a[i]);
        push(b[i],f[i]);
    }
    
    cout<<f[n]<<endl;
    //getch();
    return 0;
}

