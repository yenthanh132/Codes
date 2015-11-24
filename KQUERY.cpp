#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=30007;

int a[maxn],n,q,m;
vector<int> ds;

struct Node{
    Node *L, *R;
    int sum;
    Node(){
        sum=0;
        L=R=NULL;
    }
} *IT[maxn];

Node *update(Node *q, int l, int r, int x){
    Node *p = new Node;
    if(l==r){
        if(q) *p=*q;
        p->sum++;
        return p;
    }
    if(q) *p=*q;
    int mid=(l+r)/2;
    if(x<=mid) p->L = update(p->L,l,mid,x);
    else p->R = update(p->R,mid+1,r,x);
    ++p->sum;
    return p;
}

int get(Node *prev, Node *cur, int l, int r, int x){
    if(cur==NULL) return 0;
    if(r<=x){
        if(prev) return cur->sum - prev->sum;
        else return cur->sum;
    }
    if(l==r) return 0;
    int mid=(l+r)/2;
    if(x<=mid) return get((prev?prev->L:NULL),(cur?cur->L:NULL),l,mid,x);
    int left_part=0;
    if(cur->L){
        if(prev && prev->L) left_part = cur->L->sum - prev->L->sum;
        else left_part = cur->L->sum;
    }
    return left_part + get((prev?prev->R:prev), (cur?cur->R:NULL), mid+1,r,x);
}

int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]), ds.pb(a[i]);
    sort(ds.begin(),ds.end());
    ds.resize(unique(ds.begin(),ds.end())-ds.begin());
    m=sz(ds);
    for(int i=1; i<=n; ++i)
        a[i]=lower_bound(ds.begin(),ds.end(),a[i]) - ds.begin() + 1;
    IT[0]=NULL;
    for(int i=1; i<=n; ++i) IT[i]=update(IT[i-1],1,m,a[i]);
    scanf("%d",&q);
    for(int i=0; i<q; ++i){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        int v=lower_bound(ds.begin(),ds.end(),k)-ds.begin()+1;
        if(v<=m && ds[v-1]>k) --v;
        printf("%d\n", r-l+1 - get(IT[l-1],IT[r],1,m,v));
    }
}

