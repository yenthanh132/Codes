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

int n,q,a[maxn],h[maxn],cnt,first[maxn],last[maxn];
vector<int> edge[maxn];

void DFS(int u){
    a[++cnt]=h[u];
    first[u]=cnt+1;
    int v;
    REP(i,sz(edge[u])){   
        v=edge[u][i];
        DFS(v);
    }
    last[u]=cnt;
}


//For IT

struct ITnode{
    int t,minv,cnt;
}IT[maxn*4];
    
void init(int i, int l, int r){
    if(l==r){
        IT[i].t=0;
        IT[i].minv=a[l];
        IT[i].cnt=0;
        return;
    }
    int mid=(l+r)>>1;
    init(i*2,l,mid); init(i*2+1,mid+1,r);
    IT[i].minv=min(IT[i*2].minv,IT[i*2+1].minv);
}

void lazyupdate(int i, bool leaf){
    if(!IT[i].t) return;
    if(IT[i].minv!=oo) IT[i].minv -= IT[i].t;
    if(!leaf){
        IT[i*2].t+=IT[i].t;
        IT[i*2+1].t+=IT[i].t;
    }
    IT[i].t=0;
}

int getmin(int i, int l, int r, int s, int f){
    lazyupdate(i,l==r);
    if(f<l || s>r) return oo;
    if(s<=l && r<=f) return IT[i].minv;
    int mid=(l+r)>>1;
    int res = min(getmin(i*2,l,mid,s,f), getmin(i*2+1,mid+1,r,s,f));
    IT[i].minv=min(IT[i*2].minv, IT[i*2+1].minv);
    return res;
}   

void delval(int i, int l, int r, int s, int f, int v){
    lazyupdate(i,l==r);
    if(f<l || s>r) return;
    if(IT[i].minv>v) return;
    if(s<=l && r<=f && IT[i].minv!=v) return;
    if(l==r){
        IT[i].minv=oo;
        IT[i].cnt=1;
        return;
    }
    int mid=(l+r)>>1;
    delval(i*2,l,mid,s,f,v);
    delval(i*2+1,mid+1,r,s,f,v);
    IT[i].minv=min(IT[i*2].minv, IT[i*2+1].minv);
    IT[i].cnt=IT[i*2].cnt+IT[i*2+1].cnt;
}

void decseg(int i, int l, int r, int s, int f, int v){
    lazyupdate(i,l==r);
    if(f<l || s>r) return;
    if(s<=l && r<=f){
        IT[i].t=v;
        lazyupdate(i,l==r);
        return;
    }
    int mid=(l+r)>>1;
    decseg(i*2,l,mid,s,f,v); decseg(i*2+1,mid+1,r,s,f,v);
    IT[i].minv=min(IT[i*2].minv, IT[i*2+1].minv);
}

int count(int i, int l, int r, int s, int f){
    if(f<l || s>r) return 0;
    if(s<=l && r<=f) return IT[i].cnt;
    int mid=(l+r)>>1;
    return count(i*2,l,mid,s,f) + count(i*2+1,mid+1,r,s,f);   
}

//==============================================

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    int parent,t,id,x,minv;
    FOR(i,1,n){
        scanf("%d%d",&h[i],&parent); 
        edge[parent].pb(i);
    }
    cnt=-1;
    DFS(0);
    init(1,1,n);
    scanf("%d",&q);
    REP(tt,q){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d",&id,&x);   
            if(first[id]>last[id]) continue;
            minv=getmin(1,1,n,first[id],last[id]);
            while(minv<=x){
                delval(1,1,n,first[id],last[id],minv);
                minv=getmin(1,1,n,first[id],last[id]);  
            }
            decseg(1,1,n,first[id],last[id],x);
        }else{
            scanf("%d",&id);
            if(first[id]>last[id]) puts("0");
            else printf("%d\n",last[id]-first[id]+1-count(1,1,n,first[id],last[id]));
        }
    }   
    
    //getch();
    return 0;
}
