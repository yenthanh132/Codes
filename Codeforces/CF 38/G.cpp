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

const int MAXINT=32768;

struct node{
    int id,v,maxv,size,priority;
    node* left, *right, *parent;
}*nilT, *root, sentinal;

void init(){
    sentinal.priority=0;
    sentinal.size=0;
    sentinal.maxv=0;
    sentinal.v=0;
    nilT=&sentinal;
    root=nilT;
}

void setlink(node*x, node*y, bool inleft){
    y->parent=x;
    if(inleft) x->left=y; else x->right=y;
}

void updatenode(node *x){
    x->size = x->left->size + x->right->size + 1;
    x->maxv = max(max(x->left->maxv, x->right->maxv), x->v);
}

void uptree(node *x){
    node *y=x->parent;
    if(y==nilT) return;
    node *z=y->parent;
    if(x == y->left){
        setlink(y,x->right,1);
        setlink(x,y,0);
    }else{
        setlink(y,x->left,0);
        setlink(x,y,1);
    }
    setlink(z,x,z->left==y);
    if(y==root) root=x;
    updatenode(y); updatenode(x);
}
    
node * newnode(int id, int v){
    node *p=new node;
    p->v=p->maxv=v;
    p->size=1;
    p->priority=rand()%MAXINT;
    p->id=id;
    p->left = p->right = p->parent = nilT;
    return p;
}

node * findnode(int v, int c){
    node *x=root;
    while(1){
        if(x->right->maxv > v || x->right->size > c) x = x->right;
        else{
            c-=x->right->size;
            if(x->v > v || c==0) return x;
            else{
                c--;
                x=x->left;
            }
        }
    }
}

void insert(int id, int v, int c){
    if(root==nilT){
        root=newnode(id,v);
        return;
    }
    node *x, *newN = newnode(id,v);
    if(root->maxv < v && root->size <= c){
        //Insert at the head
        x=root;
        while(x->left != nilT) x=x->left;
        setlink(x,newN,1);
    }    
    else{
        x = findnode(v,c);
        if(x->right == nilT) setlink(x,newN,0);
        else{
            x=x->right;
            while(x->left != nilT) x=x->left;
            setlink(x,newN,1);
        }
    }
    while(x != nilT){
        updatenode(x);
        x=x->parent;
    }
    while(newN->parent != nilT && newN->parent->priority < newN->priority) uptree(newN);
}

const int maxn=100007;
int arr[maxn],n,c;

void output(node *p){
    if(p==nilT) return;
    output(p->left);
    arr[++c]=p->id;
    output(p->right);
}
 
#include <conio.h>   
int main(){
    //freopen("test.txt","r",stdin);
    
    scanf("%d",&n);
    int v,c;
    init();
    srand(time(NULL));
    FOR(i,1,n){
        scanf("%d%d",&v,&c);
        insert(i,v,c);
        
    }
    c=0;
    output(root);
    FOR(i,1,n) printf("%d ",arr[i]);
    puts("");
    
    //getch();
    return 0;
}
