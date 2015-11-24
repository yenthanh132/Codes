#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=2007;

vector<int> e[maxn];
int n,m;

/* Graph matching */
bool inQueue[maxn];
int match[maxn], T[maxn], myq[maxn], first, last, b[maxn], inPath[maxn];
int lockX;
bool win[maxn];
vector<int> bList[maxn], freePoints;

void push(int u){
    myq[++last] = u;
    inQueue[u] = 1;
}

int pop(){
    return myq[first++];
}

void initBFS(int start){
    for(int u=1; u<=n; ++u) T[u] = 0, inQueue[u] = 0;
    first = 1; last = 0;
    push(start);
    T[start] = 1;
    for(int u=1; u<=n; ++u){
        b[u] = u;
        bList[u].clear();
        bList[u].pb(u);
    }
}

int cntLCA;

int lca(int start, int u, int v){
    ++cntLCA;
    while(1){
        u = b[u];
        inPath[u] = cntLCA;
        if(u == start) break;
        u = T[match[u]];
    }
    while(1){
        v = b[v];
        if(inPath[v]==cntLCA) return v;
        v = T[match[v]];
    }
}

int markList[maxn*2], cntMark;

void retrace(int r, int u){
    while (b[u] != r){
        int v = match[u];
        markList[++cntMark] = b[u];
        markList[++cntMark] = b[v];
        u = T[v];
        if(b[u] != r) T[u] = v;
    }
}


void blossom(int start, int u, int v){
    cntMark = 0;

    int r = lca(start, u, v); retrace(r,u); retrace(r,v);
    if(b[u] != r) T[u] = v;
    if(b[v] != r) T[v] = u;

    for(int i=1; i<=cntMark; ++i){
        int bIndex = markList[i];
        for(int i=0; i<sz(bList[bIndex]); ++i){
            int u = bList[bIndex][i];
            if(b[u] != r){
                b[u] = r;
                bList[r].pb(u);
                if(!inQueue[u])
                push(u);
            }
        }
        bList[bIndex].clear();
    }

}



int findPath(int start, bool markWin = false){

    while(first <= last){
        int u = pop();
        if(markWin) win[u] = 1;
        for(int i=0; i<sz(e[u]); ++i){
            int v = e[u][i];
            if(match[u] != v && b[u] != b[v])
                if(v == start || (match[v] && T[match[v]]))
                    blossom(start, u, v);
                else if(T[v] == 0){
                    T[v] = u;
                    if(match[v] == 0) return v;
                    push(match[v]);
                }
        }
    }
    return -1;
}

void enlarge(int v){
    int u, next;
    while(v){
        u = T[v];
        next = match[u];
        match[u] = v;
        match[v] = u;
        v = next;
    }
}

void doMatching(){
    for(int u=1; u<=n; ++u) match[u] = 0;
    for(int u=1; u<=n; ++u) if(!match[u]){
        initBFS(u);
        int finish = findPath(u);
        if(finish != -1) enlarge(finish);
    }
}


int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cntLCA = 0;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int u=1; u<=n; ++u) e[u].clear();
        for(int i=0,x,y; i<m; ++i){
            scanf("%d%d",&x,&y);
            e[x].pb(y); e[y].pb(x);
        }
        doMatching();

        freePoints.clear();
        for(int u=1; u<=n; ++u) win[u] = 0;
        for(int u = 1; u<=n; ++u)
            if(!match[u]){
                win[u] = 1;
                freePoints.pb(u);
            }

        for(int i=0; i<sz(freePoints); ++i){
            int u = freePoints[i];
            initBFS(u);
            findPath(u, 1);
        }
        int res = 0;
        for(int u=1; u<=n; ++u) if(win[u]) ++res;
        printf("%d\n",res);
    }
}

