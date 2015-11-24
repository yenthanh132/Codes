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

const int maxn=300007;

int n,k,pos;
pii x[maxn];
queue<int> myq;
ll res;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&x[i].fi);
        x[i].se=i;
    }
    scanf("%d",&k);
    sort(x+1,x+n+1);
    
    ll val=0, sum=0;
    res=oo;
    pos=-1;
    FOR(i,1,n){
        val += 1ll * x[i].fi * sz(myq) - sum;
        myq.push(x[i].fi); sum+=x[i].fi;
        while(sz(myq)>k){
            int v=myq.front(); myq.pop(); sum-=v;
            val -= sum - 1ll * v * sz(myq);
        }
        if(sz(myq)==k && (i==k|| val<res)){
            res=val;
            pos=i;   
        }        
    }   
    //cout<<pos<<' '<<res<<endl;
    FOR(i,pos-k+1,pos) printf("%d ",x[i].se);
}
