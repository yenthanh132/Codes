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
const double eps=1e-7;

bool equal(double a, double b){
    return fabs(a-b)<eps;
}

bool bigger(double a, double b){
    return !equal(a,b) && a>b;
}

double a,b,Y1[maxn],Y2[maxn],l[maxn];
int m,n;

int find(double v){
    int l,r,mid,res;
    res=0;
    l=1; r=n;
    while(l<=r){
        mid=(l+r)>>1;
        if(bigger(v,Y1[mid])){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return res;
}

double sqr(double r){ return r*r; }

double dis(int i, int j){
    return sqrt(sqr(a-b)+sqr(Y2[j]-Y1[i]));
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%lf%lf",&n,&m,&a,&b);
    FOR(i,1,n) scanf("%lf",&Y1[i]);
    FOR(i,1,m) scanf("%lf",&Y2[i]);
    FOR(i,1,m) scanf("%lf",&l[i]);
    
    double res=1e15,t;
    int u,v;
    FOR(j,1,m){
        int pos=find(Y2[j]*a/b);
        if(pos>0){
            t=sqrt(sqr(a)+sqr(Y1[pos]-0)) + dis(pos,j) + l[j];
            if(bigger(res,t)){
                res=t;
                u=pos; v=j;
            }
        }
        if(pos<n){
            t=sqrt(sqr(a)+sqr(Y1[pos+1]-0)) + dis(pos+1,j) + l[j];
            if(bigger(res,t)){
                res=t;
                u=pos+1; v=j;
            }
        }
    }
    printf("%d %d\n",u,v);
    //getch();
    return 0;
}
        
