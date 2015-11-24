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

const int maxint=32768;

//Treap

struct node{int v,size,priority; node *left, *right, *parent;} *root, *nil;

void init(){
    srand(time(NULL));
    nil = new node;
    nil->v=nil->size=nil->priority=0;
    root=nil;
}

node *newnode(int v){
    node *p = new node;
    p->v=v; p->size=1; p->priority=rand()%maxint+1;
    p->left=p->right=p->parent=nil;
    return p;
}

void setlink(node *& x, node *& y, bool inleft){
    y->parent=x;
    if(inleft) x->left=y; else x->right=y;
}

void uptree(node *& x){
    node *y=x->parent, *z;
    z=y->parent;
    if(y->left==x){
        setlink(y,x->right,true);
        setlink(x,y,false);
    }else{
        setlink(y,x->left,false);
        setlink(x,y,true);
    }
    setlink(z,x,z->left==y);
    if(y==root) root=x;
    y->size=y->left->size+y->right->size+1;
    x->size=x->left->size+x->right->size+1;
}

void add(int v){
    if(root==nil){
        root=newnode(v);
        return;
    }
    node *x, *y;
    x=root;
    while(x!=nil){
        y=x;
        if(v < x->v) x=x->left; else x=x->right;
    }
    x=newnode(v);
    setlink(y,x,v<y->v);
    while(y!=nil){
        y->size++;
        y=y->parent;
    }
    while(x->parent!=nil && x->parent->priority < x->priority) uptree(x);
}

int getvalue(int pos){
    node *x = root;
    while(1){
        if(pos==x->left->size+1) return (x->v);
        else if(pos<=x->left->size) x=x->left;
        else{
            pos-=x->left->size+1;
            x=x->right;
        }
    }
}

int n,a,b;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    init();
    scanf("%d",&n);
    REP(index,n){
        scanf("%d",&a);
        if(a==1){
            scanf("%d",&b);
            add(b);
        }else
            if(root->size<3) printf("No reviews yet\n");
            else printf("%d\n",getvalue(root->size - root->size/3 + 1));
    }
    //getch();
    return 0;
}      
