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

const int maxn=1007;

struct node{
    ll t,v,t2;
} IT[maxn*4][maxn*4];

struct node2{
    int y1, y2;
} pos[maxn*4];

int n,m;

void lazyupdate1D(int i, int j, int l, int r,int height){
    node &p=IT[i][j];
    if(p.t==0) return;
    int width=r-l+1;
    if((height*width)&1) p.v^=p.t;
    if(l<r){
        IT[i][j*2].t^=p.t;
        IT[i][j*2+1].t^=p.t;
    }
    p.t=0;
}    

void update1D(int i, int j, int l, int r, int y1, int y2, ll v, int height){
    lazyupdate1D(i,j,l,r,height);
    if(y1>r || y2<l) return;   
    if(y1<=l && r<=y2){
        IT[i][j].t=v;
        lazyupdate1D(i,j,l,r,height);
        return;
    }
    int mid=(l+r)/2;
    update1D(i,j*2,l,mid,y1,y2,v,height);
    update1D(i,j*2+1,mid+1,r,y1,y2,v,height);
    IT[i][j].v = IT[i][j*2].v ^ IT[i][j*2+1].v;
}

void lazyupdate2D(int i, int l, int r){
    node &p=IT[i][1];
    if(p.t2==0) return;
    update1D(i,1,1,n,pos[i].y1,pos[i].y2,p.t2,r-l+1);
    if(l<r){
        int mid=(l+r)/2;
        lazyupdate2D(i*2,l,mid);
        lazyupdate2D(i*2+1,mid+1,r);
        IT[i*2][1].t2=IT[i*2+1][1].t2=p.t2;
        pos[i*2].y1=pos[i*2+1].y1=pos[i].y1;
        pos[i*2].y2=pos[i*2+1].y2=pos[i].y2;
    }
    p.t2=0;
}

void update2D(int i, int l, int r, int x1, int x2, int y1, int y2, ll v){
    lazyupdate2D(i,l,r);
    if(x1>r || x2<l) return;
    if(x1<=l && r<=x2){
        IT[i][1].t2=v; pos[i].y1=y1; pos[i].y2=y2;
        lazyupdate2D(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    update2D(i*2,l,mid,x1,x2,y1,y2,v);
    update2D(i*2+1,mid+1,r,x1,x2,y1,y2,v);   
    IT[i][1].v = IT[i*2][1].v ^ IT[i*2+1][1].v; 
}   

ll ans;

void get1D(int i, int j, int l, int r, int y1, int y2, int height){
    lazyupdate1D(i,j,l,r,height);
    if(y1>r || y2<l) return;
    if(y1<=l && r<=y2){
        ans^=IT[i][j].v;
        return;
    }
    int mid=(l+r)/2;
    get1D(i,j*2,l,mid,y1,y2,height);
    get1D(i,j*2+1,mid+1,r,y1,y2,height);
    IT[i][j].v = IT[i][j*2].v ^ IT[i][j*2+1].v;
}

void get2D(int i, int l, int r, int x1, int x2, int y1, int y2){
    lazyupdate2D(i,l,r);
    if(x1>r || x2<l) return;
    if(x1<=l && r<=x2){
        get1D(i,1,1,n,y1,y2,r-l+1);
        return;
    }
    int mid=(l+r)/2;
    get2D(i*2,l,mid,x1,x2,y1,y2);
    get2D(i*2+1,mid+1,r,x1,x2,y1,y2);
    IT[i][1].v = IT[i*2][1].v ^ IT[i*2+1][1].v;
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    reset(IT,0);
    int k,x1,y1,x2,y2;
    ll v;
    REP(tt,m){
        scanf("%d%d%d%d%d",&k,&x1,&y1,&x2,&y2);
        if(k==1){
            ans=0;
            get2D(1,1,n,x1,x2,y1,y2);
            printf("%I64d\n",ans);
        }else{
            scanf("%I64d",&v);
            if(v) update2D(1,1,n,x1,x2,y1,y2,v);   
        }
    }
    //getch();
    return 0;
}
