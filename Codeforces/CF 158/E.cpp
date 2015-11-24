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
const int maxm=400000;
const double eps=1e-9;

int n,a[11],per[11],arr[4][4],m;
struct point{double x,y;} p[maxn]; 
double x[maxn],y[maxn];
struct line{double x, y1, y2; int cbot,ctop,id;} lstleft[maxm+maxn],lstright[maxn+maxm];
struct answer{double x1,y1,x2,y2;} list[maxm];
bool ok[maxm];

bool equal(double a, double b){
    return fabs(a-b)<eps;
}

bool mycmp(const line&a, const line &b){
    return a.x+eps<b.x;
}

int find(double v){
    int l, r, mid;
    l=1; r=n;
    while(l<=r){
        mid=(l+r)>>1;
        if(equal(y[mid],v)) return mid;
        else if(y[mid]>v) r=mid-1;
        else l=mid+1;
    }
    return 0;
}

//IT
int IT[maxn*4];

void update(int i, int l, int r, int &p){
    if(p<l || p>r) return;
    if(l==r){
        IT[i]++;
        return;
    }
    int mid=(l+r)>>1;
    update(i*2,l,mid,p); update(i*2+1,mid+1,r,p);
    IT[i]=IT[i*2]+IT[i*2+1];
}

int get(int i, int l, int r, double lbound, double ubound){
    if(ubound<y[l] || y[r]<lbound) return 0;
    if(lbound<y[l] && y[r]<ubound) return IT[i];
    int mid=(l+r)>>1;
    return get(i*2,l,mid,lbound,ubound)+get(i*2+1,mid+1,r,lbound,ubound);
}

//-------------------------------------------

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%lf%lf",&x[i],&y[i]);
        p[i].x=x[i];
        p[i].y=y[i];
    }
    sort(x+1,x+n+1); sort(y+1,y+n+1);
    x[0]=x[n+1]=y[0]=y[n+1]=1e9+1;
    FOR(i,1,9) scanf("%d",&a[i]);
    FOR(i,1,9) per[i]=i;
    int i,sleft,sright,stop,sbottom;
    line l;
    m=0;
    do{
        i=1;
        FOR(xx,1,3) FOR(yy,1,3) arr[xx][yy]=a[per[i++]];
        sleft=arr[1][1]+arr[2][1]+arr[3][1];
        sright=arr[1][3]+arr[2][3]+arr[3][3];
        stop=arr[1][1]+arr[1][2]+arr[1][3];
        sbottom=arr[3][1]+arr[3][2]+arr[3][3];
        
        if( equal(x[sleft],x[sleft+1]) || equal(x[n-sright+1],x[n-sright]) 
         || equal(y[sbottom],y[sbottom+1]) || equal(y[n-stop+1],y[n-stop])) continue;
        
        l.x=x[sleft]+0.1;
        l.y1=y[sbottom]+0.1;
        l.y2=y[n-stop+1]-0.1;
        l.cbot=arr[3][1]; l.ctop=arr[1][1];
        l.id=++m;
        lstleft[m]=l;
        list[m].x1=l.x;
        
        l.x=x[n-sright+1]-0.1;
        l.y1=y[sbottom]+0.1;
        l.y2=y[n-stop+1]-0.1;
        l.cbot=arr[3][3]; l.ctop=arr[1][3];
        l.id=m;
        lstright[m]=l;
        list[m].x2=l.x;
        
        list[m].y1=l.y1; list[m].y2=l.y2;
    }while(next_permutation(per+1,per+10));
    
    FOR(i,1,n){
        l.x=p[i].x;
        l.y1=p[i].y;
        l.id=-1;
        lstleft[++m]=l;
        lstright[m]=l;
    }
    
    sort(lstleft+1,lstleft+m+1,mycmp);
    sort(lstright+1,lstright+m+1,mycmp);
    
    sort(y+1,y+n+1);
    int tc=1;
    FOR(i,2,n) if(!equal(y[tc],y[i])) y[++tc]=y[i];
    n=tc;
    reset(IT,0); reset(ok,0);
    int pos;
    FOR(i,1,m)
        if(lstleft[i].id==-1){
            pos=find(lstleft[i].y1);
            update(1,1,n,pos);
        }else
            if(lstleft[i].cbot == get(1,1,n,-oo,lstleft[i].y1) 
            && lstleft[i].ctop == get(1,1,n,lstleft[i].y2,oo))
                ok[lstleft[i].id]=1;
            
    
    reset(IT,0);
    FORD(i,m,1)
        if(lstright[i].id==-1){
            pos=find(lstright[i].y1);
            update(1,1,n,pos);
        }else
            if(ok[lstright[i].id]
            && lstright[i].cbot == get(1,1,n,-oo,lstright[i].y1)
            && lstright[i].ctop == get(1,1,n,lstright[i].y2,oo)){
                l=lstright[i];
                printf("%0.6lf %0.6lf\n",list[l.id].x1,list[l.id].x2);
                printf("%0.6lf %0.6lf\n",list[l.id].y1,list[l.id].y2);
                return 0;
            }
    
    puts("-1");
    return 0;
}
    
        
        
