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
multimap<int,int> endval;
map<pii,bool> mapendval;
set<int> saveval;
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

struct node{int u, parent, num;};
stack<node> mystack;
void dfs(){
    node start,t1,t2;
    int v,len;
    start.u=1;start.parent=0; start.num=1;
    mystack.push(start);
    map<int,int>::iterator it,itlow,ithigh;
    while (!mystack.empty()){
        t1=mystack.top(); mystack.pop();
        key[t1.u]=key[t1.parent]*prime+val[t1.u];
        d[t1.num]=t1.u;
        itlow=endval.lower_bound(val[t1.u]); ithigh=endval.upper_bound(val[t1.u]);
        for(it=itlow; it!=ithigh; it++) if(t1.num>=it->se){
            len=it->se;v=posL[len];
            hashvalue=key[t1.u]-key[d[t1.num-len]]*hashpow[len];
            while(mymap[v].find(hashvalue)!=mymap[v].end()){
                found[mymap[v].find(hashvalue)->se]=true;
                mymap[v].erase(mymap[v].find(hashvalue));
            }
        }
        REP(i,sz(a[t1.u])){
            v=a[t1.u][i];
            if(v!=t1.parent){
                t2.u=v; t2.parent=t1.u; t2.num=t1.num+1;
                mystack.push(t2);
            }
        }
    }
}

//#include<conio.h>

int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out2.txt","w",stdout);
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
        dfs();
        
        FOR(i,1,q) puts((found[i]?"Y":"N"));
    }
    //getch();
    return 0;
}
    
