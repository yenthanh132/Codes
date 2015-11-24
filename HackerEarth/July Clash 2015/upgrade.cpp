#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


/* SPLAY TREE */
struct node{
    int v,size,sum;
    bool needSwap;
    node *left, *right, *parent;
} *nilT;

void init(){
    nilT = new node;
    nilT->size = 0;
    nilT->sum = 0;
}

node * newnode(int v){
    node *p = new node;
    p->needSwap = 0;
    p->v = v;
    p->sum = v;
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

void updateNode(node *x){
    x->size = 1 + x->left->size + x->right->size;
    x->sum = x->v + x->left->sum + x->right->sum;
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
    updateNode(y); updateNode(x);
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

void split(node *r, node *&ln, node *&rn, int idx){
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
    updateNode(p);
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
    updateNode(ln);
    return ln;
}

/*======================================= */

const int maxn=100007;

int n,q,pre[maxn],pos[maxn],com[maxn],parent[17][maxn],val[maxn],cnt,depth[maxn],height[maxn],cntcom[maxn];
vector<int> e[maxn];
node* rootData[maxn];

void dfs(int u, int p){
    depth[u] = 1;
    for(int i=0,v; i<sz(e[u]); ++i){
        v=e[u][i];
        if(v==p) continue;
        parent[0][v]=u;
        height[v] = height[u]+1;
        dfs(v,u);
        depth[u] = max(depth[u], depth[v]+1);
    }
}

void dfs2(int u, int p){
    if(com[u]==0){
        com[u] = ++cnt;
        pre[u] = p;
        pos[u] = 1;
        rootData[cnt] = newnode(val[u]);
    }
    int best=-1;
    for(int i=0,v; i<sz(e[u]); ++i){
        v=e[u][i];
        if(v==p) continue;
        if(best==-1 || depth[best]<depth[v]) best=v;
    }
    if(best==-1) return;

    com[best] = com[u];
    pre[best] = pre[u];
    pos[best] = pos[u] + 1;
    rootData[cnt] = join(rootData[cnt], newnode(val[best]));
    dfs2(best,u);

    for(int i=0,v; i<sz(e[u]); ++i){
        v=e[u][i];
        if(v==p || v==best) continue;
        dfs2(v,u);
    }
}

int lca(int u, int v){
    if(height[u]>height[v]) swap(u,v);
    for(int i=0; i<17; ++i) if((height[v]-height[u])>>i&1) v=parent[i][v];
    if(u==v) return u;
    for(int i=16; i>=0; --i) if(parent[i][u]!=parent[i][v]){
        u=parent[i][u];
        v=parent[i][v];
    }
    return parent[0][u];
}

/* Query implementation */
int sumQuery(int u, int v){
    int r=lca(u,v);
    int res = 0, id;

    node *ln, *mn, *rn;
    //left part
    while(com[u]!=com[r]){
        id=com[u];
        split(rootData[id], ln, mn, pos[u]);
        res += ln->sum;
        rootData[id] = join(ln, mn);
        u=pre[u];
    }
    id = com[r];
    split(rootData[id], mn, rn, pos[u]);
    split(mn, ln, mn, pos[r]-1);
    res += mn->sum;
    rootData[id] = join(join(ln,mn),rn);

    //right part
    while(com[v]!=com[r]){
        id=com[v];
        split(rootData[id], ln, mn, pos[v]);
        res += ln->sum;
        rootData[id] = join(ln, mn);
        v=pre[v];
    }
    id = com[r];
    split(rootData[id], mn,rn, pos[v]);
    split(mn, ln, mn, pos[r]);
    res += mn->sum;
    rootData[id] = join(join(ln,mn),rn);
    return res;
}

void reverseQuery(int u, int v){
    int r=lca(u,v),id;
    //left part should take the top heavy-light node
    int x=v;
    while(com[x]!=com[r]) x=pre[x];
    if(x!=r) swap(u,v);

    node *ln, *mn, *rn;
    node *leftPart, *rightPart; //for the top node
    int sizePart;
    node *treePathLeft = nilT, *treePathRight = nilT;
    //left part
    x=u;
    while(com[x]!=com[r]){
        id = com[x];
        split(rootData[id], ln, mn, pos[x]);
        rootData[id] = mn;
        treePathLeft = join(ln, treePathLeft);
        x=pre[x];
    }
    id = com[r];
    split(rootData[id], mn, rightPart, pos[x]);
    split(mn, leftPart, mn, pos[r]-1);
    sizePart = mn->size;
    treePathLeft = join(mn, treePathLeft);

    //right part
    x=v;
    while(com[x]!=com[r]){
        id = com[x];
        split(rootData[id], ln, mn, pos[x]);
        rootData[id] = mn;
        treePathRight = join(ln, treePathRight);
        x = pre[x];
    }

    //join to the treePathLeft and reverse it
    treePathLeft->needSwap ^= 1;
    treePathLeft = join(treePathLeft, treePathRight);
    treePathLeft->needSwap ^= 1;


    // Reconstruct the tree path to the original tree
    x = u;
    while(com[x]!=com[r]){
        id = com[x];
        int len = cntcom[id] - rootData[id]->size;
        split(treePathLeft, ln, treePathLeft, len);
        ln->needSwap ^= 1;
        rootData[id] = join(ln, rootData[id]);
        x = pre[x];
    }
    id = com[r];
    split(treePathLeft, mn, treePathLeft, sizePart);
    mn->needSwap ^=1;
    rootData[id] = join(join(leftPart, mn), rightPart);

    x = v;
    while(com[x]!=com[r]){
        id = com[x];
        int len = cntcom[id] - rootData[id]->size;
        split(treePathLeft, treePathLeft, rn, treePathLeft->size - len);
        rootData[id] = join(rn, rootData[id]);
        x = pre[x];
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; ++i) scanf("%d",&val[i]);

    for(int i=0,u,v; i<n-1; ++i){
        scanf("%d%d",&u,&v);
        e[u].pb(v); e[v].pb(u);
    }

    //lca init
    height[1]=1;
    dfs(1,-1);
    for(int i=1; i<17; ++i)
        for(int u=1; u<=n; ++u) parent[i][u]=parent[i-1][parent[i-1][u]];

    //splay tree init
    init();

    //tree decomposition
    cnt = 0;
    reset(com,0);
    dfs2(1,-1);
    for(int i=1; i<=cnt; ++i) cntcom[i] = rootData[i]->size;

    //do query
    char key[5];
    int x,y;
    for(int i=0; i<q; ++i){
        scanf("%s%d%d",key,&x,&y);
        if(key[0]=='S') printf("%d\n", sumQuery(x,y));
        else reverseQuery(x,y);
    }

    return 0;

}

