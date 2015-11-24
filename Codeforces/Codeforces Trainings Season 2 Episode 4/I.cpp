#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=300007;

int n,k,x[maxn],y[maxn],f[maxn],pos[maxn];
vector<pii> hor[maxn],ver[maxn],bit_hor[maxn],bit_ver[maxn];
int dp[maxn],trace[maxn];
vector<int> ds;

int find_pos(vector <pii> &arr, int v){
    int l=0, r=sz(arr), mid;
    while(l<=r){
        mid=(l+r)/2;
        if(arr[mid].first==v) return mid;
        else if(arr[mid].first<v) l=mid+1; else r=mid-1;
    }
    return -1;
}

bool cmp(const int &i, const int &j){
    return x[i]<x[j] || (x[i]==x[j] && y[i]<y[j]);
}

void update(vector<pii> &bit, int i, pii v){
    ++i;
    for(; i<=sz(bit); i+=i&(-i)){
        bit[i-1]=max(bit[i-1],v);
    }
}

pii get(vector<pii> &bit, int i){
    ++i;
    pii res = pii(-1,-1);
    for(; i>0; i-=i&(-i)){
        res=max(res,bit[i-1]);
    }
    return res;
}


int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i){
        scanf("%d%d%d",&x[i],&y[i],&f[i]);
        f[i]-=k;
        hor[x[i]].pb(pii(y[i],i));
        ver[y[i]].pb(pii(x[i],i));
        pos[i]=i;
    }
    for(int i=0; i<=100000; ++i){
        sort(hor[i].begin(),hor[i].end());
        sort(ver[i].begin(),ver[i].end());
        bit_hor[i].resize(sz(hor[i]));
        bit_ver[i].resize(sz(ver[i]));
        for(int j=0; j<sz(bit_hor[i]); ++j) bit_hor[i][j]=pii(-1,-1);
        for(int j=0; j<sz(bit_ver[i]); ++j) bit_ver[i][j]=pii(-1,-1);
    }
    sort(pos+1,pos+n+1,cmp);
    for(int i=1; i<=n; ++i) dp[i]=-oo;
    dp[1]=f[1];

    for(int i=1; i<=n; ++i){
        int id=pos[i];
        int X=x[id], Y=y[id];
        int ix = find_pos(ver[Y],X), jy = find_pos(hor[X],Y);
        if(id==1){ //plant 1
            update(bit_ver[Y], ix, pii(dp[1],1));
            update(bit_hor[X], jy, pii(dp[1],1));
        }else{
            pii t;
            t=get(bit_ver[Y],ix);
            if(t.first>=0 && dp[id]<t.first+f[id]){
                dp[id]=t.first+f[id];
                trace[id]=t.second;
            }
            t=get(bit_hor[X],jy);
            if(t.first>=0 && dp[id]<t.first+f[id]){
                dp[id]=t.first+f[id];
                trace[id]=t.second;
            }
            if(dp[id]>=0){
                update(bit_ver[Y],ix,pii(dp[id],id));
                update(bit_hor[X],jy,pii(dp[id],id));
            }
        }
    }

    printf("%d\n",dp[n]+k);
    int u=n;
    while(u!=1){
        ds.pb(u);
        u=trace[u];
    }
    ds.pb(1);
    printf("%d\n",sz(ds));
    for(int i=sz(ds)-1; i>=0; --i) printf("%d %d\n",x[ds[i]],y[ds[i]]);

}

