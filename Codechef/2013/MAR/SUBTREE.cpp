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

const int maxn=200007;

int p[maxn][17], n, minlen[maxn][17], q, d[maxn], k, f[maxn], list1[maxn], list2[maxn], c1, c2, val[maxn];
int res1, res2, mark[maxn];
vector<pii> a[maxn];

void dfs(int u){
    int v;
    REP(i,sz(a[u])){
        v=a[u][i].fi;
        if(d[v]==-1){
            d[v]=d[u]+1;
            val[v]=val[u]+a[u][i].se;
            p[v][0]=u;
            minlen[v][0]=a[u][i].se;
            dfs(v);
        }
    }
}

int lca(int u, int v){
    if(d[u]>d[v]) swap(u,v);
    REPD(i,17) if(((d[v]-d[u])>>i)&1) v=p[v][i];
    if(u==v) return u;
    REPD(i,17) if(p[u][i]!=p[v][i]){
        u=p[u][i];
        v=p[v][i];
    }
    return p[u][0];
}

int step(int u, int v){
    int r=lca(u,v);
    return d[u]+d[v]-d[r]*2;
}

int dis(int u, int v){
    int r=lca(u,v);
    return val[u]+val[v]-val[r]*2;
}

int jump(int u, int len){
    int i=0;
    while(len){
        if(len&1) u=p[u][i];
        i++;
        len>>=1;
    }
    return u;
}

int get_node(int s, int f, int pos, int len){
    if(pos==0) return s;
    if(pos==len) return f;
    int r=lca(s,f);
    if(pos<=d[s]-d[r]) return jump(s,pos);
    else return jump(f,len-pos);
}

bool check(int v){
    int maxdis=dis(list1[1],v);
    FOR(i,2,c1) if(maxdis!=dis(list1[i],v)) return 0;
    maxdis=dis(list2[1],v);
    FOR(i,2,c2) if(maxdis!=dis(list2[i],v)) return 0;
    return 1;
}

int get_min_len(int u, int v){
    if(u==v) return oo;
    if(d[u]>d[v]) swap(u,v);
    int res=oo;
    REPD(i,17) if(((d[v]-d[u])>>i)&1){
        res=min(res,minlen[v][i]);
        v=p[v][i];
    }
    if(u==v) return res;
    REPD(i,17) if(p[u][i]!=p[v][i]){
        res=min(res,min(minlen[u][i],minlen[v][i]));
        u=p[u][i]; v=p[v][i];
    }
    res=min(res,min(minlen[u][0],minlen[v][0]));
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    int u,v,w;    
    REP(index,n-1){
        scanf("%d%d%d",&u,&v,&w);
        a[u].pb(pii(v,w));
        a[v].pb(pii(u,w));
    }
    //pre LCA
    FOR(i,1,n) d[i]=-1; d[1]=0; val[1]=0;
    dfs(1);
    FOR(i,1,16) FOR(v,1,n){
        u=p[v][i-1];
        p[v][i]=p[u][i-1];
        minlen[v][i]=min(minlen[v][i-1],minlen[u][i-1]);
    }
    
    //Solve
    int maxdis, vleft, vright, left, right, mid, t, vstep;
    
    scanf("%d",&q);
    REP(index,q){
        scanf("%d",&k);
        FOR(i,1,k) scanf("%d",&f[i]);
        maxdis=-1;
        FOR(i,1,k){
            v=dis(f[1],f[i]);
            if(v>maxdis) list1[c1=1]=f[i], maxdis=v;
            else if(v==maxdis) list1[++c1]=f[i];
        }
        maxdis=-1;
        FOR(i,1,k){
            v=dis(list1[1], f[i]);
            if(v>maxdis) list2[c2=1]=f[i], maxdis=v;
            else if(v==maxdis) list2[++c2]=f[i];
        }
        
        
        u=list1[1]; v=list2[1];
        res1=maxdis;
        
        //check center node
        int cnt=0;
        FOR(i,1,c1) mark[list1[i]]=index+1, cnt++;
        FOR(j,1,c2) if(mark[list2[j]]!=index+1) cnt++;
        if(cnt<c1+c2){
            if(cnt>2) res2=-1;
            else{
                u=list1[1];
                if(c1>1) v=list1[2]; else v=list2[1];
                if(u==v) v=list2[2];
                res2=get_min_len(u,v);
            }
            
            printf("%d %d\n",res1,res2);
            continue;
        }
        
        vstep=step(u,v);
        left=0; right=vstep;
        while(left<=right){
            mid=(left+right)>>1;
            t=get_node(u,v,mid,vstep);
            if(check(t)){
                right=mid-1;
                vleft=t;
            }else left=mid+1;
        }
        left=0; right=vstep;
        while(left<=right){
            mid=(left+right)>>1;
            t=get_node(u,v,mid,vstep);
            if(check(t)){
                left=mid+1;
                vright=t;
            }else right=mid-1;
        }
        
        res2=get_min_len(vleft,vright);
        if(res2==oo) res2=-1;
        printf("%d %d\n",res1,res2);
    }
    //getch();
    return 0;
}
    
