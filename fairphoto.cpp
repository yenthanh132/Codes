#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;
const int base=73471;

int n,k,pos[10],sum[10];
pii a[maxn];
int rmask[maxn][10];
int S[maxn][10];
map<ll,int> mpos;

ll fhash(int *sum, int mask){
    ll res = mask;
    int old=-1,cur;
    for(int v=0; v<8; ++v) if(mask>>v&1){
        cur=sum[v+1];
        if(old!=-1) res=res*base+cur-old;
        old = cur;
    }
    return res;
}

bool foundDiff(int mask, int l, int r){
    for(int j=1; j<=8; ++j)
        if(!(mask>>(j-1)&1) && S[r][j]-S[l-1][j]>0)
            return 1;
    return 0;
}

int main(){
//    freopen("7.in","r",stdin);
    freopen("fairphoto.in","r",stdin);
    freopen("fairphoto.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=8; ++j) S[i][j]=S[i-1][j];
        S[i][a[i].second]++;
    }
    for(int v=1; v<=8; ++v) pos[v]=oo;
    pii ds[10];
    for(int i=n; i>=1; --i){
        pos[a[i].second]=i;
        for(int v=1; v<=8; ++v) ds[v]=pii(pos[v],v);
        sort(ds+1,ds+9);
        for(int j=1, mask=0; j<=8; ++j){
            mask |= 1<<(ds[j].second-1);
            rmask[i][j]=mask;
        }
    }
    for(int v=1; v<=8; ++v) pos[v]=-oo;
    reset(sum,0);
    int res = -1;
    for(int i=0; i<=n; ++i){
        if(i>=1){
            pos[a[i].second]=i;
            sum[a[i].second]++;
        }
        if(i<n){
            for(int j=k; j<=8; ++j){
                int mask=rmask[i+1][j];
                ll x=fhash(sum,mask);
                if(mpos.count(x)==0) mpos[x]=i+1;
                else{
                    int p=mpos[x];
                    if(foundDiff(mask,p,i)) mpos[x]=i+1;
                }
            }
        }
        if(i==0) continue;

        for(int v=1; v<=8; ++v) ds[v]=pii(pos[v],v);
        sort(ds+1,ds+9,greater<pii>());
        for(int j=1, mask=0; j<=8; ++j){
            mask |= 1<<(ds[j].second-1);
            ll x=fhash(sum,mask);
            if(j>=k && mpos.count(x)){
                int p=mpos[x];
                if(!foundDiff(mask,p,i))
                    res = max(res,a[i].first-a[mpos[x]].first);
            }
        }
    }

    printf("%d\n",res);
    return 0;
}

