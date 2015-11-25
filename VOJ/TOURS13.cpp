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

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}


const int maxn=1007;
const int maxm=100007;

vector<pii> a1[maxn],a2[maxn];
int n,m;
int nheap1,nheap2,heap1[maxn],heap2[maxn],d1[maxn],d2[maxn],pos1[maxn],pos2[maxn];
bool free1[maxn],free2[maxn];

void update1(int u){
    int child,parent;
    child=pos1[u];
    if(child==0) child=++nheap1;
    parent=child>>1;
    while(parent && d1[heap1[parent]]>d1[u]){
        heap1[child]=heap1[parent];
        pos1[heap1[child]]=child;
        child=parent;
        parent=child>>1;
    }
    heap1[child]=u;
    pos1[u]=child;
}

int pop1(){
    int res=heap1[1], u=heap1[nheap1--],r,c;
    r=1;
    while((r<<1)<=nheap1){
        c=r<<1;
        if(c<nheap1 && d1[heap1[c+1]]<d1[heap1[c]]) c++;
        if(d1[u]<=d1[heap1[c]]) break;
        heap1[r]=heap1[c]; pos1[heap1[r]]=r;
        r=c;
    }
    heap1[r]=u;
    pos1[u]=r;
    return res;
}

void update2(int u){
    int child,parent;
    child=pos2[u];
    if(child==0) child=++nheap2;
    parent=child>>1;
    while(parent && d2[heap2[parent]]>d2[u]){
        heap2[child]=heap2[parent];
        pos2[heap2[child]]=child;
        child=parent;
        parent=child>>1;
    }
    heap2[child]=u;
    pos2[u]=child;
}

int pop2(){
    int res=heap2[1], u=heap2[nheap2--], r,c;
    r=1;
    while((r<<1)<=nheap2){
        c=r<<1;
        if(c<nheap2 && d2[heap2[c+1]]<d2[heap2[c]]) c++;
        if(d2[u]<=d2[heap2[c]]) break;
        heap2[r]=heap2[c]; pos2[heap2[r]]=r;
        r=c;
    }
    heap2[r]=u;
    pos2[u]=r;
    return res;
}

int dijkstra(int s){
    int res=oo,u,v,w;
    pii *it, *itend;
    
    
    nheap1=nheap2=0;
    reset(pos1,0); reset(pos2,0);
    reset(free1,1); reset(free2,1);
    FOR(i,0,n) d1[i]=d2[i]=oo;
    d1[s]=d2[s]=0;
    update1(s); update2(s);
    while(nheap1 || nheap2){
        v=0;
        if(nheap1) v+=d1[heap1[1]];
        if(nheap2) v+=d2[heap2[1]];
        if(v>=res) break;
        if(nheap1){
            u=pop1();
            if(u==0) return d1[u];
            if(u!=s && !free2[u]) break;
            free1[u]=0;
            if(d1[u]>=res) break;
            if(a1[u].empty()) continue;
            it=&a1[u][0];
            itend=&a1[u][sz(a1[u])-1];
            for(;it<=itend; it++){
                v=it->fi; w=it->se;
                if(v==s) v=0;
                if(free1[v] && d1[v]>d1[u]+w){
                    d1[v]=d1[u]+w;
                    update1(v);
                    res=min(res,d1[v]+d2[v]);
                }
            }
        }
        if(nheap2){
            u=pop2();
            if(u==0) return d2[u];
            if(u!=s && !free1[u]) break;
            free2[u]=0;
            if(d2[u]>=res) break;
            if(a2[u].empty()) continue;
            it=&a2[u][0];
            itend=&a2[u][sz(a2[u])-1];
            for(;it<=itend; it++){
                v=it->fi; w=it->se;
                if(v==s) v=0;
                if(free2[v] && d2[v]>d2[u]+w){
                    d2[v]=d2[u]+w;
                    update2(v);
                    res=min(res,d2[v]+d1[v]);
                }
            }
        }
    }
    if(res==oo) return -1; else return res;
}
        

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,u,v,w;
    read(test);
    REP(index,test){
        read(n); read(m);
        FOR(i,1,n) a1[i].clear(), a2[i].clear();
        FOR(i,1,m){
            read(u); read(v); read(w);
            a1[u].pb(pii(v,w));
            a2[v].pb(pii(u,w));
        }
        FOR(i,1,n) printf("%d\n",dijkstra(i));
    }
    //cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
