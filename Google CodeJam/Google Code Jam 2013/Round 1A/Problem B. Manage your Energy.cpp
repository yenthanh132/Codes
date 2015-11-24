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

const int maxn=10007;
int r,e,n,a[maxn],next[maxn];
ll res;
stack<int> mys;

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    
    int T;
    scanf("%d",&T);
    FOR(tt,1,T){
        scanf("%d%d%d",&e,&r,&n);
        FOR(i,1,n) scanf("%d",&a[i]);
        res=0;
        if(e<=r){
            FOR(i,1,n) res+=1ll*a[i]*e;
        }else{
            reset(next,0);
            while(!mys.empty()) mys.pop();
            next[n]=oo;
            mys.push(n);
            FORD(i,n-1,1){
                while(!mys.empty() && a[i]>=a[mys.top()]) mys.pop();
                if(mys.empty()) next[i]=oo; else next[i]=mys.top();
                mys.push(i);
            }
            ll v=e; res=0;
            ll x,len,dec;
            FOR(i,1,n){
                if(i==n) res+=v*a[n];
                else{
                    x=next[i];
                    if(x==oo){
                        res+=v*a[i];
                        v=0;
                    }else{
                        len=x-i;
                        if(len*r+v>e){
                            dec=len*r+v-e;
                            if(dec>v) dec=v;
                            res+=dec*a[i];
                            v-=dec;   
                        }
                    }
                    v+=r;
                    if(v>e){
                        res+=(v-e)*a[i];
                        v=e;
                    }
                }
            }
        }
        printf("Case #%d: %lld\n",tt,res);
    }
    
    return 0;
}           
