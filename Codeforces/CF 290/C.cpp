#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=333;
const int maxm=maxn*maxn;

int a[maxn],ia[maxn],b[maxn],ib[maxn],m,n;
int trace[maxn],N,M,S,F,head[maxn],jmp[maxm],myq[maxn];
bool free1[maxn];

struct edge{
    int x,y,c,f;
    edge(){}
    edge(int _x, int _y, int _c, int _f){
        x=_x; y=_y; c=_c; f=_f;
    }
}e[maxm];

bool isprime(int n){
    if(n==2 || n==3) return 1;
    if(n<2 || n%2==0 || n%3==0) return 0;
    int sn = sqrt(n);
    int k=0;
    do{
        k+=6;
        if(n%(k-1)==0 || n%(k+1)==0) break;
    }while(k-1<=sn);
    return k-1>sn;
}

void push(int x, int y, int c){
    e[M]=edge(x,y,c,0);
    jmp[M]=head[x];
    head[x]=M;
    ++M;
    e[M]=edge(y,x,0,0);
    jmp[M]=head[y];
    head[y]=M;
    ++M;
}

bool findpath(){
    int first=1,last=1;
    myq[1]=S;
    reset(trace,-1); trace[S]=0;
    while(first<=last){
        int u=myq[first++];
        for(int i=head[u]; i!=-1; i=jmp[i]){
            if(e[i].c>e[i].f && trace[e[i].y]==-1){
                trace[e[i].y]=i;
                if(e[i].y==F) return 1;
                myq[++last]=e[i].y;
            }
        }
    }
    return 0;
}

int flowval=0;

void incflow(){
    int delta=oo;
    int i,v=F;
    do{
        i=trace[v];
        delta=min(delta,e[i].c-e[i].f);
        v=e[i].x;
    }while(v!=S);
    v=F;
    do{
        i=trace[v];
        e[i].f+=delta;
        e[i^1].f-=delta;
        v=e[i].x;
    }while(v!=S);
    flowval += delta;
}

int cnt;
vector<int> ans[maxn];

void dfs(int u, int p){

    free1[u]=0;
    if(u<=m){
        ans[cnt].pb(ia[u]);
        for(int i=head[u]; i!=-1; i=jmp[i])
            if(e[i].f==1 && free1[e[i].y]){
                dfs(e[i].y,u);
                break;
            }

    }else{
        ans[cnt].pb(ib[u-m]);
        for(int i=head[u]; i!=-1; i=jmp[i]){
            int i2=i^1;
            if(e[i2].f==1 && free1[e[i2].x]){
                dfs(e[i2].x,u);
                break;
            }
        }
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    int CC;
    cin>>CC;
    m=n=0;
    for(int i=1; i<=CC; ++i){
        int v;
        cin>>v;
        if(v&1) a[++m]=v, ia[m]=i;
        else b[++n]=v, ib[n]=i;
    }
    if(m!=n){
        puts("Impossible");
        return 0;
    }

    N=m+n+2;
    S=N-1; F=N;
    M=0;
    reset(head,-1);
    for(int i=1; i<=m; ++i) push(S,i,2);
    for(int j=1; j<=n; ++j) push(j+m,F,2);
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j) if(isprime(a[i]+b[j])){
            push(i,j+m,1);
        }
    flowval = 0;
    while(findpath()) incflow();

    findpath();
    if(flowval < m*2){
        puts("Impossible");
        return 0;
    }

    reset(free1,1); cnt=0;
    for(int i=1; i<=m; ++i) if(free1[i]){
        ++cnt;
        dfs(i,-1);
    }

    cout<<cnt<<endl;
    for(int i=1; i<=cnt; ++i){
        cout<<sz(ans[i]);
        for(int j=0; j<sz(ans[i]); ++j) cout<<' '<<ans[i][j];
        cout<<endl;
    }
}

