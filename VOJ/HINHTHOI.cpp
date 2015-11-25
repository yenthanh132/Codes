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

const ll base=1000;
const int maxn = 1507;
const double PI=atan(1)*4;
const double lim=1e-7;

struct line{int t; ll v;};

pii a[maxn];
line list[maxn*maxn];
int n,m;

inline int gcd(int a, int b){
    int t;
    while(b!=0){
        a=a%b;
        t=a; a=b; b=t;
    }
    return a;
}

ll hash(int x1, int y1, int x, int y){
    if(y<0 || (y==0 && x<0)) y=-y, x=-x;
    ll ans=x1*base+y1;
    int d=gcd(abs(x),abs(y));
    y/=d; x/=d;
    ans=ans*base+x; ans=ans*base+y;
    return ans;
}

void quicksort(int l, int r){
    if(l>=r) return;
    ll k=list[rand()%(r-l+1)+l].v;
    int i=l,j=r;
    do{
        while(list[i].v<k) i++;
        while(list[j].v>k) j--;
        if(i<=j){
            if(i<j) swap(list[i],list[j]);
            i++, j--;
        }
    }while(i<=j);
    quicksort(l,j); quicksort(i,r);
}

void init(){
    line t;
    m=0;
    FOR(i,1,n-1) FOR(j,i+1,n){
        t.v=hash(a[i].fi+a[j].fi, a[i].se+a[j].se, a[j].se-a[i].se, a[j].fi-a[i].fi);
        t.t=1;
        list[++m]=t;
        t.v=hash(a[i].fi+a[j].fi, a[i].se+a[j].se, a[j].fi-a[i].fi, a[i].se-a[j].se);
        t.t=2;
        list[++m]=t;
    }
    quicksort(1,m);
}

void solve(){
    int i=1,j,c;
    ll res=0,t1,t2;
    while(i<=m){
        j=i; 
        t1=t2=0;
        if(list[i].t==1) t1++; else t2++;
        while(j<m && list[i].v==list[j+1].v){
            j++;
            if(list[j].t==1) t1++; else t2++;
        }
        res+=t1*t2;
        i=j+1;
    }
    printf("%I64d\n",res/2);
}
    
//#include <conio.h>
int main(){
    //freopen("HINHTHOI\\HINHTHOI_9.in","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
    init();
    solve();
    //getch();
    return 0;
}
    
