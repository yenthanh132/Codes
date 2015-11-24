#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=307;

ll dp[maxn][maxn];
ll BIT[maxn][maxn], IT[maxn][maxn*4];
vector<pii> a[maxn];
int n,m,k;

void update(ll* arr, int p, ll v){
    p++;
    for(int i=p; i<=n+1; i+=i&(-i)) arr[i]=min(arr[i],v);
}

ll get(ll* arr, int p){
    ll res=oo;
    p++;
    for(int i=p; i; i-=i&(-i)) res=min(res,arr[i]);
    return res;
}

void updateIT(ll* arr, int i, int l, int r, int p, ll v){
    if(p<l || p>r) return;
    if(l==r){
        arr[i]=min(arr[i],v);
        return;
    }
    int mid=(l+r)/2;
    updateIT(arr,i*2,l,mid,p,v);
    updateIT(arr,i*2+1,mid+1,r,p,v);
    arr[i]=min(arr[i*2],arr[i*2+1]);
}

ll resIT;
void getIT(ll *arr, int i, int l, int r, int s, int f){
    if(f<l || s>r || l>r) return;
    if(s<=l && r<=f){
        resIT=min(resIT,arr[i]);
        return;
    }
    int mid=(l+r)/2;
    getIT(arr,i*2,l,mid,s,f);
    getIT(arr,i*2+1,mid+1,r,s,f);
}

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    int l,r,c,len;
    FOR(i,1,m){
        scanf("%d%d%d",&l,&r,&c);
        a[r].pb(pii(l,c));        
    }
    FOR(i,0,n) FOR(j,0,n){
        dp[i][j]=oo;
        BIT[i][j]=oo;
    }
    FOR(i,0,n) FOR(j,0,n*4) IT[i][j]=oo;
    dp[0][0]=0;
    update(BIT[0],0,0);
    updateIT(IT[0],1,0,n,0,0);
    FOR(r,1,n) FOR(v,0,min(r,n)){
        dp[r][v]=dp[r-1][v];
        REP(i,sz(a[r])){
            l=a[r][i].fi; c=a[r][i].se;
            len=r-l+1;
            if(len>v) continue;
            dp[r][v]=min(dp[r][v],get(BIT[v-len],l-1)+c);
            resIT=oo;
            getIT(IT[r-v],1,0,n,l,r-1);
            dp[r][v]=min(dp[r][v],resIT+c);
        }
        update(BIT[v],r,dp[r][v]);
        updateIT(IT[r-v],1,0,n,r,dp[r][v]);
    }
    ll res=oo;
    FOR(r,1,n) FOR(v,k,n) res=min(res,dp[r][v]);
    if(res==oo) res=-1;
    cout<<res<<endl;
    //getch();
    return 0;
}
