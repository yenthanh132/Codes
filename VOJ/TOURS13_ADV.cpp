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
const int maxm=100007;

int n,m,adj[maxm],adjcost[maxm],head[maxn],link[maxm],ans[maxn];
int d[maxn],trace[maxn],heap[maxn],pos[maxn],nheap,myqueue[maxn],first,last,circuit[maxn],k;
bool free1[maxn],mark[maxn],inqueue[maxn];

void update(int u){
    int child,parent;
    if(pos[u]) child=pos[u]; else child=++nheap;
    parent=child/2;
    while(parent && d[heap[parent]]>d[u]){
        heap[child]=heap[parent];
        pos[heap[child]]=child;
        child=parent;
        parent=child/2;
    }
    heap[child]=u;
    pos[u]=child;
}

int pop(){
    int res=heap[1], v=heap[nheap--];
    int r=1,c;
    while(r*2<=nheap){
        c=r*2;
        if(c<nheap && d[heap[c+1]]<d[heap[c]]) c++;
        if(d[v]<=d[heap[c]]) break;
        heap[r]=heap[c];
        pos[heap[r]]=r;
        r=c;
    }
    heap[r]=v;
    pos[v]=r;
    return res;
}   

void dijkstra(int s){
    int i,x,y;
    reset(free1,1);
    nheap=0; reset(pos,0);
    FOR(i,1,n) d[i]=oo;
    i=head[s];
    while(i) d[adj[i]]=adjcost[i], update(adj[i]), trace[adj[i]]=s, i=link[i];    
    while(nheap){
        x=pop();
        free1[x]=0;
        if(x==s) break;
        i=head[x];
        while(i){
            y=adj[i];
            if(free1[y] && d[y]>d[x]+adjcost[i]){
                d[y]=d[x]+adjcost[i];
                update(y);
                trace[y]=x;
            }
            i=link[i];
        }
    }
    if(d[s]==oo){
        mark[s]=1;
        i=head[s];
        while(i){
            y=adj[i];
            if(!mark[y] && !inqueue[y]){
                myqueue[++last]=y;
                inqueue[y]=1;
            }
            i=link[i];
        }
        return;
    }
    x=s;
    circuit[k=1]=x; x=trace[x];
    mark[s]=1;
    while(x!=s){
        mark[x]=1;
        circuit[++k]=x;
        x=trace[x];
    }
    FOR(j,1,k){
        x=circuit[j];
        ans[x]=min(ans[x],d[s]);
        i=head[x];
        while(i){
            y=adj[i];
            if(!mark[y] && !inqueue[y]){
                myqueue[++last]=y;
                inqueue[y]=1;
            }
            i=link[i];
        }
    }
}
    
    

int main(){
    int test,cnt,u,v,w;
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&test);
    REP(index,test){
        scanf("%d%d",&n,&m);
        FOR(i,1,n) ans[i]=oo;
        first=1;last=0;cnt=0;
        reset(head,0); reset(mark,0); reset(inqueue,0);
        FOR(i,1,m){
            scanf("%d%d%d",&u,&v,&w);
            link[++cnt]=head[u];
            adj[cnt]=v; adjcost[cnt]=w;
            head[u]=cnt;
        }
        dijkstra(1);
        while(first<=last){
            u=myqueue[first++];
            dijkstra(u);
        }
        
        FOR(i,1,n) if(ans[i]==oo) puts("-1"); else printf("%d\n",ans[i]);
    }
    cout<<clock()*1.0/CLOCKS_PER_SEC<<endl;
    return 0;
}
            
        
        
