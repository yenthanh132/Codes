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

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);   
}

struct fraction{
    ll a,b;
    fraction(){};
    fraction(ll x, ll y){
        ll d=gcd(x,y);
        a=x/d; b=y/d;
        if(a==0) b==1;
    }
    fraction operator+(fraction x){
        return fraction(a*x.b+b*x.a,b*x.b);
    }
    fraction operator-(fraction x){
        return fraction(a*x.b-b*x.a,b*x.b);
    }
    bool less1(){
        return a<b;   
    }
    bool operator<(const fraction &x) const{
        return a*x.b<b*x.a;   
    }
    bool operator==(const fraction &x) const{
        return a*x.b==b*x.a;   
    }
} list[100], val[100],ds[200007];

int n,d[100],cnt;

void duyet(int i){
    FOR(j,d[i-1]+1,n){
        val[i]=val[i-1]+list[j];
        if(val[i].less1()){
            d[i]=j;
            ds[++cnt]=val[i];
            duyet(i+1);  
        }
    } 
}

int main(){
    freopen("zanzibar.in","r",stdin);
    freopen("output.txt","w",stdout);
    n=0;
    
    FOR(x,1,12) FOR(y,x+1,13) if(gcd(x,y)==1) list[++n]=fraction(x,y);
    d[0]=0;
    val[0]=fraction(0,1);
    cnt=0;
    duyet(1); 
    sort(ds+1,ds+cnt+1);
    cnt=unique(ds+1,ds+cnt+1)-(ds+1);
    int T;
    ll x,y;
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%I64d%I64d",&x,&y);
        fraction f=fraction(x,y);
        int l=1, r=cnt, mid, pos=0;
        while(l<=r){
            mid=(l+r)/2;
            if(ds[mid]<f){
                pos=mid;
                l=mid+1;   
            }else r=mid-1;
        }
        bool first=1;
        fraction res(oo,1);
        if(pos>0){
            res=f-ds[pos];
            first=0;
        }
        if(pos<cnt){
            fraction t=ds[pos+1]-f;
            if(first || t<res) res=t;   
        }
        printf("Case %d: %I64d/%I64d\n",tt,res.a,res.b);
    }
    //cout<<ds[cnt-1].a<<' '<<ds[cnt-1].b<<endl;
    //cout<<ds[cnt].a<<' '<<ds[cnt].b;
    //cout<<1.0*clock()/CLOCKS_PER_SEC<<endl;
}
