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
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 100000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii,int> iii;
typedef pair<ll,int> plli;

#define maxn 100007

ll k;
int n,a[maxn],pos[maxn],BIT[maxn];
plli ds[maxn];

void update(int i){
    i++;
    while(i<=n+1){
        BIT[i]++;
        i += i & (-i);
    }
}

int get(int i){
    i++;
    int res=0;
    while(i){
        res+=BIT[i];
        i&=i-1;
    }
    return res;
}

bool check(ll v){
    ll count=0;
    int i,j,l,r,mid;
    reset(BIT,0);
    update(pos[0]);
    for(i=1;i<=n;i++){
        j=-1; l=0; r=n;
        while(l<=r){
            mid=(l+r)/2;
            if(ds[pos[i]].fi-ds[mid].fi>v) j=mid, l=mid+1; else r=mid-1;
        }
        if(j>=0){
            count+=get(j);
            if(count>=k) return false;
        }
        update(pos[i]);
    }
    return true;
}    

void solve(){
    ll res,left,right,mid;
    left=-oo; right=oo;
    while(left<=right){
        mid=(left+right)/2;
        if (check(mid)){
            res=mid;
            right=mid-1;
        }else left=mid+1;
    }
    printf("%I64d\n",res);
    
}
//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%I64d",&n,&k);
    ds[0].fi=0; ds[0].se=0;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        ds[i].fi=ds[i-1].fi+a[i];
        ds[i].se=i;
    }
    sort(ds,ds+n+1);
    for(int i=1;i<=n;i++) pos[ds[i].se]=i;
    solve();
    //getch();
    
    return 0;
}
