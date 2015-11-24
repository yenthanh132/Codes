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

ll res1,res2,n,p,M;

ll pos(ll v){
    v++;
    int c=0;
    while(v){
        c++;
        v/=2;
    }
    c--;
    ll res=0;
    FORD(i,n,n-c+1) res+=1ll<<(i-1);
    return res+1;
}

ll pos2(ll v){
    v=M-v+1;
    int c=0;
    while(v){
        c++;
        v/=2;
    }
    c--;
    ll res=0;
    FORD(i,n-c,1) res+=1ll<<(i-1);
    return res+1;
}

#include <conio.h>
int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    FOR(tt,1,T){
        cin>>n>>p;
        M=1ll<<n; M--;
        ll left=0, right=M, mid,res1=0;
        while(left<=right){
            mid=(left+right)/2;
            if(pos(mid)<=p){
                res1=mid;
                left=mid+1;
            }else right=mid-1;
        }
        
        left=0; right=M; res2=0;
        while(left<=right){
            mid=(left+right)/2;
            if(pos2(mid)<=p){
                res2=mid;
                left=mid+1;
            }else right=mid-1;
        }
        printf("Case #%d: %lld %lld\n",tt,res1,res2);
    }
    //getch();
    return 0;
}
