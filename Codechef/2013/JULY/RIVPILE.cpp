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
typedef pair<int, pii> iii;
const int maxn=257;

struct point{
    ll x,y;   
}p[maxn];

struct disk{
    ll r,c;
}d[maxn]; 

bool cmp(const disk &a, const disk &b){
    return a.r>b.r || (a.r==b.r && a.c<b.c);
}

int n,m,T,w;
int val[maxn][maxn],res,pos[maxn][maxn],nheap,Link[maxn][maxn][maxn];
struct node{
    int i,j;
}heap[maxn*maxn];
bool free1[maxn][maxn];

ll dis(const point &a, const point &b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

void init(){
    sort(d+1,d+m+1,cmp);
    int mm=1; 
    FOR(i,2,m) if(d[mm].c > d[i].c) d[++mm]=d[i];
    m=mm;
    nheap=0;
    FOR(i,1,n) FOR(j,1,m) pos[i][j]=0;
    FOR(u,1,n-1) FOR(v,u+1,n) if(u!=v){
        int q=m;
        ll dist=dis(p[u],p[v]);
        FOR(j,1,m){
            while(q>0 && (d[j].r+d[q].r)*(d[j].r+d[q].r) < dist) q--;
            Link[u][j][v]=q;
            Link[v][j][u]=q;
        }   
    }
}

void update(int i, int j){
    int child=pos[i][j],parent;
    if(child==0) child=++nheap;
    parent=child/2;
    while(parent>0 && val[heap[parent].i][heap[parent].j]>val[i][j]){
        heap[child]=heap[parent];
        pos[heap[child].i][heap[child].j]=child;
        child=parent; parent=child/2;
    }
    heap[child].i=i; heap[child].j=j;
    pos[i][j]=child;
}

void get(int &I, int &J){
    I=heap[1].i; J=heap[1].j;
    int r=1,c,i,j;
    i=heap[nheap].i; j=heap[nheap--].j;
    while(r*2<=nheap){
        c=r*2;
        while(c<nheap && val[heap[c+1].i][heap[c+1].j]<val[heap[c].i][heap[c].j]) c++;
        if(val[i][j]<=val[heap[c].i][heap[c].j]) break;
        heap[r]=heap[c];
        pos[heap[r].i][heap[r].j]=r;
        r=c;
    }
    heap[r].i=i; heap[r].j=j;
    pos[i][j]=r;
}
    

void dijkstra(){
    FOR(i,1,n) FOR(j,1,m){
        free1[i][j]=1;
        if(p[i].y <= d[j].r){
            val[i][j]=d[j].c;
            update(i,j);
        }else val[i][j]=oo;
    }
    res=oo;
    int z,i,j;
    while(nheap>0){
        get(i,j);
        free1[i][j]=0;
        //if(val[i][j]>=res) break;
        if(j>1 && free1[i][j-1] && val[i][j-1]>val[i][j]-d[j].c+d[j-1].c){
            val[i][j-1]=val[i][j]-d[j].c+d[j-1].c;
            update(i,j-1);
        }
        if(w-p[i].y <= d[j].r)
           res=min(res,val[i][j]);    
        
        FOR(v,1,n) if(v!=i){
            z=Link[i][j][v];
            if(z>0 && free1[v][z] && val[v][z]>val[i][j]+d[z].c){
                val[v][z]=val[i][j]+d[z].c;
                update(v,z);
            }
        }
    }
            
}

#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d%d",&n,&m,&w);
        FOR(i,1,n) scanf("%lld%lld",&p[i].x,&p[i].y);
        FOR(i,1,m) scanf("%lld%lld",&d[i].r,&d[i].c);
        init();
        dijkstra();
        if(res==oo) printf("impossible\n");
        else printf("%d\n",res);
    }
    getch();
    return 0;
    
}
    
