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

const int maxn = 50001;
const int MAXINT=32767;

//TREAP
struct node{int v,size,priority,h,sumh; node *left, *right, *parent;} *root, *nil;

void init(){
    nil=new node;
    nil->v=nil->size=nil->priority=0;
    nil->h=nil->sumh=0;
    root=nil;
    srand(time(NULL));
}

node *newnode(int v, int h){
    node *p=new node;
    p->v=v; p->size=1; p->priority=rand()%MAXINT+1; p->h=p->sumh=h;
    p->left=p->right=p->parent=nil;
    return p;
}

void setlink(node *x, node *y, bool inleft){
    y->parent=x;
    if(inleft) x->left=y; else x->right=y;
}

void update(node *&x){
    x->size=x->left->size + x->right->size + 1;
    x->sumh=x->left->sumh + x->right->sumh + x->h;
}

void uptree(node *x){
    node *y=x->parent;
    node *z=y->parent;
    if(x==y->left){
        setlink(y,x->right,true);
        setlink(x,y,false);
    }else{
        setlink(y,x->left,false);
        setlink(x,y,true);
    }
    setlink(z,x,z->left==y);
    if(y==root) root=x;
    update(y); update(x);
}

void add(int v, int h){
    if(root==nil){
        root=newnode(v,h);
        return;
    }
    node *x=root, *y;
    while(x!=nil){
        y=x;
        if(v<y->v) x=y->left; else x=y->right;
    }
    x=newnode(v,h);
    setlink(y,x,v < y->v);
    while(y!=nil){
        y->size++;
        y->sumh+=h;
        y=y->parent;
    }
    while(x->parent!=nil && x->parent->priority < x->priority) uptree(x);
}

pii getval(int v){
    node *x=root;
    pii ans=pii(0,0);
    while(x!=nil)
        if(x->v <= v){
            ans.fi+=x->left->size+1;
            ans.se+=x->left->sumh + x->h;
            x=x->right;
        }else x=x->left;
    return ans;
}

pii getrange(int from, int to){
    pii a,b;
    a=getval(from-1); b=getval(to);
    return(pii(b.fi-a.fi,b.se-a.se));
}
//------------------------------------------        

int a[maxn], p[maxn], n, d,T;
double res;

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&T);
    REP(index,T){
        scanf("%d%d",&n,&d);
        FOR(i,1,n) scanf("%d",&a[i]);
        FOR(i,1,n) scanf("%d",&p[i]);
        res=0;
        init();
        add(a[n],100-p[n]);
        pii ans;
        FORD(i,n-1,1){
            ans=getval(a[i]-d-1);
            res += ans.fi;
            ans=getrange(a[i]-d,a[i]-1);
            res += (1.0*p[i]/100)*ans.fi + (1.0*ans.se/100)*(1.0*(100-p[i])/100);
            ans=getrange(a[i],a[i]+d-1);
            res += (1.0*p[i]/100)*(1.0*ans.se/100);
            add(a[i],100-p[i]);
        }
        printf("%0.4f\n",res);
    }
    //getch();
    return 0;
}
     
    
