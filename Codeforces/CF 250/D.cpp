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

const int maxn=100007;

struct ITNode{
    int v,p;
    ll s;
}IT[maxn*4];

void ITUpdate(int i, int l, int r, int p, int v){
    if(p<l || p>r) return;
    if(l==r){
        IT[i].s=IT[i].v=v;
        IT[i].p=l;
        return;
    }
    int mid=(l+r)>>1;
    ITUpdate(i*2,l,mid,p,v); ITUpdate(i*2+1,mid+1,r,p,v);
    IT[i].s=IT[i*2].s+IT[i*2+1].s;
    if(IT[i*2].v>IT[i*2+1].v){
        IT[i].v=IT[i*2].v;
        IT[i].p=IT[i*2].p;
    }else{
        IT[i].v=IT[i*2+1].v;
        IT[i].p=IT[i*2+1].p;
    }
}

ll ITSum(int i, int l, int r, int s, int f){
    if(f<l || r<s) return 0;
    if(s<=l && r<=f) return IT[i].s;
    int mid=(l+r)>>1;
    return ITSum(i*2,l,mid,s,f) + ITSum(i*2+1,mid+1,r,s,f);
}

pii ITMax(int i, int l, int r, int s, int f){
    if(f<l || r<s) return pii(-1,-1);
    if(s<=l && r<=f) return pii(IT[i].v,IT[i].p);
    int mid=(l+r)>>1;
    return max(ITMax(i*2,l,mid,s,f), ITMax(i*2+1,mid+1,r,s,f));
}

int n,m;

int main(){
    //freopen("input.txt","r",stdin);
    reset(IT,0);
    scanf("%d%d",&n,&m);
    int v;
    FOR(i,1,n){
        scanf("%d",&v);
        ITUpdate(1,1,n,i,v);
    }

    int k,x,y;
    REP(i,m){
        scanf("%d",&k);
        if(k==1){
            scanf("%d%d",&x,&y);
            printf("%I64d\n",ITSum(1,1,n,x,y));
        }else if(k==2){
            scanf("%d%d%d",&x,&y,&v);
            while(1){
                pii t=ITMax(1,1,n,x,y);
                if(t.fi<v) break;
                ITUpdate(1,1,n,t.se,t.fi%v);
            }
        }else{
            scanf("%d%d",&x,&y);
            ITUpdate(1,1,n,x,y);
        }
    }

    return 0;
}
