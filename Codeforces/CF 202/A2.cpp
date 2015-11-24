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
#define oo 1000000000000000007ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int a[111111],n;

bool check(ll v){
    ll c=0;
    FOR(i,1,n){
        if(a[i]>v) return 0; else c+=v-a[i];
        if(c>v) c=v;
    }
    return c>=v;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    ll l=1, r=oo, mid,res;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<res<<endl;
}

