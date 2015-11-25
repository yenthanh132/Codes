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

const int maxn=107;

int n,k[maxn],dp[maxn][64];
ll cnt[maxn][64];

int cntbit(int v){
    int c=0;
    while(v){
        c+=v%2;
        v/=2;
    }
    return c;
}

void update(int &v, ll &c, int vnew, ll cnew){
    if(v<vnew){
        v=vnew;
        c=cnew;
    }else if(v==vnew) c+=cnew;
}

int getbit(int v, int pos){
    return (v>>(pos-1))&1;
}

bool ok(int id, int id2){
    if(getbit(id,1))
        if(getbit(id2,2) || getbit(id2,6)) return 0;
    if(getbit(id,2))
        if(getbit(id2,1) || getbit(id2,3)) return 0;
    if(getbit(id,3)) 
        if(getbit(id2,2) || getbit(id2,4)) return 0;
    return 1;
}

//#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&k[i]);
    
    if(n==1){
        if(k[1]) puts("2 1");
        else puts("3 1");
        return 0;
    }
    
    REP(id,64)
        if( (!k[1] || !getbit(id,k[1]))
        && (!k[2] || !getbit(id,k[2]+3))){
            int id2=id;
            FOR(k,3,5) if((id2>>k)&1) id2-=1<<k;
            id2<<=3;
            if(!ok(id>>3,id2)) continue;
            dp[2][id]=cntbit(id);
            cnt[2][id]=1;
        }
        
    int bit;
    FOR(i,3,n)
        REP(id,8)
            REP(id2,64) 
                if(ok(id,id2) && (!k[i] || !getbit(id,k[i]))){
                    bit=id*8+(id2>>3);
                    update(dp[i][bit],cnt[i][bit],dp[i-1][id2]+cntbit(id),cnt[i-1][id2]);
                }
    
    int M=0;
    ll L;
    REP(id,64) M=max(M,dp[n][id]);
    L=0;
    REP(id,64) if(M==dp[n][id]) L+=cnt[n][id];
    
    cout<<M<<' '<<L<<endl;

    //getch();
    return 0;
}
    
    
