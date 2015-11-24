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

const int maxn=500007;

int n,q,first[maxn],last[maxn],cnt,list[maxn];
vector<int> a[maxn];

struct node{
    int t,v1,v2;
}IT[maxn*4];
    

void DFS(int u, int parent=-1){
    list[++cnt]=u;
    first[u]=cnt;
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v!=parent) DFS(v,u);
    }
    last[u]=cnt;
}

void lazyupdate(int i, int l, int r){
    if(IT[i].t==0) return;
    IT[i].v1=max(IT[i].v1,IT[i].t);
    if(l!=r){
        IT[i*2].t=max(IT[i*2].t,IT[i].t);
        IT[i*2+1].t=max(IT[i*2+1].t,IT[i].t);
    }
    IT[i].t=0;   
}

void fill(int i, int l, int r, int s, int f, int time){
    lazyupdate(i,l,r);
    if(f<l || r<s) return;
    if(s<=l && r<=f){
        IT[i].t=time;
        lazyupdate(i,l,r);
        return;
    }
    int mid=(l+r)/2;
    fill(i*2,l,mid,s,f,time); fill(i*2+1,mid+1,r,s,f,time);
    IT[i].v1=max(IT[i*2].v1,IT[i*2+1].v1);
}

void mark(int i, int l, int r, int p, int time){
    if(p<l || r<p) return;
    if(l==r){
        IT[i].v2=max(IT[i].v2,time);
        return;
    }   
    int mid=(l+r)/2;
    mark(i*2,l,mid,p,time); mark(i*2+1,mid+1,r,p,time);
    IT[i].v2=max(IT[i*2].v2,IT[i*2+1].v2);
}

int get1(int i, int l, int r, int p){
    lazyupdate(i,l,r);
    if(p<l || r<p) return 0;
    if(l==r) return IT[i].v1;
    int mid=(l+r)/2;
    int res = max(get1(i*2,l,mid,p), get1(i*2+1,mid+1,r,p));
    IT[i].v1=max(IT[i*2].v1,IT[i*2+1].v1);
    return res;
}

int get2(int i, int l, int r, int s, int f){
    if(f<l || r<s) return 0;
    if(s<=l && r<=f) return IT[i].v2;
    int mid=(l+r)/2;
    int res = max(get2(i*2,l,mid,s,f), get2(i*2+1,mid+1,r,s,f));
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int u,v;
    REP(i,n-1){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
    }
    
    cnt=0;
    DFS(1);
    
    scanf("%d",&q);
    FOR(tt,1,q){
        scanf("%d%d",&u,&v);
        if(u==1)
            fill(1,1,n,first[v],last[v],tt);
        else if(u==2)
            mark(1,1,n,first[v],tt);
        else
            if(get1(1,1,n,first[v])>get2(1,1,n,first[v],last[v])) puts("1");
            else puts("0");
    }
    
    //getch();
    return 0;
}
        
