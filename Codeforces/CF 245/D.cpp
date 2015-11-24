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

const int maxn=1000007;

int n;
struct point{
    ll x,y;
    point(){}
    point(ll _x, ll _y){
        x=_x;
        y=_y;   
    }
} a[maxn],b[maxn],list[maxn];
ll res;

bool cmp(const point &a, const point &b){
    return a.x<b.x || (a.x==b.x && a.y<b.y);  
}

void merge(int l, int r){
    int mid=(l+r)/2;
    int x=l, y=mid+1, p=l;
    while(p<=r){
        if(y>r || (x<=mid && a[x].y < a[y].y)) b[p++]=a[x++];
        else b[p++]=a[y++];
    }
    FOR(i,l,r) a[i]=b[i];
}

ll myabs(ll v){ return (v<0?-v:v); }

ll dis2(const point &a, const point &b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);  
}

void solve(int l, int r){
    if(l==r) return;
    int mid=(l+r)/2;
    ll x_mid = a[mid].x;
    solve(l,mid); solve(mid+1,r);
    merge(l,r);
    int cnt=0;
    FOR(i,l,r) if(myabs(a[i].x-x_mid) < res) list[++cnt]=a[i];
    FOR(len,1,5) FOR(i,1,cnt-len) res=min(res,dis2(list[i],list[i+len]));
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&n);
    ll s=0;
    int v;
    FOR(i,1,n){
        scanf("%d",&v);
        s+=v;
        a[i]=point(i,s);
    }
        
    sort(a+1,a+n+1,cmp);
    res=oo;
    solve(1,n);
    
    printf("%d\n",res);
    
}
