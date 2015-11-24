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
const int maxm=22;

int a[maxn+1],n,m,d;
int cnt[maxm];
bool f[1<<maxm];

int cbit(int v){
    int res=0;
    while(v){
        res+=v&1;
        v>>=1;   
    }   
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d%d",&n,&m,&d);
    REP(i,m){
        int s,v;
        scanf("%d",&s);
        REP(j,s){
            scanf("%d",&v);
            a[v]=i;
        }
    }
    reset(f,0);
    reset(cnt,0);
    FOR(i,1,d-1) cnt[a[i]]++;
    FOR(i,d,n){
        if(i>d) cnt[a[i-d]]--;
        cnt[a[i]]++;
        int mask=0;
        REP(j,m) if(cnt[j]==0) mask|=1<<j;
        f[mask]=1;  
    }
    REPD(b,1<<m) 
        if(!f[b])
            REP(i,m) 
                if(((b>>i)&1)==0 && f[b|(1<<i)]) f[b]=1;
    
    int res=oo;
    REP(i,1<<m) if(!f[i]) res=min(res,cbit(i));
    cout<<res<<endl;
    
    return 0;
}
