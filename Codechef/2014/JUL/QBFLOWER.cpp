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

bool a[maxn][maxn];
int match[maxn],T[maxn],myq[maxn],first,last,b[maxn];
bool inQueue[maxn],inPath[maxn],mark[maxn];
int n,m;

void push(int u){
    myq[++last]=u;
    inQueue[u]=1;
}

int pop(){
    int r=myq[first++];
    return r;
}

void initBFS(int start){
    reset(T,0);
    reset(inQueue,0);
    first=1; last=0;
    push(start);
    T[start]=-1;
    FOR(u,1,n) b[u]=u;
}

int lca(int start, int u, int v){
    reset(inPath,0);
    while(1){
        u=b[u];
        inPath[u]=1;
        if(u==start) break;
        u=T[match[u]];
    }
    while(1){
        v=b[v];
        if(inPath[v]) return v;
        v=T[match[v]];
    }
}

void reTrace(int r, int u){
    while(u!=r){
        int v=match[u];
        mark[b[v]]=mark[b[u]]=1;
        u=T[v];
        if(b[u]!=r) T[u]=v;
    }
}

void blossom(int start, int u, int v){
    int r=lca(start,u,v);
    reTrace(r,u); reTrace(r,v);
    if(b[u]!=r) T[u]=v;
    if(b[v]!=r) T[v]=u;
    FOR(u,1,n) if(mark[b[u]]) b[u]=r;
    FOR(u,1,n) if(!inQueue[u] && b[u]==r) push(u);
}

int find_path(int start){
    while(first<=last){
        int u=pop();
        FOR(v,1,n) if(a[u][v] && match[u]!=v && b[u]!=b[v])
            if(v==start || (match[v] && T[match[v]])) blossom(start,u,v);
            else if(T[v]==0){
                T[v]=u;
                if(match[v]==0) return v;
                push(match[v]);
            }
    }
    return -1;
}

void enlarge(int v){
    int u,next;
    while(v){
        u=T[v];
        next=match[u];
        match[u]=v;
        match[v]=u;
        v=next;
    }
}

int max_matching(){
    int res=0;
    reset(match,0);
    FOR(u,1,n) if(!match[u]){
        initBFS(u);
        int finish=find_path(u);
        if(finish!=-1){
            enlarge(finish);
            ++res;
        }
    }
    return res;
}

int main(){
    int x,y;
    scanf("%d%d",&n,&m);
    REP(i,m){
        scanf("%d%d",&x,&y);
        a[x][y]=a[y][x]=1;
    }
    cout<<n-max_matching()<<endl;
}
