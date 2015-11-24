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

const int maxn=100007;
const int maxv=100000;

int n,a[maxn],plist[maxn],cnt,pos[maxn];
bool isprime[maxn];

int find(int v){
    int l=1, r=cnt, mid, x=oo;
    while(l<=r){
        mid=(l+r)/2;
        if(plist[mid]<=v){
            x=plist[mid];
            l=mid+1;   
        }else r=mid-1;
    } 
    return x;
}

void doswap(int u, int v){
    int x=a[u], y=a[v];
    swap(pos[x],pos[y]);
    swap(a[u],a[v]);   
}

vector<pii> res;

int main(){
    
    isprime[2]=1; for(int i=3; i<=maxv; i+=2) isprime[i]=1;
    for(int i=3; i*i<=maxv; i+=2) if(isprime[i])
        for(int j=i*i; j<=maxv; j+=i*2) isprime[j]=0;
    plist[cnt=1]=1;
    for(int i=3; i<=maxv; i+=2) if(isprime[i])
        plist[++cnt]=i-1;
    
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]), pos[a[i]]=i;
 
    
    FOR(i,1,n)
        while(pos[i]!=i){
            int x=find(pos[i]-i);
            res.pb(pii(pos[i]-x,pos[i])); 
            doswap(pos[i]-x,pos[i]);
            
        }
    printf("%d\n",sz(res));
    REP(i,sz(res)) printf("%d %d\n",res[i].fi,res[i].se);
 
    return 0;   
}
