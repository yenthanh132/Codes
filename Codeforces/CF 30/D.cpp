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

int n,k,x;
struct point{int x,y,id;} a[maxn];
double res;

bool cmp(const point &a, const point &b){
    return a.x<b.x;
}

double sqr(double r){return r*r;}

double dis(const point &a, const point &b){
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",&a[i].x), a[i].y=0, a[i].id=i;
    scanf("%d%d",&a[n+1].x,&a[n+1].y);
    sort(a+1,a+n+1,cmp);
    FOR(i,1,n) if(a[i].id==k){
        x=i;
        break;
    }
    double t;
    if(x==n){
        FOR(i,1,n+1) a[i].x=-a[i].x;
        sort(a+1,a+n+1,cmp);
        x=1;
    }
    if(k==n+1) x=n+1;
    if(x==n+1){
        res=min(dis(a[n+1],a[1])+dis(a[1],a[n]), dis(a[n+1],a[n])+dis(a[1],a[n]));
    }
    else if(x==1){
        if(a[n+1].x<a[1].x){
            res=min( dis(a[n+1],a[1])*2+dis(a[1],a[n]), dis(a[1],a[n])*2 + dis(a[1],a[n+1]));
        }else{
            int i;
            res=0;
            for(i=2; i<=n && a[i].x<=a[n+1].x; i++) res+=dis(a[i],a[i-1]);
            res+=dis(a[i-1],a[n+1]);
            if(i<=n){
                res+=dis(a[n+1],a[i]);
                for(++i; i<=n; i++) res+=dis(a[i-1],a[i]);
            }
        }
    }else{
        if(a[n+1].x<=a[x].x){
            res=dis(a[1],a[x])+dis(a[1],a[n+1])+dis(a[n+1],a[x+1])+dis(a[x+1],a[n]);
            t=dis(a[x],a[n])*2;
            int i;
            for(i=x-1; i>=1 && a[i].x>=a[n+1].x; i--) t+=dis(a[i],a[i+1]);
            t+=dis(a[i+1],a[n+1]);
            if(i>=1){
                t+=dis(a[n+1],a[i]);
                for(--i; i>=1; i--) t+=dis(a[i+1],a[i]);
            }
            res=min(res,t);
        }else{
            res=dis(a[x],a[n])+dis(a[n],a[n+1])+dis(a[n+1],a[x-1])+dis(a[x-1],a[1]);
            t=dis(a[x],a[1])*2;
            int i;
            for(i=x+1; i<=n && a[i].x<=a[n+1].x; i++) t+=dis(a[i-1],a[i]);
            t+=dis(a[i-1],a[n+1]);
            if(i<=n){
                t+=dis(a[n+1],a[i]);
                for(++i; i<=n; i++) t+=dis(a[i-1],a[i]);
            }
            res=min(res,t);
        }
    }
    printf("%.12lf\n",res);
    getch();
    return 0;
}               
        
            
            
