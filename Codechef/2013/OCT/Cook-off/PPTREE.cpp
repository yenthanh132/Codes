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

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}


//==================================

struct node{
    node *next[2];
} *root;

void del(node *u){
    if(u==NULL) return;
    del(u->next[0]);
    del(u->next[1]);
    delete u;
}

node *newnode(){
    node *p=new node;
    p->next[0] = p->next[1] = NULL;
    return p;      
}

void init(){
    del(root);
    root = newnode();
}

void add(int v){
    node *p=root;
    REPD(i,30){
        int b=(v>>i)&1;
        if(p->next[b]==NULL) p->next[b]=newnode();
        p=p->next[b];
    }   
}

int get(int v){
    node *p=root;
    int res=0;
    REPD(i,30){
        int b=(v>>i)&1;
        if(p->next[1^b]!=NULL){
            res|=1<<i; 
            p=p->next[1^b];
        }else if(p->next[b]!=NULL)
            p=p->next[b];
        else return -oo;
    }   
    return res;
}

const int maxn=100007;

int n,d[maxn];
vector<pii> e[maxn];


void dfs(int u, int p, int val){
    int v;
    d[u]=val;
    add(val);
    REP(i,sz(e[u])){
        v=e[u][i].fi;
        if(v==p) continue;
        dfs(v,u,val^e[u][i].se);
    }
}



//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    
    root=NULL;
    
    int T;
    read(T);
    REP(tt,T){
        read(n);
        FOR(i,1,n) e[i].clear();
        int u,v,w;
        REP(i,n-1){
            read(u); read(v); read(w);
            e[u].pb(pii(v,w));
            e[v].pb(pii(u,w));
        }
       
        init();
        int res=0;
        dfs(1,-1,0);
        FOR(i,1,n) res=max(res,get(d[i]));
        cout<<res<<endl;
    }
    //getch();
    return 0;
}
