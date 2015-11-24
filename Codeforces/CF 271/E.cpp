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

int n,cnt;
pii bit1[maxn],bit2[maxn];
ll d,h[maxn],lh[maxn];
int toLeft[maxn],toRight[maxn],f[maxn],trace[maxn];
vector<int> ans;

void update_up(pii *bit, int i, pii v){
    for(;i<=cnt; i+=i&(-i)) bit[i]=max(bit[i],v);
}

void update_down(pii *bit, int i, pii v){
    for(;i; i-=i&(-i)) bit[i]=max(bit[i],v);
}

pii get_down(pii *bit, int i){
    pii res = pii(-1,-1);
    for(;i; i-=i&(-i)) res=max(res,bit[i]);
    return res;
}

pii get_up(pii *bit, int i){
    pii res = pii(-1,-1);
    for(;i<=cnt; i+=i&(-i)) res=max(res,bit[i]);
    return res;
}

int hpos(ll h){
    return lower_bound(lh+1,lh+cnt+1,h)-lh;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%I64d",&n,&d);
    for(int i=1; i<=n; ++i) scanf("%I64d",&h[i]), lh[i]=h[i];
    sort(lh+1,lh+n+1);
    cnt=unique(lh+1,lh+n+1)-(lh+1);
    for(int i=1,j=1; i<=cnt; ++i){
        while(j<=i && lh[i]-lh[j]>=d) ++j;
        toLeft[i]=j-1;
    }
    for(int i=cnt,j=cnt; i>=1; --i){
        while(j>=i && lh[j]-lh[i]>=d) --j;
        toRight[i]=j+1;
    }
    for(int i=1; i<=cnt; ++i) bit1[i]=bit2[i]=pii(-1,-1);
    for(int i=1; i<=n; ++i){
        f[i]=1;
        trace[i]=-1;
        int x=hpos(h[i]);
        pii t=get_down(bit1,toLeft[x]);
        if(t.first+1>f[i]){
            f[i]=t.first+1;
            trace[i]=t.second;
        }
        t=get_up(bit2,toRight[x]);
        if(t.first+1>f[i]){
            f[i]=t.first+1;
            trace[i]=t.second;
        }
        if(f[i]>0){
            update_up(bit1,x,pii(f[i],i));
            update_down(bit2,x,pii(f[i],i));
        }
    }
    int u=1,res=1;
    for(int i=2; i<=n; ++i) if(f[i]>res){
        res=f[i];
        u=i;
    }
    printf("%d\n",res);
    while(u!=-1){
        ans.pb(u);
        u=trace[u];
    }
    for(int i=sz(ans)-1; i>=0; --i) printf("%d ",ans[i]);
    return 0;
}

