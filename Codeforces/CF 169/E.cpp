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

int n,com[maxn],d[maxn],q,cntcom[maxn],val1;
int** BIT;
vector<int> a[maxn];

void dfs(int u,int p){
    int v;
    cntcom[com[u]]++;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(v==p) continue;
        com[v]=com[u];
        d[v]=d[u]+1;
        dfs(v,u);
    }
}

void update(int* a, int p, int v){
    for(int i=p; i; i-=i&(-i)) a[i]+=v;
}

int get(int *a, int p, int n){
    int res=0;
    for(int i=p; i<=n; i+=i&(-i)) res+=a[i];
    return res;
}

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&q);
    int u,v,k,x,D;
    FOR(i,1,n-1){
        scanf("%d%d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
    }
    BIT=new int*[sz(a[1])+2];
    REP(i,sz(a[1])){
        v=a[1][i];
        com[v]=i+1;
        d[v]=1;
        dfs(v,1);
        BIT[i+1]=new int[cntcom[i+1]+2];
        FOR(j,1,cntcom[i+1]) BIT[i+1][j]=0;
        cntcom[0]=max(cntcom[0],cntcom[i+1]);
    }
    BIT[0]=new int[cntcom[0]+2];
    FOR(j,1,cntcom[0]) BIT[0][j]=0;
    val1=0;
    REP(index,q){
        scanf("%d%d",&k,&v);
        if(k==0){
            scanf("%d%d",&x,&D);
            if(v==1){
                val1+=x;
                update(BIT[0],min(D,cntcom[0]),x);
            }else{
                update(BIT[com[v]],min(d[v]+D,cntcom[com[v]]),x);
                if(D>=d[v]){
                    val1+=x;
                    update(BIT[0],min(cntcom[0],D-d[v]),x);
                    update(BIT[com[v]],min(cntcom[com[v]],D-d[v]),-x);
                }else update(BIT[com[v]],d[v]-D-1,-x);
            }
        }else{
            if(v==1) printf("%d\n",val1); else
            printf("%d\n",get(BIT[com[v]],d[v],cntcom[com[v]]) + get(BIT[0],d[v],cntcom[0]));
        }
    }
    
    return 0;
}
