#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

struct Node{
    int v;
    Node *next[2];
} *trie;

Node *newNode(){
    Node *p = new Node;
    p->next[0] = p->next[1] = NULL;
    p->v = 0;
    return p;
}

const int maxn=100007;

int T,n,a[maxn],Q,L[11],R[11];
ll res[11];

ll dem(int X, int R){
    ll ans = 0;
    Node *p = trie;
    for(int j=29; j>=0 && p; --j){
        int b=X>>j&1;
        int c=R>>j&1;
        if(c){
            if(p->next[b]) ans += p->next[b]->v;
            b^=1;
        }
        p = p->next[b];
    }
    return ans;
}

void add(Node *p, int X){
    for(int j=29; j>=0; --j){
        ++p->v;
        int b=X>>j&1;
        if(!p->next[b]) p->next[b] = newNode();
        p = p->next[b];
    }
    ++p->v;
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        scanf("%d",&Q);
        for(int i=1; i<=Q; ++i) scanf("%d%d",&L[i],&R[i]), res[i]=0;
        trie = newNode();
        a[0]=0; add(trie, a[0]);
        for(int i=1; i<=n; ++i){
            a[i]^=a[i-1];
            for(int j=1; j<=Q; ++j){
                res[j]-=dem(a[i],L[j]);
                res[j]+=dem(a[i],R[j]+1);
            }
            add(trie,a[i]);
        }
        for(int i=1; i<=Q; ++i) printf("%lld\n",res[i]);
    }
}

