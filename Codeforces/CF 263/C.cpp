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
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


using namespace std;


struct node{
    int v,size,sum;
    bool needSwap;
    node *left, *right, *parent;
} *root, *nilT;


void init(){
    nilT = new node;
    nilT->size = 0;
    nilT->sum = 0;
    root = nilT;
}

node * newnode(int v){
    node *p = new node;
    p->needSwap = 0;
    p->v = p->sum = v;
    p->size = 1;
    p->left = p->right = p->parent = nilT;
    return p;
}

void setlink(node *x, node *y, bool inleft){
    y->parent = x;
    if(inleft) x->left = y; else x->right = y;
}

void lazyUpdate(node *x){
    if(x==nilT || !x->needSwap) return;
    node *pl = x->left, *pr = x->right;
    setlink(x,pl,0); setlink(x,pr,1);
    x->needSwap = 0;
    x->left->needSwap ^=1;
    x->right->needSwap ^=1;
}

void uptree(node *x){
    node *y = x->parent;
    if(y==nilT) return;
    lazyUpdate(y); lazyUpdate(x);
    node *z = y->parent;
    if(x == y->left){
        setlink(y,x->right,1);
        setlink(x,y,0);
    }else{
        setlink(y,x->left,0);
        setlink(x,y,1);
    }
    setlink(z,x,z->left==y);
    if(y==root) root = x;
    y->size = 1 + y->left->size + y->right->size;
    y->sum = y->v + y->left->sum + y->right->sum;
    x->size = 1 + x->left->size + x->right->size;
    x->sum = x->v + x->left->sum + x->right->sum;
    lazyUpdate(z);
}

void splay(node *x){
    lazyUpdate(x);
    while(1){
        node *y=x->parent;
        if(y==nilT) return;
        node *z=y->parent;
        if(z != nilT && (z->left == y) == (y->left == x)) uptree(y);
        uptree(x);
    }
}

node *getnode(node *root, int idx){
    node *p = root;
    while(1){
        lazyUpdate(p);
        if(p->left->size + 1 == idx) return p;
        else if(p->left->size + 1 < idx){
            idx -= p->left->size + 1;
            p=p->right;
        }else p=p->left;
    }
}

void split(node *r,int idx, node *&ln, node *&rn){
    if(idx==0){
        ln=nilT;
        rn=r;
        return;
    }
    if(idx==r->size){
        ln=r;
        rn=nilT;
        return;
    }
    node *p = getnode(r,idx);
    splay(p);
    rn = p->right;
    rn->parent = nilT;
    p->right = nilT;
    p->size = p->left->size + 1;
    p->sum = p->left->sum + p->v;
    ln=p;
}

node *join(node *ln, node *rn){
    if(ln==nilT) return rn;
    if(rn==nilT) return ln;
    lazyUpdate(ln);
    while(ln->right!=nilT){
        ln = ln->right;
        lazyUpdate(ln);
    }
    splay(ln);
    setlink(ln,rn,0);
    ln->size = ln->left->size + ln->right->size + 1;
    ln->sum = ln->left->sum + ln->right->sum + ln->v;
    return ln;
}

int N,Q;

node* build_tree(int l, int r){
    if(l>r) return nilT;
    if(l==r) return newnode(1);
    int mid=(l+r)/2;
    node *p = newnode(1);
    p->left = build_tree(l,mid-1);
    p->right = build_tree(mid+1,r);
    p->left->parent = p->right->parent = p;
    p->size = 1 + p->left->size + p->right->size;
    p->sum = p->left->sum + p->right->sum + p->v;
    return p;
}

void query1(int A){
    node *ln, *mn, *rn;
    split(root,A,ln, rn);
    ln->needSwap ^= 1;
    int sr = rn->size;
    for(int i=1; i<=sr; ++i){
        if(ln==nilT) break;
        node *p = getnode(rn,i);
        node *q = getnode(ln,1);
        splay(q);
        splay(p);
        p->v += q->v;
        p->sum += q->v;
        rn = p;

        //delete node
        q->left->parent = q->right->parent = nilT;
        ln=join(q->left,q->right);
        delete q;

    }
    root = join(rn,ln);
}

int query2(int l, int r){
    node *ln, *mn, *rn;
    split(root,r,ln,rn);
    split(ln,l,ln,mn);
    int res = mn->sum;
    root = join(join(ln,mn),rn);
    return res;
}



int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&Q);
    init();
    root = build_tree(1,N);
    int k,l,r;
    for(int i=0; i<Q; ++i){
        scanf("%d%d",&k,&l);
        if(k==1){
            query1(l);
        }else{
            scanf("%d",&r);
            printf("%d\n",query2(l,r));
        }
    }
    return 0;
}

