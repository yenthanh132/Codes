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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

const double PI=3.141592653589793238462;
const double LIM=0.000000001;
#define maxn 10007

struct circle{int x,y,r;} a[maxn];
struct line{double rad; int i; bool open;} arr[maxn*4];
double d[maxn],res;
int n,m,pos[maxn],heap[maxn],nheap;

double myabs(double a){return (a>=0)?a:-a;}

void makeround(double &rad){
    if(rad<0) rad+=2*PI;
    else if(rad>2*PI) rad-=2*PI;
}

void add(double rad1, double rad2, int i){
    arr[++m].rad=rad1; arr[m].i=i; arr[m].open=1;
    arr[++m].rad=rad2; arr[m].i=i; arr[m].open=0;
}

bool equal(double a, double b){
    return(myabs(a-b)<=LIM);
}

bool cmpfunc(const line &a, const line &b){
    if(a.rad<b.rad) return true;
    else if(equal(a.rad,b.rad) && a.open>b.open) return true;
    else return false;
}

//------HEAP--------
void upheap(int v){
    int child=pos[v], parent=child/2;
    while(parent>0 && d[heap[parent]]>d[v]){
        heap[child]=heap[parent];
        pos[heap[child]]=child;
        child=parent;
        parent=child/2;
    }
    heap[child]=v;
    pos[v]=child;
}

void downheap(int v){
    int r=pos[v], c;
    while(r*2<=nheap){
        c=r*2;
        if(c<nheap && d[heap[c+1]]<d[heap[c]]) c++;
        if(d[v]<=d[heap[c]]) break;
        heap[r]=heap[c];
        pos[heap[r]]=r;
        r=c;
    }
    heap[r]=v;
    pos[v]=r;
}

void addheap(int v){
    pos[v]=++nheap;
    heap[nheap]=v;
    upheap(v);
}

void delheap(int v){
    int p=pos[v];
    v=heap[nheap--];
    if(nheap==0) return;
    pos[v]=p;
    heap[p]=v;
    upheap(v); downheap(v);
}

//--------------------

double dis_line_point(double rad, int x, int y){
    double k=tan(rad);
    return (myabs(k*x-y)/sqrt(k*k+1));
}

double cal_part(double rad1, double rad2, int i){
    double t;
    if (equal(dis_line_point(rad2,a[i].x,a[i].y),a[i].r)) t=PI/2; 
        else t=asin(dis_line_point(rad2,a[i].x,a[i].y)/a[i].r);
    if(rad2>rad1) return(t-(rad2-rad1)); else return((rad1-rad2)-t);
}

double cal(double rad1, double rad2, int i){
    double mid=atan2(a[i].y,a[i].x); makeround(mid);
    if (equal(rad2,2*PI) && equal(mid,0)) mid=2*PI;
    return(a[i].r*(cal_part(mid,rad2,i)-cal_part(mid,rad1,i)));
}    

void solve(){
    nheap=0; reset(pos,0);
    res=0; 
    double oldrad=0;
    FOR(i,1,m){
        if(nheap)
            if(!equal(oldrad,arr[i].rad)) res=res+cal(oldrad,arr[i].rad,heap[1]);
        if(arr[i].open) addheap(arr[i].i); else delheap(arr[i].i);
        oldrad=arr[i].rad;
    }
    printf("%0.6f",res);
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&n); m=0;
    double rad1,rad2,t;
    FOR(i,1,n){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
        d[i]=sqrt(a[i].x*a[i].x+a[i].y*a[i].y);
        t=asin(a[i].r/d[i]);
        rad1=atan2(a[i].y,a[i].x)-t; rad2=atan2(a[i].y,a[i].x)+t;
        makeround(rad1); makeround(rad2);
        if(rad1<rad2 || equal(rad1,rad2)) add(rad1,rad2,i);
        else add(0,rad2,i), add(rad1,PI*2,i);
    }
    sort(arr+1,arr+m+1,cmpfunc);
    solve();
    getch();
    return 0;
}
