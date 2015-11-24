#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=200007;

int BIT[maxn],n,a[maxn],res[maxn];

void update(int i, int v){
    for(;i<=n;i+=i&(-i)) BIT[i]+=v;
}

void init(){
    reset(BIT,0);
    for(int i=1; i<=n; ++i) update(i,1);
}

int get(int i){
    int ret = 0;
    for(;i;i-=i&(-i)) ret+=BIT[i];
    return ret;
}

int getTh(int th){
    int l=1,r=n,mid,res;
    while(l<=r){
        mid=(l+r)/2;
        if(get(mid)>th){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return res;
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    init();
    int v;
    for(int i=n; i>=1; --i){
        scanf("%d",&v);
        a[i]=get(v);
        update(v+1,-1);
    }
    init();
    for(int i=n; i>=1; --i){
        scanf("%d",&v);
        a[i]+=get(v);
        update(v+1,-1);
    }
    for(int i=1,t=0; i<=n; ++i){
        a[i]+=t;
        t=a[i]/i;
        a[i]%=i;
    }
    init();
    for(int i=n; i>=1; --i){
        res[i]=getTh(a[i]);
        update(res[i],-1);
        printf("%d ",res[i]-1);
    }
}

