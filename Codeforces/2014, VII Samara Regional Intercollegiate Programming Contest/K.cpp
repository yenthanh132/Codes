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

int n,m;
ll a[maxn],b[maxn],u[maxn],v[maxn];
ll bit1[maxn],bit2[maxn];

void update(ll *bit, int i, ll v){
    for(;i<=n; i+=i&(-i)) bit[i]=max(bit[i],v);
}

ll get(ll *bit, int i){
    ll res = 0;
    for(;i; i-=i&(-i)) res=max(res,bit[i]);
    return res;
}

int pos(ll *bit, ll v){
    int l=1,r=n,mid,res=n+1;
    while(l<=r){
        mid=(l+r)/2;
        if(get(bit,mid)>v){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%I64d",&a[i]);
        update(bit1,i,a[i]);
    }
    for(int i=1; i<=n; ++i){
        scanf("%I64d",&b[i]);
        update(bit2,i,b[i]);
    }

    scanf("%d",&m);
    for(int i=0; i<m; ++i) scanf("%I64d",&u[i]);
    for(int i=0; i<m; ++i) scanf("%I64d",&v[i]);
    for(int i=0; i<m; ++i){
        int pa=pos(bit1,u[i]);
        int pb=pos(bit2,v[i]);
        if(pa<pb) puts("Mike");
        else if(pa>pb) puts("Constantine");
        else puts("Draw");
    }

}

