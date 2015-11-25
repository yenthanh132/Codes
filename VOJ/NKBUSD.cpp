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

const int maxn=10007;

const double eps=1e-9;

double s,vmin,vmax,v0,s2,len[maxn],dis1,dis2,res,ans[maxn],arr[maxn];
int n,k,m,pos[maxn];
bool mark[maxn];

bool check(double time){
    if(time<0){
        FOR(i,1,m) if(fabs(len[i]-dis2)>eps) return 0;
        FOR(i,1,m) ans[i]=v0;
        res=0;
        return 1;
    }
    double umin,umax,t;
    arr[0]=0;
    umin=oo; umax=-oo ;
    FOR(i,1,m){
        arr[i]=arr[i-1]+(dis2-len[i])/time;
        umin=min(umin,arr[i]);
        umax=max(umax,arr[i]);
    }
    if(umax-umin>vmax-vmin+eps) return 0;
    return 1;
}
        
void build_arr(double time){
    FOR(i,1,m) arr[i]=(dis2-len[i])/time;
    double minval=vmin;
    ans[1]=vmin;
    FOR(i,2,m){
        ans[i]=arr[i-1]+ans[i-1];
        minval=min(minval,ans[i]);
    }
    FOR(i,1,m) ans[i]=ans[i]-minval+vmin;
}
        
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%lf%lf%lf%lf",&n,&k,&s,&vmin,&vmax,&v0);

    dis1=s/n;
    int v;
    REP(i,k){
        scanf("%d",&v);
        mark[v]=1;
    }
    m=0;
    FOR(i,1,n) if(!mark[i]) pos[++m]=i;
    pos[m+1]=pos[1]+n;
    dis2=s/m;
    FOR(i,1,m) len[i]=(pos[i+1]-pos[i])*dis1;
    double l=eps,r=oo,mid;
    if(check(-1)) goto printout;
    while(r-l>eps){
        mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            r=mid;
        }else l=mid;
    }
    build_arr(res);
printout:
    printf("%0.6lf\n",res);
    FOR(i,1,m) printf("%d %0.6lf\n",pos[i],ans[i]);
    //getch();
    return 0;
}
