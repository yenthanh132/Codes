#include <stdio.h>
#include <string>
using namespace std;

struct node{int v,p; node *left,right,parent} *tree,nilT;
node sentinal;

void init(){
    sentinal.v=0;
    sentinal.p=0;
    nilT=&sentinal;
    tree=nilT;
}

void setlink(node *x, node *y,bool inleft){
    y->parent=x; 
    if (inleft) x->left=y; else x->right=y;
}

void uptree(node* x){
    node *y, *z;
    y=x->parent; z=y->parent;
    if (x==y->left){
        setlink(y,x->right,true);
        setlink(x,y,false);
    }
    
