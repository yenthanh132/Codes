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


typedef long long ll;
typedef pair<int, int> pii;

const int maxn=300007;

int n,a[maxn],q,q1,q2;
ll gt[maxn],id,val[maxn],BIT[maxn],res,ans[maxn],ans2[maxn];

struct OriginQuery{
    int x, y;
}ds[maxn];

struct query{
    int x,v,i;
    query(){}
    query(int _x, int _v, int _i){
        x=_x; v=_v; i=_i;
    }
    bool operator<(const query &b)const{
        return x<b.x;
    }
} list1[maxn*2];

struct query2{
    int x,y,z,i;
    query2(){}
    query2(int _x, int _y, int _z, int _i){
        x=_x; y=_y; z=_z; i=_i;
    }
    bool operator<(const query2 &b) const{
        return x<b.x;
    }
} list2[maxn*2];

void update(int p, ll v){
    for(int i=p; i<=n; i+=i&(-i)) BIT[i]=(BIT[i]+v)%oo;
}

ll get(int p){
    ll res=0;
    for(int i=p; i; i-=i&(-i)) res=(res+BIT[i])%oo;
    return res;
}

int main(){
    read(n); read(q);
    gt[0]=1;
    FOR(i,1,n) gt[i]=(gt[i-1]*i)%oo;
    FOR(i,1,n) read(a[i]);
    q1=q2=0;
    int x,y;
    FOR(i,1,q){
        read(x); read(y);
        ds[i].x=x; ds[i].y=y;
        list1[++q1]=query(x,a[y],i);
        list1[++q1]=query(y,a[x],i);
        list2[++q2]=query2(x,min(a[x],a[y]),max(a[x],a[y]),-i);
        list2[++q2]=query2(y,min(a[x],a[y]),max(a[x],a[y]),i);
    }
    
    sort(list1+1,list1+q1+1);
    x=q1;
    id=1;
    FORD(i,n,1){
        val[i]=(get(a[i]-1)*gt[n-i])%oo;
        while(x>=1 && i<=list1[x].x){
            ans[list1[x].i]=(ans[list1[x].i]+get(list1[x].v-1)*gt[n-i])%oo;
            x--;
        }
        id=(id+val[i])%oo;
        update(a[i],1);
    }
    
    reset(BIT,0);
    sort(list2+1,list2+q2+1);
    x=1;
    query2 t;
    FOR(i,1,n){
        while(x<=q2 && list2[x].x<=i){
            t=list2[x];
            if(t.i>0){
                ans2[t.i]=(ans2[t.i]+get(t.z-1)-get(t.y)+oo)%oo;
            }else{
                ans2[-t.i]=(ans2[-t.i]-get(t.z-1)+get(t.y)+oo)%oo;
            }
            x++;
        }
        update(a[i],gt[n-i]);
    }
    
    FOR(i,1,q){
        x=ds[i].x; y=ds[i].y;
        res=(id-val[x]-val[y]+ans[i]+2*oo)%oo;
        if(a[x]<a[y])
            res=(res+gt[n-x]+ans2[i])%oo;
        else
            res=(res-ans2[i]+oo)%oo;
        printf("%lld\n",res);
    }
    
    return 0;
}
    
