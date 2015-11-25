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

int n,n1,n2,w,c1,c2,sw[21],sv[21];
ll res;
pii ds1[1048577],ds2[1048577],list1[21],list2[21];

void duyet1(int i){
    if(i>n1){
        ds1[c1++]=pii(sw[n1],sv[n1]);
        return;
    }
    sw[i]=sw[i-1]; sv[i]=sv[i-1]; duyet1(i+1);
    sw[i]=sw[i-1]+list1[i-1].fi; sv[i]=sv[i-1]+list1[i-1].se;
    if(sw[i]<=w) duyet1(i+1);
}

void duyet2(int i){
    if(i>n2){
        ds2[c2++]=pii(sw[n2],sv[n2]);
        return;
    }
    sw[i]=sw[i-1]; sv[i]=sv[i-1]; duyet2(i+1);
    sw[i]=sw[i-1]+list2[i-1].fi; sv[i]=sv[i-1]+list2[i-1].se;
    if(sw[i]<=w) duyet2(i+1);
}

void quicksort(pii ds[], int l, int r){
    if(l>=r) return;
    pii k=ds[rand()%(r-l+1)+l];
    int i=l, j=r;
    do{
        while(ds[i].fi<k.fi || (ds[i].fi==k.fi && ds[i].se>k.se))i++;
        while(ds[j].fi>k.fi || (ds[j].fi==k.fi && ds[j].se<k.se))j--;
        if(i<=j){
            if(i<j) swap(ds[i],ds[j]);
            i++; j--;
        }
    }while(i<=j);
    quicksort(ds,l,j); quicksort(ds,i,r);
}

void init(){
    sw[0]=sv[0]=c1=c2=0;
    duyet1(1);
    quicksort(ds1,0,c1-1);
    FOR(i,1,c1-1) ds1[i].se=max(ds1[i].se,ds1[i-1].se);
    duyet2(1);
    quicksort(ds2,0,c2-1);
    FOR(i,1,c2-1) ds2[i].se=max(ds2[i].se,ds2[i-1].se);
}

void solve(){
    res=0;
    int j=c2-1;
    REP(i,c1){
        while(ds1[i].fi+ds2[j].fi>w) j--;
        res=max(res,(ll)ds1[i].se+ds2[j].se);
    }
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
