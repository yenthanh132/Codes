#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

vector<int> pos[maxn];
int bit[maxn],a[maxn];
int n,m,ans[maxn];

struct query{
    int v,k,id;
} q[maxn];

bool cmp(const query &a, const query &b){
    return a.v>b.v;
}

void update(int i, int v){
    for(; i<=n; i+=i&(-i)) bit[i]+=v;
}

int get(int i){
    int r=0;
    for(; i; i-=i&(-i)) r+=bit[i];
    return r;
}

int getk(int k){
    int l=1, r=n, mid, pos;
    while(l<=r){
        mid=(l+r)/2;
        if(get(mid)>=k){
            pos=mid;
            r=mid-1;
        }else
            l=mid+1;
    }
    return pos;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]), pos[a[i]].pb(i);
    for(int i=1; i<=m; ++i) scanf("%d%d",&q[i].v,&q[i].k), q[i].id=i;
    sort(q+1,q+m+1,cmp);

    int it=100000;
    for(int i=1; i<=m; ++i){
        while(it>=q[i].v){
            for(int j=0; j<sz(pos[it]); ++j)
                update(pos[it][j],1);
            --it;
        }
        ans[q[i].id] = a[getk(q[i].k)];
    }

    for(int i=1; i<=m; ++i) printf("%d\n",ans[i]);
}

