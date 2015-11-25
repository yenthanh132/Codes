#include <stdio.h>
#include <ctime>
#include <stdlib.h>

#define MAXINT 32767

using namespace std;

struct node{int v,priority,size; node *left,*right,*parent;};

node sentinal;
node *tree, *nil;

void init(){
    sentinal.v=0; sentinal.priority=0; sentinal.size=0;
    nil=&sentinal;
    tree=nil;
    srand(time(NULL));
}

void setlink(node* x, node* y, bool inleft){
    y->parent=x;
    if (inleft) x->left=y; else x->right=y;
}

void uptree(node* x){
    node *y,*z;
    y=x->parent; z=y->parent;
    if (x==y->left){
        setlink(y,x->right,true);
        setlink(x,y,false);
    }else{
        setlink(y,x->left,false);
        setlink(x,y,true);
    }
    setlink(z,x,(z->left==y));
    if (tree==y) tree=x;
    y->size=y->left->size + y->right->size + 1;
    x->size=x->left->size + x->right->size + 1;
}

node* newnode(int v){
    node* p=new node;
    p->v=v; p->size=1; p->priority=rand()%MAXINT + 1;
    p->left=nil; p->right=nil; p->parent=nil;
    return p;
}

void add(int v){
    if (tree==nil){
        tree=newnode(v);
        return;
    }
    node *x,*y;
    x=tree; y=nil;
    while (x!=nil && x->v != v){
        y=x;
        if (v < y->v) x=x->left; else x=x->right;
    }
    if (x!=nil) return;
    x=newnode(v);
    setlink(y,x,v < y->v);
    while (y!=nil) (y->size)++, y=y->parent;
    while (x->parent!=nil && x->parent->priority < x->priority) uptree(x);
}

void del(int v){
    if (tree==nil) return;
    node *x, *y, *z;
    x=tree; 
    while (x!=nil && x->v!=v) if (v < x->v) x=x->left; else x=x->right;
    if (x==nil) return;
    while (x->left!=nil && x->right!=nil)
        if (x->left->priority>x->right->priority) uptree(x->left); else uptree(x->right);
    if (x->left!=nil) y=x->left; else y=x->right;
    z=x->parent;
    setlink(z,y,z->left==x);
    while (z!=nil) (z->size)--, z=z->parent;
    if (x==tree) tree=y;
    delete x;
}

node* getnode(int k){
    node *x=tree;
    while (1){
        if (x->left->size+1==k) return x;
        else if(k<=x->left->size) x=x->left;
        else {
            k-=x->left->size+1;
            x=x->right;
        }
    }
}

int count(int x){
    int res=0;
    node *p=tree;
    while (p!=nil)
        if (p->v < x) res+=p->left->size+1, p=p->right; else p=p->left;
    return res;
}

int main(){
    init();
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int q,i,v; char ch;
    scanf("%d\n",&q); 
    for(i=0;i<q;i++){
        scanf("%c%d\n",&ch,&v);
        if (ch=='I') add(v);
        else if(ch=='D') del(v);
        else if(ch=='K') if (v>tree->size || v<1) printf("invalid\n"); else printf("%d\n",getnode(v)->v);
        else printf("%d\n",count(v));
    }
    return 0;
}
