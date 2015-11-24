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

const int maxv=1442250;
int T;
ll N;

ll cal2(ll n){
    return n*(n+1)*(2*n+1)/6;
}

ll cal(ll n){
    return n*(n+1)/2;   
}

int main(){
    freopen("army.in","r",stdin);
    //freopen("output.txt","w",stdout);   
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%I64d",&N);
        ll l,r,mid,pos=0;
        l=1; r=maxv;
        while(l<=r){
            mid=(l+r)/2;
            if(cal2(mid)>=N){
                pos=mid;
                r=mid-1;   
            }else l=mid+1;
        }
        
        ll res=(pos-1)*(pos-1);
        N-=cal2(pos-1);
        if(N>cal(pos)){
            N-=cal(pos);
            res+=pos; 
            pos--;
            l=1; r=pos; 
            ll pos2=0;
            while(l<=r){
                mid=(l+r)/2;
                if(cal(pos)-cal(pos-mid)>=N){
                    pos2=mid;
                    r=mid-1;   
                }else l=mid+1;
            }  
            res+=pos2;
        }else{
            l=1; r=pos; pos=0;
            while(l<=r){
                mid=(l+r)/2;
                if(cal(mid)>=N){
                    pos=mid;
                    r=mid-1;   
                }else l=mid+1;
            }
            res+=pos;
        }
        printf("Case %d: %I64d\n",tt,res);
    }
}
