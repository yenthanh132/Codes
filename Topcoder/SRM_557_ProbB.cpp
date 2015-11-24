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

const int maxn = 207;

vector<int> a[maxn],b[maxn],c[maxn];
int degin[maxn],degout[maxn],n,N,countcom,cnt,com[maxn],num[maxn],low[maxn],list[maxn],mX[maxn],mY[maxn],dis[maxn];
stack<int> stack1;
bool free1[maxn],arr[maxn][maxn],cirle[maxn];

void DFS(int u){
    int v;
    num[u]=low[u]=++cnt;
    stack1.push(u);
    REP(i,sz(a[u])){
        int v=a[u][i];
        if(free1[v])
            if(num[v]==0){
                DFS(v);
                low[u]=min(low[u],low[v]);
            }else low[u]=min(low[u],num[v]);
    }
    if(low[u]==num[u]){
        countcom++;
        do{
            v=stack1.top(); stack1.pop();
            free1[v]=0;
            com[v]=countcom;
        }while(v!=u);
    }
}

void DFS2(int u){
    free1[u]=0;
    int v;
    REP(i,sz(b[u])){
        v=b[u][i];
        if(free1[v]) DFS2(v);
    }
    list[cnt--]=u;
}

void pushe(int u, int v){
    if(arr[u][v]) return;
    arr[u][v]=1;
    c[u].pb(v);
}

void build(){
    int u,v;
    reset(degin,0); reset(degout,0);
    REP(u,n)
        REP(i,sz(a[u])){
            v=a[u][i];
            if(com[u]==com[v]) continue;
            b[com[u]].pb(com[v]);
            degout[com[u]]++; degin[com[v]]++;
        }
    REP(u,n) if(cirle[u]) b[com[u]].pb(com[u]);
    N=countcom;
    reset(free1,1);
    cnt=N;
    FOR(i,1,N) if(free1[i]) DFS2(i);
    reset(arr,0);
    FORD(i,N,1){
        u=list[i];
        REP(i,sz(b[u])){
            v=b[u][i];
            pushe(u,v);
            REP(j,sz(c[v])) pushe(u,c[v][j]);
        }
    }
}

// fast matching

bool findpath(){
    queue<int> myqueue;
    FOR(u,1,N) if(mX[u]==0) dis[u]=0, myqueue.push(u); else dis[u]=oo;
    dis[0]=oo;
    while(!myqueue.empty()){
        int u=myqueue.front(); myqueue.pop();
        REP(i,sz(c[u])){
            int v=c[u][i];
            if(dis[mY[v]]==oo){
                dis[mY[v]]=dis[u]+1;
                if(mY[v]) myqueue.push(mY[v]);
            }
        }
    }
    return dis[0]!=oo;
}

bool DFS3(int u){
    if(u==0) return 1;
    REP(i,sz(c[u])){
        int v=c[u][i];
        if(dis[mY[v]]==dis[u]+1 && DFS3(mY[v])){
            mX[u]=v; mY[v]=u;
            return 1;
        }
    }
    dis[u]=oo;
    return 0;
}

int getans(){
    reset(mX,0); reset(mY,0);
    int res=0;
    while(findpath())
        FOR(i,1,N) if(mX[i]==0 && DFS3(i)) res++;
    return N-res;
}

class Incubator {
public:
    
	int maxMagicalGirls(vector <string> love) {
		n=sz(love);
		reset(cirle,0);
		REP(i,n) REP(j,n)
                    if(love[i][j]=='Y'){
                        a[i].pb(j);
                        if(i==j) cirle[i]=1;
                    }
                
		reset(free1,1);
		cnt=countcom=0;
		REP(i,n) if(free1[i]) DFS(i);
		build();
		return getans();
	}
};


int main(){
    vector<string> love;
    love.pb("NNYNN");
    love.pb("NNYNN");
    love.pb("NNNYY");
    love.pb("NNNNN");
    love.pb("NNNNN");
    Incubator a;
    cout<<a.maxMagicalGirls(love)<<endl;
    system("pause");
}

//Powered by KawigiEdit 2.1.7 (beta) modified by pivanof!
