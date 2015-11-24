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
    int c,v,sumv,maxv,mypoint,oppoint;
    bool winnode;
    node* next[26];
};

node* newnode(int v){
    node* p = new node;
    p->c = p->sumv = p->maxv=0;
    p->mypoint=0; p->oppoint=0;
    p->v=v;
    REP(k,26) p->next[k]=NULL;
    return p;
}

node* root;
int n;

void dfs(node *u){
    node* v;
    u->winnode=0;
    REP(k,26) if(u->next[k]!=NULL){
        v=u->next[k];
        v->sumv = v->v + u->sumv;
        v->maxv = max(v->v, u->maxv);
        dfs(v);
        if(v->winnode==0)
            u->winnode=1;
    }
    int myp,opp;
    REP(k,26) if(u->next[k]!=NULL){
        v=u->next[k];
        if(v->winnode ^ u->winnode){
            myp=v->oppoint + v->c + v->maxv*v->sumv;
            opp=v->mypoint;
            if(myp>u->mypoint){
                u->mypoint=myp;
                u->oppoint=opp;
            }else if(myp == u->mypoint && opp < u->oppoint)
                u->oppoint=opp;
        }
    }
}
                
#include <conio.h>    
int main(){
    freopen("test.txt","r",stdin);
    root=newnode(0);
    string s;
    cin>>n;
    REP(i,n){
        cin>>s;
        int len=sz(s);
        char ch;
        node* p=root;
        REP(j,len){
            ch=s[j];
            if(p->next[j]==NULL) p->next[j]=newnode(ch-'a'+1);
            p=p->next[j];
            p->c++;
        }
    }
    dfs(root);
    if(root->winnode){
        puts("First"); 
    }else{
        puts("Second");
    }
    printf("%d %d\n",root->mypoint,root->oppoint);
    getch();
    return 0;
}
    
