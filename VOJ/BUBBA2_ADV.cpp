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
typedef pair<int, int> pii;
typedef pair<pii,int> iii;

const int maxn = 50001;

struct node{vector<int>list; node* flink; map<int,node*> next;} *root;

node* newnode(){
    node *t=new node;
    t->list=vector<int>();
    return t;
}

node* go(node *a, int v){
    if (a->next.find(v)==a->next.end()) return a; else return a->next[v];
}

vector<int> a[maxn];
int n,q,val[maxn];
bool res[maxn],free1[maxn];

void buildtree(){
    queue<node*> myqueue;
    map<int,node*>::iterator it;
    node *u, *v, *r;
    for(it=root->next.begin(); it!=root->next.end(); it++){
        v=it->se;
        myqueue.push(v);
        v->flink=root;
    }
    while(!myqueue.empty()){
        u=myqueue.front(); myqueue.pop();
        for(it=u->next.begin(); it!=u->next.end(); it++){
            v=it->se;
            myqueue.push(v);
            r=u->flink;
            while(r!=root && r->next.find(it->fi)==r->next.end()) r=r->flink;
            v->flink=go(r,it->fi);
            REP(i,sz(v->flink->list)) v->list.pb(v->flink->list[i]);
        }
    }
}

void addresult(node *&a){
    while(!a->list.empty()){
        res[a->list[sz(a->list)-1]]=true;
        a->list.pop_back();
    }
}

void dfs(int u, node *p){
    free1[u]=false;
    while(p!=root && p->next.find(val[u])==p->next.end()) p=p->flink;
    p=go(p,val[u]);
    addresult(p);
    int v;
    REP(i,sz(a[u])){
        v=a[u][i];
        if(free1[v]) dfs(v,p);
    }
}

//#include <conio.h>
int main(){
    //freopen("test.inp","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,u,v,k;
    node *p;
    scanf("%d",&T);
    REP(index,T){
        scanf("%d%d",&n,&q);
        FOR(i,1,n) scanf("%d",val+i);
        REP(i,n-1){
            scanf("%d%d",&u,&v);
            a[u].pb(v); a[v].pb(u);
        }
        root=newnode();
        reset(res,false);
        FOR(i,1,q){
            scanf("%d",&k);
            p=root;
            REP(j,k){
                scanf("%d",&v);
                if(p->next.find(v)==p->next.end()) p->next[v]=newnode();
                p=p->next[v];
            }
            p->list.pb(i);
        }
        buildtree();
        reset(free1,true);
        reset(res,false);
        dfs(1,root);
        FOR(i,1,q) puts(res[i]?"Y":"N");
    }
    //getch();
}
