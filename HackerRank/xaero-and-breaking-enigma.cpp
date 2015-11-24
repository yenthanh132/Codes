#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

struct node{
    int v,size;
    bool needSwap;
    node *left, *right, *parent;
} *root, *nilT;

void init(){
    nilT = new node;
    nilT->size = 0;
    root = nilT;
}

node * newnode(int v){
    node *p = new node;
    p->needSwap = 0; p->v = v; p->size = 1; p->left = p->right = p->parent = nilT;
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
    x->needSwap = 0; x->left->needSwap ^=1; x->right->needSwap ^=1;
}
void uptree(node *x){
    node *y = x->parent;
    if(y==nilT) return;
    lazyUpdate(y); lazyUpdate(x);
    node *z = y->parent;
    if(x == y->left){ setlink(y,x->right,1); setlink(x,y,0);}else{ setlink(y,x->left,0); setlink(x,y,1); }
    setlink(z,x,z->left==y);
    y->size = 1 + y->left->size + y->right->size;
    x->size = 1 + x->left->size + x->right->size;
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
        else if(p->left->size + 1 < idx){ idx -= p->left->size + 1; p=p->right;}else p=p->left;
    }
}
void split(node *r,int idx, node *&ln, node *&rn){
    if(idx==0){ ln=nilT; rn=r; return; }
    if(idx==r->size){ ln=r; rn=nilT; return; }
    node *p = getnode(r,idx);  splay(p);
    rn = p->right;  rn->parent = nilT;  p->right = nilT;   p->size = p->left->size + 1;  ln=p;
}
node *join(node *ln, node *rn){
    if(ln==nilT) return rn;  if(rn==nilT) return ln; lazyUpdate(ln);
    while(ln->right!=nilT){ ln = ln->right; lazyUpdate(ln); }
    splay(ln);  setlink(ln,rn,0);
    ln->size = ln->left->size + ln->right->size + 1;  return ln;
}

//==================================================

const int maxn=200007;
int N,M;
ll K;
char s[maxn];
int id[maxn];

node* initTree(int l, int r){
    if(l>r) return nilT;
    int mid=(l+r)/2;
    node *p = newnode(mid);
    p->left = initTree(l,mid-1);
    p->left->parent = p;

    p->right = initTree(mid+1,r);
    p->right->parent = p;

    p->size = 1 + p->left->size + p->right->size;

    return p;
}

int it;
void trace(node *p){
    lazyUpdate(p);
    if(p==nilT) return;
    trace(p->left);
    id[it++]=p->v;
    trace(p->right);
}

bool free1[maxn];
vector<int> lst[maxn];
int minId[maxn];
int cnt;
vector<int> num;

void dfs(int u){
    lst[cnt].pb(u);
    minId[cnt]=min(minId[cnt],u);
    free1[u]=0;
    int v=id[u];
    if(free1[v]) dfs(v);
}

bool cmp(const int &a, const int &b){
    return minId[a] > minId[b];
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d%lld",&N,&M,&K);
    scanf("%s",s+1);
    init();
    root=initTree(1,N);
    for(int i=0; i<M; ++i){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l<r){
            node *lp, *mp, *rp;
            split(root,r,mp,rp);
            split(mp,l-1,lp,mp);
            mp->needSwap ^= 1;
            root = join(join(lp,mp),rp);
        }
    }

    it=1;
    trace(root);
//    for(int i=1; i<=N; ++i) printf("%d ",id[i]); puts("");

    reset(free1,1);
    cnt=0;
    bool ok=1;

    for(int i=1; i<=N; ++i) if(free1[i]){
        ++cnt; lst[cnt].clear();
        minId[cnt]=oo;
        dfs(i);
        char x=0;
        for(int j=0; j<sz(lst[cnt]); ++j){
            int u = lst[cnt][j];
            if(s[u]!='?'){
                if(x!=0 && x!=s[u]){
                    ok=0;
                    break;
                }
                x=s[u];
            }
        }
        if(!ok) break;
        if(x==0) num.pb(cnt);
        else{
            for(int j=0; j<sz(lst[cnt]); ++j)
                s[lst[cnt][j]]=x;
        }
    }

    if(ok){
        if(sz(num)>0) sort(num.begin(),num.end(),cmp);
        --K;
        for(int i=0; i<sz(num); ++i){
            int u=num[i];
            char x = 'a'+K%26;
            for(int j=0; j<sz(lst[u]); ++j)
                s[lst[u][j]]=x;
            K/=26;
        }
        if(K>0) ok=0;

    }

    if(!ok) puts("Bad Luck Allen");
    else puts(s+1);

    return 0;
}

