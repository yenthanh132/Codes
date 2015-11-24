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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000000003ll

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;
const int maxm=107;

struct edge{
    int x,y,w;
    edge(){}
    edge(int a, int b, int c):x(a),y(b),w(c){}
}e[maxm];

bool cmp(const edge &e1, const edge &e2){
    return e1.w < e2.w;
}

ll mat[maxn][maxn];
int n,m,lab[maxn],mark[maxn],num,arr[maxn],k,cnt,id[maxn];
vector<int> e2[maxn];

ll mul(ll a, ll b){
    if(a<0) a+=oo;
    if(b<0) b+=oo;
    if(a<b) swap(a,b);
    if(b==0) return 0;
    ll t = mul(a,b/2);
    t=t*2;
    if(b&1) t+=a;
    return t%oo;
}

ll mypow(ll base, ll n){
    if(n==1) return base;
    ll t=mypow(base,n/2);
    t=mul(t,t);
    if(n&1) return mul(t,base);
    return t;
}

ll gauss(int n){
    for(int i=1; i<=n; ++i){
        if(mat[i][i]==0){
            for(int j=i+1; j<=n; ++j) if(mat[j][i]!=0){
                for(int k=i; k<=n; ++k) swap(mat[i][k],mat[j][k]);
                break;
            }
        }
        for(int j=i+1; j<=n; ++j) if(mat[j][i]!=0){
            ll x = mul(mat[j][i], mypow(mat[i][i],oo-2));
            for(int k=i; k<=n; ++k){
                mat[j][k] -= mul(mat[i][k], x);
                if(mat[j][k]<0) mat[j][k]+=oo;
            }
        }
    }
    ll res = 1;
    for(int i=1; i<=n; ++i) res = mul(res,mat[i][i]);
    return res;
}

int getroot(int u){
    if(lab[u]<0) return u;
    lab[u]=getroot(lab[u]);
    return lab[u];
}

void join(int r1, int r2){
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}


void dfs1(int u){
    id[u]=++cnt;
    int v;
    for(int i=0; i<sz(e2[u]); ++i){
        v=e2[u][i];
        if(id[v]==-1) dfs1(v);
    }
}

void dfs2(int u){
    mark[u] = num;
    int v,idu,idv;
    idu = id[u];
    mat[idu][idu] = sz(e2[u]);
    for(int i=0; i<sz(e2[u]); ++i){
        v=e2[u][i]; idv = id[v];
        if(mark[v] != num) dfs2(v);
        mat[idu][idv] -= 1;
    }
}

//calculate the number of minimum spanning tree
ll cal(){
    ll res = 1;
    sort(e,e+m,cmp);
    for(int u=1; u<=n; ++u) lab[u]=-1;
    num = 0;
    reset(mark,0);

    for(int i=0,j; i<m; i=j+1){
        j=i;
        while(j+1<m && e[j+1].w == e[i].w) ++j;

        //consider all edges with the same length
        ++num; k = 0;
        for(int z=i; z<=j; ++z){
            int x = getroot(e[z].x), y = getroot(e[z].y);
            if(x==y) continue;
            if(mark[x]!=num){
                e2[x].clear();
                mark[x]=num;
                arr[++k] = x;
            }
            if(mark[y]!=num){
                e2[y].clear();
                mark[y]=num;
                arr[++k] = y;
            }
            e2[x].pb(y);
            e2[y].pb(x);
        }
        // loop all components
        ++num;
        for(int z=1; z<=k; ++z) id[arr[z]]=-1;
        for(int z=1; z<=k; ++z) if(id[arr[z]]==-1){
            int x = arr[z];
            cnt = 0;
            dfs1(x); //mark id for each vertex
            for(int i=1; i<=cnt; ++i) for(int j=1; j<=cnt; ++j) mat[i][j] = 0;
            dfs2(x); //create the matrix
            res *= gauss(cnt-1);
        }

        //merge vertices in each component into one vertex
        for(int z=i; z<=j; ++z){
            int x = getroot(e[z].x), y = getroot(e[z].y);
            if(x!=y) join(x,y);
        }
    }
    return res;
}

ll gcd(ll a, ll b){
    if(a<b) return gcd(b,a);
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    //freopen("input.txt","r",stdin);
    int x,y,w;
    scanf("%d%d",&n,&m);
    int t=0;
    reset(mat,0);
    for(int i=0; i<m; ++i){
        scanf("%d%d%d",&x,&y,&w);
        if(x==y) continue;
        e[t++]=edge(x,y,w);
        mat[x][x]+=1;
        mat[y][y]+=1;
        mat[x][y]-=1;
        mat[y][x]-=1;
    }
    m=t;
    ll total = gauss(n-1);
    ll val = cal();
    ll d = gcd(val, total);
    cout<<val/d<<'/'<<total/d<<endl;
    return 0;
}
