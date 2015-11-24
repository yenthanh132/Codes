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

double eps=1e-9;

int n;
double t,v[11],m[11],x[11];

bool equal(double a, double b){
    return fabs(a-b)<eps;
}

bool smaller(double a, double b){
    return !equal(a,b) && a<b;
}

double collide(int i, int j){
    if(equal(x[i],x[j])) return 0;
    if(smaller(x[i],x[j]) && v[i]>eps && v[j]<-eps)
        return (x[j]-x[i])/(v[i]-v[j]);
            
    if(smaller(x[i],x[j])){
        if(v[i]>eps && v[j]>eps && smaller(v[j],v[i])) return (x[j]-x[i])/(v[i]-v[j]);
        if(v[i]<-eps && v[j]<-eps && smaller(v[j],v[i])) return (x[j]-x[i])/(v[i]-v[j]);
    }
    return -1;
}

bool pal[11][11];
bool col[11];
#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    cin>>n>>t;
    FOR(i,1,n) cin>>x[i]>>v[i]>>m[i];
    reset(pal,0);
    while(1){
        double mint=oo;
        FOR(i,1,n) FOR(j,1,n) if(i!=j && !pal[i][j] && collide(i,j)>=0){
            mint=min(mint,collide(i,j));
        }
        if(t-mint<-eps) break;
        t-=mint;
        reset(pal,0);
        reset(col,0);
        FOR(i,1,n) FOR(j,1,n) if(i!=j && equal(collide(i,j),mint)){
            pal[i][j]=pal[j][i]=1;
            double v1,v2;
            x[i]+=v[i]*mint;
            x[j]+=v[j]*mint;
            v1=((m[i]-m[j])*v[i]+2*m[j]*v[j])/(m[i]+m[j]);
            v2=((m[j]-m[i])*v[j]+2*m[i]*v[i])/(m[i]+m[j]);
            v[i]=v1; v[j]=v2;
            
            col[i]=1; col[j]=1;
        }
        FOR(i,1,n) if(!col[i]) x[i]+=v[i]*mint;
    }
    if(t>eps) FOR(i,1,n) x[i]+=v[i]*t;
    FOR(i,1,n) printf("%0.12lf\n",x[i]);
    //getch();
    return 0;
}
