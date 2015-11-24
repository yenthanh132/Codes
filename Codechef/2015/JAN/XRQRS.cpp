#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


const int maxn=500007;
const int maxBit=18;

struct node{
    int v;
    node *next[2];
    node(){
        v=0;
        next[0]=next[1]=NULL;
    }
    node(node *p){
        v=p->v;
        next[0]=p->next[0];
        next[1]=p->next[1];
    }
}*trie[maxn];

int N,M;

void add(int v){
    node *p = trie[N];
    trie[++N] = new node(p);
    node *q = trie[N];
    ++q->v;
    for(int i=maxBit; i>=0; --i){
        int b = v>>i&1;
        if(q->next[b]==NULL) q->next[b] = new node();
        else q->next[b] = new node(q->next[b]);
        q=q->next[b];
        ++q->v;
    }
}

void del(int k){
    N-=k;
}

int node_count(node *pl, node *pr){
    if(!pr) return 0;
    int ret = pr->v;
    if(pl) ret -= pl->v;
    return ret;
}

node* go(node *p, int x){
    if(p) return p->next[x];
    return NULL;
}

int query1(int l, int r, int x){
    node *pl = trie[l-1];
    node *pr = trie[r];
    int ret = 0;
    for(int i=maxBit; i>=0; --i){
        int b = x>>i&1;
        if(node_count(go(pl,1^b), go(pr,1^b))) b^=1;
        if(b) ret|=1<<i;
        pl=go(pl,b); pr=go(pr,b);
    }
    return ret;
}

int query3(int l, int r, int x){
    node *pl = trie[l-1];
    node *pr = trie[r];
    int ret = 0;
    for(int i=maxBit; i>=0; --i){
        int b=x>>i&1;
        if(b) ret += node_count(go(pl,0), go(pr,0));
        pl=go(pl,b); pr=go(pr,b);
    }
    ret+=node_count(pl,pr);
    return ret;
}

int query4(int l, int r, int x){
    node *pl = trie[l-1];
    node *pr = trie[r];
    int ret = 0;
    for(int i=maxBit; i>=0; --i){
        int c = node_count(go(pl,0), go(pr,0));
        int b;
        if(c>=x) b=0;
        else{
            x-=c;
            b=1;
        }
        pl=go(pl,b); pr=go(pr,b);
        if(b) ret |= 1<<i;
    }
    return ret;
}

int main(){
//    freopen("input.txt","r",stdin);
    N=0;
    trie[0]=new node();
    scanf("%d",&M);
    int k,x,y,z;

    for(int i=0; i<M; ++i){
        scanf("%d",&k);
        if(k==0){
            scanf("%d",&x);
            add(x);
        }else if(k==1){
            scanf("%d%d%d",&x,&y,&z);
            printf("%d\n",query1(x,y,z));
        }else if(k==2){
            scanf("%d",&x);
            del(x);
        }else if(k==3){
            scanf("%d%d%d",&x,&y,&z);
            printf("%d\n",query3(x,y,z));
        }else if(k==4){
            scanf("%d%d%d",&x,&y,&z);
            printf("%d\n",query4(x,y,z));
        }
    }
}

