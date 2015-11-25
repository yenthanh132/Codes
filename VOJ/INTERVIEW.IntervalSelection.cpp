#include <iostream>
#include <algorithm>
#include <cstdio>
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

#define maxn 1007

int n,m,resIT;
struct ITnode{int v,t;} IT[maxn*8];
struct edge{int x,y;} a[maxn];
vector<pii> ds;

void compress(){
    sort(ds.begin(),ds.end());
    m=0;
    for(int i=0;i<sz(ds);i++){
        if (i==0 || ds[i].fi!=ds[i-1].fi) m++;
        if (ds[i].se<n) a[ds[i].se+1].x=m; else a[ds[i].se-n+1].y=m;
    }
}

void lazyupdate(int i, int l, int r){
    if (IT[i].t==0) return;
    IT[i].v+=IT[i].t;
    if(l<r) IT[i*2].t+=IT[i].t, IT[i*2+1].t+=IT[i].t;
    IT[i].t=0;
}

void updateIT(int i, int l, int r, int& s, int& f){
    lazyupdate(i,l,r);
    if(r<s || l>f) return;
    if(s<=l && r<=f){
        IT[i].t=1;
        lazyupdate(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    updateIT(i*2,l,mid,s,f); updateIT(i*2+1,mid+1,r,s,f);
    IT[i].v=max(IT[i*2].v,IT[i*2+1].v);
}

void getIT(int i, int l, int r, int& s, int& f){
    lazyupdate(i,l,r);
    if(r<s || l>f) return;
    if(s<=l && r<=f){
        resIT=max(resIT,IT[i].v);
        return;
    }
    int mid=(l+r)/2;
    getIT(i*2,l,mid,s,f); getIT(i*2+1,mid+1,r,s,f);
    IT[i].v=max(IT[i*2].v,IT[i*2+1].v);
}
       
bool mycmp(edge a,edge b){return(a.y<b.y || (a.y==b.y && a.x>b.x));}
       
void solve(){
    int i,res=0;
    reset(IT,0);
    sort(a+1,a+n+1,mycmp);
    for(i=1;i<=n;i++){
        resIT=0;
        getIT(1,1,m,a[i].x,a[i].y);
        if (resIT<=1){
            res++;
            updateIT(1,1,m,a[i].x,a[i].y);
        }
    }
    printf("%d\n",res);
}
       
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int test,i;
    scanf("%d",&test);
    for(int index=0;index<test;index++){
        scanf("%d",&n);
        ds.clear();
        for(i=0;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);        
            ds.pb(mp(u,i)); ds.pb(mp(v,i+n));
        }
        compress();
        solve();
    }
    //getch();
    return 0;
}
    
