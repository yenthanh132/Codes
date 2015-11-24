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

int n,x,y;
ll c;

ll sqr(ll v){return v*v;}
ll cal2(ll v){return v*(v+1)/2;}

ll cal(ll t){
    ll res=2*t*t+2*t+1;
    t++;
    res-=sqr(max(0ll,t-x));
    res-=sqr(max(0ll,t-(n-x+1)));
    res-=sqr(max(0ll,t-y));
    res-=sqr(max(0ll,t-(n-y+1)));
    ll len=t-(n-y+1);
    if(len>0){
        res+=cal2(max(0ll,len-x));
        res+=cal2(max(0ll,len-(n-x+1)));
    }
    len=t-y;
    if(len>0){
        res+=cal2(max(0ll,len-x));
        res+=cal2(max(0ll,len-(n-x+1)));
    }
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>x>>y>>c;
    //cout<<cal(8035148056ll)<<endl;
    //cout<<cal(1999999997)<<endl;
    ll l=0, r=2000000000ll, mid, res=oo;
    while(l<=r){
        mid=(l+r)/2;
        if(cal(mid)>=c){
            res=mid;
            r=mid-1;
        }else l=mid+1;
    }
    cout<<res<<endl;
    return 0;
}
        
