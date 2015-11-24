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

const int maxn=300007;
const int maxm=1507;
const double PI = acos(-1);
const double eps=1e-9;

struct circle{
    int x,y,r;
} b[maxm];

struct edge{
    int a,b,c,x1,y1,x2,y2;
    double r;
    void build(){
        int vx=x2-x1;
        int vy=y2-y1;
        r=atan2(vy,vx);
        if(r<0) r+=PI;
        a=vy; b=-vx;
        c=-a*x1 - b*y1;
    }
} a[maxn];

bool equal(double a, double b){
    return fabs(a-b)<eps;
}

bool least(double a, double b){
    return a<b && !equal(a,b);
}

bool cmp(const edge &a, const edge &b){
    return least(a.r,b.r) || (equal(a.r,b.r) && (     
}

int n,m;

int main(){
    freopen("Test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        a[i].x1*=2;
        a[i].y1*=2;
        a[i].x2*=2;
        a[i].y2*=2;
        a[i].build();
    }
    FOR(i,1,m){
        scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].r);
        b[i].x*=2;
        b[i].y*=2;
        b[i].r*=2;
    }
    
