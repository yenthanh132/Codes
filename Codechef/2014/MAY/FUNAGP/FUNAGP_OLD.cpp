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

ll sR[maxn],sIR[maxn],pR[maxn];
ll p1,p2,R,MOD;
int n,q;

inline void Mod(ll &v){
    v=v%MOD;  
}

ll mul(ll a, ll b){
    if(b==0 || a==0) return 0;   
    if(b==1) return a;
    ll tmp=mul(a,b/2);
    tmp+=tmp;    
    if(b&1) tmp+=a;
    Mod(tmp);
    return tmp;
}

ll pow_mod(ll base, int n){
    if(n==1) return base;
    ll t=pow_mod(base,n/2);
    t=t*t%p2;
    if(n&1) t=t*base%p2;
    return t;
}

//BIT for modify single value
ll BIT[maxn];

int BIT_inc(int p, ll v){
    if(v<0) v+=MOD;
    for(int i=p; i<=n; i+=i&(-i)){
        BIT[i]+=v;
        Mod(BIT[i]);
    }
}

ll BIT_get(int p){
    ll res=0;
    for(int i=p; i; i-=i&(-i)){
        res+=BIT[i];
        Mod(res);
    }
    return res;
}

ll Get_Sum1(int l, int r){
   return (BIT_get(r)-BIT_get(l-1)+MOD)%MOD;   
}


//IT for modify a sequence of value
struct IT_node{
    ll s,d,v; 
} IT[maxn*4];

void lazy_update(int i, int l, int r){
    if(!IT[i].s && !IT[i].d) return;

    IT[i].v += mul(IT[i].s,sR[r-l+1]) + mul(IT[i].d,sIR[r-l+1]); Mod(IT[i].v);
    if(l<r){
        //Update sub left
        IT[i*2].s += IT[i].s; Mod(IT[i*2].s);
        IT[i*2].d += IT[i].d; Mod(IT[i*2].d);
        int idx=(l+r)/2 - l + 1;
        //Update sub right
        IT[i*2+1].s += mul(pR[idx], IT[i].s + mul(idx,IT[i].d)); Mod(IT[i*2+1].s);
        IT[i*2+1].d += mul(pR[idx], IT[i].d); Mod(IT[i*2+1].s);
    }
    IT[i].s = 0; IT[i].d = 0;
}

void IT_inc(int i, int l, int r, int s, int d, int x, int y){
    lazy_update(i,l,r);
    if(y<l || r<x) return;
    if(x<=l && r<=y){
        int idx=l-x;
        IT[i].s = mul(pR[idx], s + mul(idx,d));
        IT[i].d = mul(pR[idx], d);
        lazy_update(i,l,r);
        return;
    }   
    int mid=(l+r)/2;
    IT_inc(i*2,l,mid,s,d,x,y);
    IT_inc(i*2+1,mid+1,r,s,d,x,y);
    IT[i].v = IT[i*2].v + IT[i*2+1].v; Mod(IT[i].v);
}

ll IT_res;
void IT_get(int i, int l, int r, int x, int y){
    lazy_update(i,l,r);
    if(y<l || r<x) return;
    if(x<=l && r<=y){
        IT_res = (IT_res + IT[i].v)%MOD;
        return;   
    }   
    int mid=(l+r)/2;
    IT_get(i*2,l,mid,x,y);
    IT_get(i*2+1,mid+1,r,x,y);
    IT[i].v = IT[i*2].v + IT[i*2+1].v; Mod(IT[i].v);    
}

ll Get_Sum2(int x, int y){
    IT_res=0;
    IT_get(1,1,n,x,y);
    return (IT_res+MOD)%MOD;
}

ll Get_Sum_Total(int x, int y){
    ll res=Get_Sum1(x,y) + Get_Sum2(x,y); Mod(res);
    return res;   
}

int main(){
    int test;
    freopen("input.txt","r",stdin);
    freopen("output2.txt","w",stdout);
    scanf("%d",&test);
    REP(tt,test){
        scanf("%d%d%I64d%I64d%I64d",&n,&q,&R,&p1,&p2);
        MOD=p1*p2;
        
        pR[0]=1;
        sR[0]=sIR[0]=0;
        FOR(i,1,n){
            pR[i]=mul(pR[i-1],R);
            sR[i]=sR[i-1]+pR[i-1]; Mod(sR[i]);
            sIR[i]=sIR[i-1]+mul(pR[i-1],i-1); Mod(sIR[i]);
        }
        reset(IT,0);
        reset(BIT,0);
        FOR(i,1,n){
            int v;
            scanf("%d",&v);
            BIT_inc(i,v);
        }
        
        int type,s,d,x,y;
        ll v1,v2;
        REP(t,q){
            scanf("%d",&type);
            if(type==0){
                scanf("%d%d%d%d",&s,&d,&x,&y);
                IT_inc(1,1,n,s,d,x,y);   
            }else if(type==1){
                scanf("%d%d",&x,&s);
                v1=Get_Sum_Total(x,x);
                v2=pow_mod(v1%p2,s);
                BIT_inc(x,v2-v1);           
            }else{ //type==2;
                scanf("%d%d",&x,&y);
                printf("%I64d\n",Get_Sum_Total(x,y)%p1);
            }        
        }
    }
    return 0;
}
    
    
