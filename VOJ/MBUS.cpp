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
typedef pair<pii, int> piii;
const int maxn = 100007;

int X,Y,n,m,listy[maxn];
piii a[maxn];
ll BIT[maxn];

int find(int v){
    int l=1, r=m, mid;
    while(l<=r){
        mid=(l+r)/2;
        if(listy[mid]==v) return mid;
        else if(listy[mid]>v) r=mid-1; else l=mid+1;
    }
}

void update(int x, ll v){
    while(x<=m){
        BIT[x]=max(BIT[x],v);
        x+=x&(-x);
    }
}

ll get(int x){
    ll res=0;
    while(x>0){
        res=max(res,BIT[x]);
        x&=x-1;
    }
    return res;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&X,&Y,&n);
    int nn=0;
    FOR(i,1,n){
        scanf("%d%d%d",&a[i].fi.fi,&a[i].fi.se,&a[i].se);
        if(a[i].fi.fi>=1 && a[i].fi.se>=1){
            nn++;
            a[nn]=a[i];
            listy[nn]=a[i].fi.se;
        }
    }
    n=nn;
    
    sort(listy+1,listy+n+1);
    m=1;
    FOR(i,2,n) if(listy[i]>listy[m]) listy[++m]=listy[i];
    FOR(i,1,n) a[i].fi.se=find(a[i].fi.se);
    sort(a+1,a+n+1);
    
    reset(BIT,0);
    ll v;
    FOR(i,1,n){
        v=get(a[i].fi.se);
        update(a[i].fi.se,v+a[i].se);
    }
    cout<<get(m)<<endl;
    //getch();
    return 0;
}
        
    
    
