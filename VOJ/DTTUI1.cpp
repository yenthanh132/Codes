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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;

int n,n1,n2,w,c,sw[21],sv[21];
ll res;
pii ds[1048577],list1[21],list2[21];

void duyet1(int i){
    if(i>n1){
        ds[c++]=pii(sw[n1],sv[n1]);
        return;
    }
    sw[i]=sw[i-1]; sv[i]=sv[i-1]; duyet1(i+1);
    sw[i]=sw[i-1]+list1[i-1].fi; sv[i]=sv[i-1]+list1[i-1].se;
    if(sw[i]<=w) duyet1(i+1);
}

bool mycmp(const pii &a, const pii &b){
    return(a.fi<b.fi || (a.fi==b.fi && a.se>b.se));
}

void init(){
    sw[0]=sv[0]=c=0;
    duyet1(1);
    sort(ds, ds+c, mycmp);
    int t=-1;
    REP(i,c){
        t=max(t,ds[i].se);
        ds[i].se=t;
    }
}

ll findv(int w){
    int l=0, r=c-1, mid, res=0;
    while(l<=r){
        mid=(l+r)/2;
        if(ds[mid].fi<=w){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return ds[res].se;
}

void duyet2(int i){
    if(i>n2){
        res=max(res,sv[n2]+findv(w-sw[n2]));
        return;
    }
    sw[i]=sw[i-1]; sv[i]=sv[i-1]; duyet2(i+1);
    sw[i]=sw[i-1]+list2[i-1].fi; sv[i]=sv[i-1]+list2[i-1].se;
    if(sw[i]<=w) duyet2(i+1);
}

void solve(){
    res=0;
    duyet2(1);    
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    int u,v,t1,t2;
    scanf("%d%d",&n,&w);
    n1=(n+1)/2; n2=n-n1;
    t1=t2=0;
    REP(i,n){
        scanf("%d%d",&u,&v);
        if(i<n1) list1[t1++]=pii(u,v); else list2[t2++]=pii(u,v);
    }
    init();
    solve();
    printf("%lld\n",res);
    //getch();
    return 0;
}

