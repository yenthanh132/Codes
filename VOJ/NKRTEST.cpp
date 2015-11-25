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

const int maxn=200007;
const int maxv=1000007;
const ll base=73471;

vector<int> a[maxn],b[maxn];
int n,m,q,d[maxn];
char str[maxv];
ll h[maxn];

struct trie_node{int c,t; trie_node *next[2];} *root;

struct queue_node{trie_node* p; int u;};
queue_node myqueue[maxn];
int front,rear;

void newnode(trie_node *&a){
    a = new trie_node;
    a->c=0;
    a->next[0]=a->next[1]=NULL;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    int u,v,c;
    REP(i,m){
        scanf("%d%d%d",&u,&v,&c);
        if(c==0){
            a[u].pb(v);
            a[v].pb(u);
        }else{
            b[u].pb(v);
            b[v].pb(u);
        }
    }
    
    newnode(root);
    reset(d,-1);
    d[1]=0; h[1]=1;
    queue_node x,y;
    x.p=root; x.u=1;
    myqueue[front=rear=1]=x;
    
    while(front<=rear){
        int l=front,r=front;
        x=myqueue[l];
        while(r<rear && h[myqueue[r+1].u]==h[x.u]) r++;
        FOR(i,l,r){
            x=myqueue[i];
            REP(j,sz(a[x.u])){
                y.u=a[x.u][j];
                if(d[y.u]==-1){
                    d[y.u]=d[x.u]+1;
                    h[y.u]=h[x.u]*base;
                    if(x.p->next[0]==NULL) newnode(x.p->next[0]);
                    y.p=x.p->next[0];
                    y.p->t=y.u;
                    y.p->c++;
                    myqueue[++rear]=y;
                }
            }
        }
        FOR(i,l,r){
            x=myqueue[i];
            REP(j,sz(b[x.u])){
                y.u=b[x.u][j];
                if(d[y.u]==-1){
                    d[y.u]=d[x.u]+1;
                    h[y.u]=h[x.u]*base+1;
                    if(x.p->next[1]==NULL) newnode(x.p->next[1]);
                    y.p=x.p->next[1];
                    y.p->t=y.u;
                    y.p->c++;
                    myqueue[++rear]=y;
                }
            }
        }
        front=r+1;
    }
    
    int k,s,len;
    trie_node *p;
    scanf("%d",&q);
    REP(index,q){
        
        scanf("%s",str+1);
        len=strlen(str+1);
        k=s=0;
        p=root;
        FOR(i,1,len)
            if(p->next[str[i]-'0']!=NULL){
                p=p->next[str[i]-'0'];
                k=i;
                s=p->c;
            }
            else break;
        
        if(k==len) printf("+%d %d\n",k,s); else printf("-%d %d\n",k,s);
    }
    
    //getch();
    return 0;
}
            
