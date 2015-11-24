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

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}

const int maxn=100007;

ll sR[maxn],sIR[maxn],pR[maxn];
ll sR2[maxn],sIR2[maxn],pR2[maxn];
ll p1,p2,R,MOD;
int n,q;

ll mul(ll a, ll b){
    if(b==0 || a==0) return 0;   
    if(b==1) return a;
    ll tmp=mul(a,b/2);
    tmp+=tmp;    
    if(b&1) tmp+=a;
    return tmp%MOD;
}

ll pow_mod(ll base, int n, ll vMOD){
    if(n==0) return 1;
    ll t=pow_mod(base,n/2,vMOD);
    t=(t*t)%vMOD;
    if(n&1) t=(t*base)%vMOD;
    return t;
}

//BIT for modify single value
ll BIT[maxn];

int BIT_inc(int p, ll v){
    v%=MOD;
    if(v<0) v+=MOD;
    for(int i=p; i<=n; i+=i&(-i)){
        BIT[i]+=v;
        if(BIT[i]>MOD) BIT[i]-=MOD;
    }  
}

ll BIT_get(int p){
    ll res=0;
    for(int i=p; i; i-=i&(-i)){
        res+=BIT[i];
        if(res>MOD) res-=MOD;
    }
    return res;
}

ll Get_Sum1(int l, int r){
   return (BIT_get(r)-BIT_get(l-1)+MOD)%MOD;   
}


//IT for modify a sequence of value
struct IT_node{
    ll s,d,v,s2,d2,v2; 
    bool update;
} IT[maxn*4];

void lazy_update(int i, int l, int r){
    if(!IT[i].update) return;
    IT[i].update=0;
    IT[i].v += IT[i].s*sR[r-l+1] + IT[i].d*sIR[r-l+1]; IT[i].v%=p1;
    IT[i].v2 += IT[i].s2*sR2[r-l+1] + IT[i].d2*sIR2[r-l+1]; IT[i].v2%=p2;
    if(l<r){
        //Update sub left        
        IT[i*2].s = (IT[i*2].s + IT[i].s)%p1;
        IT[i*2].d = (IT[i*2].d + IT[i].d)%p1;
        IT[i*2].s2 = (IT[i*2].s2 + IT[i].s2)%p2;
        IT[i*2].d2 = (IT[i*2].d2 + IT[i].d2)%p2;
        
        ll idx=(l+r)/2 - l + 1;
        //Update sub right        
        IT[i*2+1].s = (IT[i*2+1].s + pR[idx] * (IT[i].s + (idx * IT[i].d)%p1) )%p1;
        IT[i*2+1].d = (IT[i*2+1].d + pR[idx] * IT[i].d)%p1;
        IT[i*2+1].s2 = (IT[i*2+1].s2 + pR2[idx] * (IT[i].s2 + (idx * IT[i].d2)%p2) )%p2;
        IT[i*2+1].d2 = (IT[i*2+1].d2 + pR2[idx] * IT[i].d2)%p2;
        IT[i*2].update=1;
        IT[i*2+1].update=1;
    }
    IT[i].s = 0; IT[i].d = 0; IT[i].s2 = 0; IT[i].d2 = 0;
}

void IT_inc(int i, int l, int r, int s, int d, int x, int y){
    lazy_update(i,l,r);
    if(y<l || r<x) return;
    if(x<=l && r<=y){
        ll idx=l-x;
        IT[i].update = 1;
        IT[i].s = (pR[idx] * (s + (idx*d)%p1)) % p1;
        IT[i].d = (pR[idx] * d) % p1;
        IT[i].s2 = (pR2[idx] * (s + (idx*d)%p2)) % p2;
        IT[i].d2 = (pR2[idx] * d) % p2;
        lazy_update(i,l,r);
        return;
    }   
    int mid=(l+r)/2;
    IT_inc(i*2,l,mid,s,d,x,y);
    IT_inc(i*2+1,mid+1,r,s,d,x,y);
    IT[i].v = (IT[i*2].v + IT[i*2+1].v)%p1;
    IT[i].v2 = (IT[i*2].v2 + IT[i*2+1].v2)%p2;
}

ll IT_res, IT_res2;
void IT_get(int i, int l, int r, int x, int y){
    lazy_update(i,l,r);
    if(y<l || r<x) return;
    if(x<=l && r<=y){
        IT_res += IT[i].v;
        IT_res2 += IT[i].v2;
        return;
    }   
    int mid=(l+r)/2;
    IT_get(i*2,l,mid,x,y);
    IT_get(i*2+1,mid+1,r,x,y);
    IT[i].v = (IT[i*2].v + IT[i*2+1].v)%p1;
    IT[i].v2 = (IT[i*2].v2 + IT[i*2+1].v2)%p2;
}

void IT_init(int i, int l, int r){
    IT[i].s = 0; IT[i].d = 0; IT[i].s2 = 0; IT[i].d2 = 0;
    IT[i].v = 0; IT[i].v2 = 0;
    IT[i].update=0;
    if(l==r) return;
    int mid=(l+r)/2;
    IT_init(i*2,l,mid); IT_init(i*2+1,mid+1,r);   
}

ll Get_Sum2(int x, int y){
    IT_res=0; IT_res2=0;
    IT_get(1,1,n,x,y);
    IT_res%=p1; IT_res2%=p2;
    if(p1==p2) return IT_res;
    //Mod theorem
    ll res = mul(IT_res, mul(p2, pow_mod(p2, p1-2, p1))) 
           + mul(IT_res2, mul(p1, pow_mod(p1, p2-2, p2)));
    return res%MOD;
}

ll Get_Sum_Total(int x, int y){
    return (Get_Sum1(x,y) +Get_Sum2(x,y))%MOD;   
}

int main(){
    int test; 
     
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    read(test);
    REP(tt,test){
        int type,s,d,x,y;
        ll v1,v2;
        
        read(n); read(q); read(R); read(p1); read(p2);
        MOD=p1*p2;
        
        pR[0]=1; sR[0]=sIR[0]=0;
        pR2[0]=1; sR2[0]=sIR2[0]=0;
        FOR(i,1,n){
            pR[i]=(pR[i-1]*R)%p1;
            sR[i]=(sR[i-1]+pR[i-1])%p1;
            sIR[i]=(sIR[i-1]+pR[i-1]*(i-1))%p1;
            pR2[i]=(pR2[i-1]*R)%p2;
            sR2[i]=(sR2[i-1]+pR2[i-1])%p2;
            sIR2[i]=(sIR2[i-1]+pR2[i-1]*(i-1))%p2;
        }
        IT_init(1,1,n);
        FOR(i,1,n) BIT[i]=0;
        FOR(i,1,n){
            read(x);
            BIT_inc(i,x);
        }
                
        
        REP(t,q){
            read(type);
            if(type==0){
                read(s); read(d); read(x); read(y);
                IT_inc(1,1,n,s,d,x,y);   
            }else if(type==1){
                read(x); read(s);
                v1=Get_Sum_Total(x,x);
                if(v1==0) v2=0; else v2=pow_mod(v1%p2,s,p2);
                BIT_inc(x,v2-v1);           
            }else{ //type==2;
                read(x); read(y); //Get_Sum3(x,y);
                printf("%lld\n",Get_Sum_Total(x,y)%p1);
            }        
        }
    }
    
    return 0;
}
    
    
