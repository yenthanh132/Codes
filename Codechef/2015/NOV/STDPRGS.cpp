#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=50007;
struct query{
    int l,r,id;
}q[maxn];
int n,m,a[maxn],S;
ll ans[maxn];

bool cmp(const query &q1, const query &q2){
    if(q1.l/S != q2.l/S) return q1.l < q2.l;
    return q1.r < q2.r;
}

multiset<int> mys;
ll cost;
int dem;

void add(int i){

    if(mys.count(i)){
        mys.insert(i);
        return;
    }
    multiset<int>::iterator it = mys.lower_bound(i);
    ll l=-1,r=-1;
    if(it!=mys.end()) r=*it;
    if(it!=mys.begin()){
        --it;
        l=*it;
    }

    mys.insert(i);
    if(r!=-1 && l!=-1) cost -= sqr(r-l);
    if(r!=-1) cost += sqr(r-i);
    if(l!=-1) cost += sqr(i-l);
}

void del(int i){
    mys.erase(mys.find(i));
    if(mys.count(i)){
        return;
    }

    multiset<int>::iterator it = mys.lower_bound(i);
    ll l=-1,r=-1;
    if(it!=mys.end()) r=*it;
    if(it!=mys.begin()){
        --it;
        l=*it;
    }
    if(r!=-1 && l!=-1) cost += sqr(r-l);
    if(r!=-1) cost -= sqr(r-i);
    if(l!=-1) cost -= sqr(i-l);
}

int cnt[101][maxn];

int main(){
//    freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1; i<=m; ++i){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }

    bool subTest3=1;
    for(int i=1; i<=n; ++i) if(a[i]>100) subTest3=0;

    if(subTest3){
        for(int i=1; i<=n; ++i) cnt[a[i]][i]=1;
        for(int v=0; v<=100; ++v) for(int i=1; i<=n; ++i) cnt[v][i]+=cnt[v][i-1];
        for(int i=1; i<=m; ++i){
            int v_old=-1;
            int res=0;
            for(int v=0; v<=100; ++v) if(cnt[v][q[i].r]-cnt[v][q[i].l-1]>0){
                if(v_old!=-1) res += sqr(v-v_old);
                v_old = v;
            }
            printf("%d\n",res);
        }
        return 0;
    }

    S = int(sqrt(n));
    sort(q+1,q+m+1,cmp);
    mys.clear();
    cost=0;
    for(int x=q[1].l; x<=q[1].r; ++x) add(a[x]);
    int l=q[1].l, r=q[1].r;
    ans[q[1].id]=cost;
    dem=0;
    for(int i=2; i<=m; ++i){
        if(q[i].r-q[i].l<S){
            mys.clear();
            cost=0;
            for(int x=q[i].l; x<=q[i].r; ++x) add(a[x]);
            l=q[i].l;
            r=q[i].r;
        }else if(l<=q[i].l){
            while(r<q[i].r) add(a[++r]);
            while(r>q[i].r) del(a[r--]);
            while(l<q[i].l) del(a[l++]);
        }else{
            while(l>q[i].l) add(a[--l]);
            while(r<q[i].r) add(a[++r]);
            while(r>q[i].r) del(a[r--]);
        }
        ans[q[i].id]=cost;
    }
//    cout<<dem<<endl;
    for(int i=1; i<=m; ++i) printf("%lld\n",ans[i]);

}

