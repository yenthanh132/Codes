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


int l[222],r[222],lc,rc,n,m,k,dp[222][222][555][2][2];

int node_cnt;

struct node{
    node *next[22],*go[22],*fail,*parent;
    int v,match,ch,id;
    
    node(){
        id=++node_cnt;        
        v=0;
        ch=0;
        match=-1;
        REP(i,m) next[i]=go[i]=NULL;
        fail=parent=NULL;
    }
} *root;

queue<node*> myq;

void build(){
    root->fail = root;
    myq.push(root);
    while(!myq.empty()){
        node *p = myq.front(); myq.pop();
        REP(i,m) if(p->next[i]!=NULL) myq.push(p->next[i]);
        if(p==root) continue;
        node *fail = p->parent->fail;
        while(fail!=root && fail->next[p->ch] == NULL) fail=fail->fail;
        p->fail = fail->next[p->ch];
        if(p->fail == NULL || p->fail == p) p->fail = root;
    }
}

int cal(node *p){
    if(p==root) return 0;
    if(p->match!=-1) return p->match;
    int &res = p->match;
    res=cal(p->fail)+p->v;
    return res;
}

node *jump_to(node *p, int ch){
    if(p->go[ch]!=NULL) return p->go[ch];
    if(p->next[ch]!=NULL){
        p->go[ch]=p->next[ch];
        return p->go[ch];   
    }
    if(p==root){
        p->go[ch]=root;
        return p->go[ch];   
    }
    return (p->go[ch]=jump_to(p->fail,ch));
}

bool smaller;

int f(int *arr, int n, int i, node *p, int s, bool is, bool start){
    s += cal(p);
    if(s>k) return 0;
    if(i>n) return start && (smaller?is:1);
    if(dp[i][p->id][s][is][start]!=-1) return dp[i][p->id][s][is][start];    
    int &res = dp[i][p->id][s][is][start];
    res = 0;
    int top = is?(m-1):arr[i];
    FOR(v,0,top){
        res += f(arr, n, i+1, (v>0 || start)?jump_to(p,v):p, s, is | (v<arr[i]), start | (v>0));
        if(res>oo) res-=oo;
    }
    return res;
}

//Each string S will have value = sum(v of s * times s appear in S)
//Cal number of string S

int main(){
    scanf("%d%d%d",&n,&m,&k);    
    scanf("%d",&lc);
    FOR(i,1,lc) scanf("%d",&l[i]);
    scanf("%d",&rc);
    FOR(i,1,rc) scanf("%d",&r[i]);
    int len,v;
    node_cnt = 0;
    root = new node;
    REP(i,n){
        node *p = root;
        scanf("%d",&len);
        REP(j,len){
            scanf("%d",&v);
            if(p->next[v]==NULL){
                p->next[v]=new node;
                p->next[v]->ch = v;
                p->next[v]->parent = p;
            }
            p=p->next[v];   
        }
        scanf("%d",&v);
        p->v += v;
    }
    build();
    reset(dp,-1);
    smaller=0;
    int res1 = f(r,rc,1,root,0,0,0);
    reset(dp,-1);
    smaller=1;
    int res2 = f(l,lc,1,root,0,0,0);
    printf("%d\n",(res1-res2+oo)%oo);
    return 0;
}
