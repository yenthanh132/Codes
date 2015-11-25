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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

const int maxn=50007;
const int maxnlen=321;
const int prime=73471;

int T, n, q, val[maxn], countL, d[maxn], num;
bool found[maxn];
vector<int> a[maxn];
multimap<ll,int> mymap[maxnlen];
set<int> saveval;
multimap<int,int> endval;
map<pii,bool> mapendval;
map<int,int> posL;


ll hashpow[maxn],key[maxn],hashvalue;

void init(){
    FOR(i,1,n) a[i]=vector<int>(), found[i]=false;
    countL=0; posL.clear(); endval.clear(); mapendval.clear();
    key[0]=0;
    FOR(i,1,maxnlen-1) mymap[i].clear();
    saveval.clear();
}

//--------------------------------------------
map<int,int>::iterator it,itlow,ithigh;

void dfs(int u, int parent){
    int v,i,len;
    ll hashvalue;
    key[u]=key[parent]*prime+val[u];
    d[++num]=u;
    //printf("%d ",num);
    itlow=endval.lower_bound(val[u]); ithigh=endval.upper_bound(val[u]);
    for(it=itlow; it!=ithigh; it++) if(num>=it->se){
        len=it->se;
        v=posL[len];
        hashvalue=key[u]-key[d[num-len]]*hashpow[len];
        while(mymap[v].find(hashvalue)!=mymap[v].end()){
            found[mymap[v].find(hashvalue)->se]=true;
            mymap[v].erase(mymap[v].find(hashvalue));
        }
    }
    for(i=0;i<sz(a[u]);i++){
        v=a[u][i];
        if(v!=parent) dfs(v,u);
    }
    num--;
}

//#include<conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int u,v,tlen;
    bool ok;
    hashpow[0]=1; FOR(i,1,50000) hashpow[i]=hashpow[i-1]*prime;
    
    scanf("%d",&T);
    REP(index,T){
        scanf("%d%d",&n,&q);
        init();
        
        FOR(i,1,n){
            scanf("%d",val+i);
            if(saveval.find(val[i])==saveval.end()) saveval.insert(val[i]);
        }
        REP(i,n-1){
            scanf("%d%d",&u,&v);
            a[u].pb(v); a[v].pb(u);
        }
        
        FOR(i,1,q){
            scanf("%d",&tlen);
            hashvalue=0;
            ok=true;
            FOR(j,1,tlen){
                scanf("%d",&v);
                if(saveval.find(v)==saveval.end()) ok=false;
                hashvalue=hashvalue*prime+v;
            }
            if(!ok) continue;
            if(posL.find(tlen)==posL.end()) posL[tlen]=++countL;
            mymap[posL[tlen]].insert(pli(hashvalue,i));
            if(mapendval[pii(v,tlen)]==0){endval.insert(pii(v,tlen)); mapendval[pii(v,tlen)]=1;}
        }
        num=0; d[0]=0;
        dfs(1,0);
        
        FOR(i,1,q) puts((found[i]?"Y":"N"));
    }
    //getch();
    return 0;
}
    
