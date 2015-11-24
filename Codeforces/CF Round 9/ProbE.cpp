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

const int maxn=51;

int deg[maxn],n,m,lab[maxn],cset;
bool ok,free1[maxn],indfs[maxn];
multiset<int> a[maxn];

int getroot(int u){
    if(lab[u]<0) return u;
    int v=getroot(lab[u]);
    lab[u]=v;
    return v;
}

void dsu(int r1,int r2){
    if(r1==r2) return;
    cset--;
    if(lab[r1]<lab[r2]){
        lab[r1]+=lab[r2];
        lab[r2]=r1;
    }else{
        lab[r2]+=lab[r1];
        lab[r1]=r2;
    }
}

void dfs(int u){
    int v, r1,r2;
    free1[u]=0;
    indfs[u]=1;
    multiset<int>::iterator it;
    for(it=a[u].begin(); it!=a[u].end(); it++){
        v=*it;
        if(free1[v]){
            r1=getroot(u);
            r2=getroot(v);
            dsu(r1,r2);
            a[v].erase(a[v].find(u));
            dfs(v);
        }
        else if(indfs[v]) ok=0;
    }
    indfs[u]=0;
}

#include <conio.h>
int main(){
    int u,v,maxdeg;
    bool ring=0;
    
    //freopen("test.txt","r",stdin);
    reset(deg,0);
    cin>>n>>m;
    
    REP(index,m){
        cin>>u>>v;
        if(u==v) ring=1;
        deg[u]++; deg[v]++;
        a[u].insert(v); a[v].insert(u);
    }
    ok=1;
    maxdeg=deg[1];
    FOR(i,1,n){
        maxdeg=max(maxdeg,deg[i]);
        if(deg[i]!=2) ok=0;
    }
    if((ok && n==m && !ring) || (n==1 && m==1 && ring)){
        cout<<"YES\n0";
        return 0;
    }else if(m>n || maxdeg>2 || ring){
        cout<<"NO\n";
        return 0;
    }
    
    ok=1;
    reset(free1,true);
    reset(indfs,false);
    FOR(i,1,n) lab[i]=-1; cset=n;
    FOR(i,1,n) if(free1[i]) dfs(i);
    if(!ok){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    vector<pii> list;
    while(cset>1){
        ok=0;
        FOR(i,1,n-1){
            FOR(j,i+1,n) if(deg[i]<2 && deg[j]<2 && getroot(i)!=getroot(j)){
                deg[i]++; deg[j]++;
                u=i; v=j;
                ok=1;
                dsu(getroot(i),getroot(j));
                break;
            }
            if(ok) break;
        }
        list.pb(pii(u,v));
    }
    u=0;
    FOR(i,1,n) if(deg[i]<2) {u=i; deg[i]++; break;}
    FOR(i,1,n) if(deg[i]<2) {v=i; deg[i]++; break;}
    list.pb(pii(u,v));
    
    cout<<sz(list)<<endl;
    REP(i,sz(list)) cout<<list[i].fi<<' '<<list[i].se<<endl;
    //getch();
    return 0;
}
    
    
