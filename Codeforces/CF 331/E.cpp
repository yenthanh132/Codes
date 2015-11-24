#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=207;

int dx[11],dy[11];
int N,val[maxn*maxn],com[maxn][maxn],value[maxn*maxn],topo[maxn*maxn],cnt;
int m,n,q;
bool inDFS[maxn*maxn],free1[maxn*maxn];
pii trace[maxn][maxn];
char s[maxn][maxn];
vector<int> e[maxn*maxn];

void dfs(int i, int j){
    int id=s[i][j]-'0';
    int i2=i+dx[id], j2=j+dy[id];
    inDFS[i*n+j]=1;
    free1[i*n+j]=0;
    if(0<=i2 && i2<m && 0<=j2 && j2<n){
        if(free1[i2*n+j2]){
            trace[i2][j2]=pii(i,j);
            dfs(i2,j2);
        }else if(inDFS[i2*n+j2]){
            ++N;
            val[N] = 0;
            int x=i,y=j;
            while(x!=i2 || y!=j2){
                pii p=trace[x][y];
                val[N] |= 1<<(s[x][y]-'0');
                com[x][y]=N;
                x=p.first; y=p.second;
            }
            com[x][y]=N;
            val[N] |= 1<<(s[x][y]-'0');
        }
    }else{
        ++N;
        val[N] = 1<<id;
        com[i][j]=N;
    }
    inDFS[i*n+j]=0;
}

void dfs2(int u){
    free1[u]=0;
    for(int i=0; i<sz(e[u]); ++i){
        int v=e[u][i];
        if(free1[v]) dfs2(v);
    }
    topo[cnt--]=u;
}

char ss[1000007];
int state[1000007],pos[maxn*maxn],len;

bool isSubset(int child, int parent){
    for(int i=0; i<10; ++i) if(child>>i&1)
        if(!(parent>>i&1)) return 0;
    return 1;
}

int main(){
//    freopen("input.txt","r",stdin);

    scanf("%d%d%d",&m,&n,&q);
    for(int i=0; i<m; ++i) scanf("%s",s[i]);
    for(int i=0; i<10; ++i) scanf("%d%d",&dx[i],&dy[i]);

    N=0;
    cnt=0;
    reset(free1,1); reset(inDFS,0);
    for(int i=0; i<m; ++i) for(int j=0; j<n; ++j) if(free1[i*n+j]) dfs(i,j);
    for(int i=0; i<m; ++i) for(int j=0; j<n; ++j) if(com[i][j]==0){
        com[i][j]=++N;
        value[N] = s[i][j]-'0';
    }
    for(int i=0; i<m; ++i) for(int j=0; j<n; ++j){
        int id=s[i][j]-'0';
        int i2=i+dx[id], j2=j+dy[id];
        if(0<=i2 && i2<m && 0<=j2 && j2<n)
            if(com[i][j]!=com[i2][j2])
                e[com[i][j]].pb(com[i2][j2]);
    }

    reset(free1,1); cnt=N;
    for(int i=1; i<=N; ++i) if(free1[i]) dfs2(i);

    for(int tt=0; tt<q; ++tt){
        scanf("%s",ss); len=strlen(ss);
        state[len]=0;
        bool ok=0;
        for(int i=len-1; i>=0; --i){
            state[i] = state[i+1];
            state[i] |= 1<<(ss[i]-'0');
        }
        reset(pos,0);
        for(int it=1; it<=N; ++it){
            int i=topo[it];
            int newPos = pos[i];
            if(sz(e[i])>0){
                if(ss[newPos]-'0'==value[i]) ++newPos;
                if(newPos>=len){
                    ok=1;
                    break;
                }
                for(int j=0; j<sz(e[i]); ++j){
                    int i2=e[i][j];
                    pos[i2]=max(pos[i2],newPos);
                }
            }else{
                if(isSubset(state[newPos],val[i])){
                    ok=1;
                    break;
                }
            }
        }
        if(ok) puts("YES");
        else puts("NO");
    }
}

