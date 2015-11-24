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

pii a[maxn];
int bit[maxn*2],lst[maxn],m,n;

int pos(int v){
    return lower_bound(lst+1,lst+m+1,v)-lst;
}

void update(int i, int v){
    for(;i<=m;i+=i&(-i)) bit[i]=max(bit[i],v);
}

int get(int i){
    int v=0;
    for(;i;i-=i&(-i)) v=max(v,bit[i]);
    return v;
}

int main(){
//    freopen("input.txt","r",stdin);
    m=0;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d%d",&a[i].first,&a[i].second);
        lst[++m]=a[i].first-a[i].second;
        lst[++m]=a[i].first+a[i].second;
    }
    sort(a+1,a+n+1);
    sort(lst+1,lst+m+1);
    m=unique(lst+1,lst+m+1)-lst-1;
    reset(bit,0);
    int res=0;
    for(int i=1; i<=n; ++i){
        int v=get(pos(a[i].first-a[i].second));
        res=max(res,v+1);
        update(pos(a[i].first+a[i].second),v+1);
    }
    cout<<res<<endl;
}

