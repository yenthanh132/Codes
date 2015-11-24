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

struct node{
    int v,size,priority;
    ll sum;
    node *left, *right, *parent;   
} *root, *nilT;

void setlink(node *x, node *y, bool inleft){
    y->parent=x;
    if(inleft) x->left=y; else x->right=y;   
}

node *new_node(int v){
    node *p = new node;
    p->v=v;
    p->size=1;
    p->sum=v;
    p->priority = rand();
    p->left=p->right=p->parent=nilT;
    return p;   
}

void update(node *x){
    x->sum = x->left->sum + x->right->sum + x->v;
    x->size = x->left->size + x->right->size + 1;       
}

void uptree(node *x){
    node *y=x->parent;
    if(y==nilT) return;
    node *z=y->parent;
    
    if(x==y->left){
        setlink(y,x->right,1);
        setlink(x,y,0);   
    }else{
        setlink(y,x->left,0);
        setlink(x,y,1);   
    }
    
    setlink(z,x,y==z->left);
    if(y==root) root=x;
    update(y); update(x);
}

void add(int v){
    if(root==nilT){
        root=new_node(v);
        return;
    }   
    node *x=root, *y=nilT;
    while(x!=nilT){
        y=x;
        if(v < y->v) x=x->left; else x=x->right;
    }   
    x=new_node(v);
    setlink(y,x,v < y->v);
    while(y!=nilT){
        y->size++;
        y->sum+=v;
        y=y->parent;
    }   
    while(x->parent!=nilT && x->parent->priority < x->priority) uptree(x);    
}

void del(int v){
    node *x=root;
    while(x!=nilT && x->v!=v){
        if(v<x->v) x=x->left; else x=x->right;
    }   
    if(x==nilT) return;
    while(x->left!=nilT && x->right!=nilT){
        if(x->left->priority > x->right->priority) uptree(x->left);
        else uptree(x->right);   
    }
    node *y=x->parent;
    node *z;
    if(x->left!=nilT) z=x->left; else z=x->right;
    setlink(y,z,x==y->left);
    if(x==root) root=z;
    while(y!=nilT){
        y->size--;
        y->sum-=v;
        y=y->parent;   
    }
    delete x;
}

void init(){
    nilT = new node;
    nilT->sum = nilT->size=0;
    nilT->priority=0;
    root=nilT;
}

int n,q,a[111111];

double cal(ll v){
    node *p = root;
    ll sum_left = 0, cnt_left=0;
    int pos=n+1;
    while(p!=nilT){
        if(1ll * p->v * (p->left->size+cnt_left) - (p->left->sum+sum_left) > v){
            pos=cnt_left+p->left->size+1;
            p=p->left;
        }else{
            sum_left+=p->left->sum + p->v;
            cnt_left+=p->left->size + 1; 
            p=p->right;
        }
    }   
    
    sum_left = 0, cnt_left = 0;
    p=root;
    while(p!=nilT){
        if(p->left->size + cnt_left + 1 == pos-1){
            ll k = v - ( 1ll*p->v*(p->left->size+cnt_left) - (p->left->sum+sum_left) );   
            return p->v + 1.0*k/(pos-1);
        }else if(p->left->size + cnt_left + 1 < pos-1){
            cnt_left += p->left->size+1;
            sum_left += p->left->sum + p->v;
            p=p->right;   
        }else 
            p=p->left;
    }
    return -1;
}

int main(){
    init();
    
    scanf("%d%d",&n,&q);
    FOR(i,1,n){
        scanf("%d",&a[i]);
        add(a[i]);   
    }
    
    int t,p,x;
    ll v;
    REP(i,q){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d",&p,&x);
            del(a[p]);
            a[p]=x;
            add(x);
        }else{
            scanf("%I64d",&v);  
            printf("%0.9lf\n",cal(v)); 
        }
    }
    
    return 0;
}
