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

const int maxn=200007;
const double eps=1e-9;

struct point{
    int x,y,id;
    
} a[maxn*2],p[maxn*4];

ll sqr(ll x){
    return x*x;
}

double dsqr(double x){
    return x*x;
}

int n,q,m,ans1[maxn],ans2[maxn],BIT[maxn*2];
ll d1[maxn],d2[maxn];
vector<int>listy;

void update(int pos){
    for(int i=pos; i<=sz(listy); i+=i&(-i)) BIT[i]++;
}

int get(int pos){
    int res=0;
    for(int i=pos; i; i-=i&(-i)) res+=BIT[i];
    return res;
}

int find(int v){
    return lower_bound(listy.begin(),listy.end(),v)-listy.begin()+1;
}

bool mycmp(const point &a, const point &b){
    if(a.x<b.x || (a.x==b.x && (a.y<b.y || (a.y==b.y  && a.id<b.id)))) return 1; else return 0;
}

void cal_ans2(){
    sort(listy.begin(),listy.end());
    listy.resize(unique(listy.begin(),listy.end())-listy.begin());
    FOR(i,1,m) p[i].y=find(p[i].y);
    sort(p+1,p+m+1,mycmp);
    FOR(i,1,m) if(p[i].id) ans2[p[i].id]=get(p[i].y);
    else update(p[i].y);
}

//#include <conio.h>
int main(){
    int x1,y1,x2,y2,left,right,mid,res;
    ll r1,r2;
    
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
    scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&q);
    FOR(i,1,n){
        d1[i]=sqr(a[i].x-x1)+sqr(a[i].y-y1);
        d2[i]=sqr(a[i].x-x2)+sqr(a[i].y-y2);
    }
    sort(d1+1,d1+n+1); sort(d2+1,d2+n+1);
    
    m=0;
    double x,y;
    FOR(i,1,n){
        x=sqrt(dsqr(a[i].x-x1)+dsqr(a[i].y-y1));
        y=sqrt(dsqr(a[i].x-x2)+dsqr(a[i].y-y2));
        p[++m].id=0;
        p[m].x=int(ceil(x)+eps); p[m].y=int(ceil(y)+eps);
        listy.pb(a[m].y);
    }
    
    FOR(i,1,q){
        scanf("%lld%lld",&r1,&r2);
        p[++m].id=i; p[m].x=r1; p[m].y=r2;
        listy.pb(r2);
        r1=sqr(r1); r2=sqr(r2);
        left=1; right=n; res=0;
        while(left<=right){
            mid=(left+right)>>1;
            if(d1[mid]<=r1){
                res=mid;
                left=mid+1;
            }else right=mid-1;
        }
        ans1[i]=res;
        left=1; right=n; res=0;
        while(left<=right){
            mid=(left+right)>>1;
            if(d2[mid]<=r2){
                res=mid;
                left=mid+1;
            }else right=mid-1;
        }
        ans1[i]+=res;
    }
    
    cal_ans2();

    FOR(i,1,q) printf("%d\n",ans1[i]-ans2[i]);
    
    //getch();
    return 0;
}
