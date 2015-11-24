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
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=4000007;

struct ITNode{
    ll s,t;
};

struct ITTree{
    ITNode IT[maxn*4];
    int len;

    ITTree(){}

    void lazy_update(int i, int l, int r){
        if(!IT[i].t) return;
        IT[i].s+=1LL*IT[i].t*(r-l+1);
        if(l<r) IT[i*2].t+=IT[i].t, IT[i*2+1].t+=IT[i].t;
        IT[i].t=0;
    }

    void ITupdate(int i, int l, int r, int s, int f, ll v){
        lazy_update(i,l,r);
        if(f<l || r<s) return;
        if(s<=l && r<=f){
            IT[i].t=v;
            lazy_update(i,l,r);
            return;
        }
        int mid=(l+r)>>1;
        ITupdate(i*2,l,mid,s,f,v); ITupdate(i*2+1,mid+1,r,s,f,v);
        IT[i].s=IT[i*2].s+IT[i*2+1].s;
    }

    ll ITRes;

    void ITget(int i, int l, int r, int s, int f){
        lazy_update(i,l,r);
        if(f<l || r<s) return;
        if(s<=l && r<=f){
            ITRes+=IT[i].s;
            return;
        }
        int mid=(l+r)>>1;
        ITget(i*2,l,mid,s,f); ITget(i*2+1,mid+1,r,s,f);
        IT[i].s=IT[i*2].s+IT[i*2+1].s;
    }

    void update(int s, int f, int v){
        ITupdate(1,1,len,s,f,v);
    }

    ll get(int s, int f){
        ITRes=0;
        ITget(1,1,len,s,f);
        return ITRes;
    }
} ITx, ITy;

int m,n,w;

int main(){
    //freopen("input.txt","r",stdin);
    ll total=0;
    int k,x1,y1,x2,y2,v;

    scanf("%d%d%d",&m,&n,&w);
    ITx.len=m; ITy.len=n;
    REP(i,w){
        scanf("%d%d%d%d%d",&k,&x1,&y1,&x2,&y2);
        if(k==0){
            scanf("%d",&v);
            int w=y2-y1+1;
            int h=x2-x1+1;
            total+=1ll*w*h*v;
            ITx.update(x1,x2,1ll*v*w);
            ITy.update(y1,y2,1ll*v*h);
        }else{
            ll rx=ITx.get(x1,x2);
            ll ry=ITy.get(y1,y2);
            printf("%I64d\n",rx+ry-total);
        }
    }

    return 0;
}

