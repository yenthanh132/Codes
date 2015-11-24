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

const ll hash_base=73471;

char a[20],a2[20],t[20];
ll v[20],hp[20];
int m,n,dp[1<<18];
int prev[20];

bool found(char *a, int lena, ll vhash, int len){
    v[0]=0;
    FOR(i,1,lena){
        v[i]=v[i-1]*hash_base+a[i];
        if(i>=len && vhash == v[i]-v[i-len]*hp[len]) return 1;
    }
    return 0;
}

void decode(int id, char *a, bool inver, bool bit1){
    FOR(i,1,n) if( ((id>>(i-1))&1) == bit1 ) a[i]=t[i]; else a[i]='0';
    if(inver) reverse(a+1,a+n+1);
}

int cal(int id){
    if(id==(1<<n)-1) return 0;
    if(dp[id]!=-1) return dp[id];
    char b[20],b2[20],str[20];
    ll v2[20];
    int &res=dp[id];
    res=oo;
    decode(id,str,0,0);
    decode(id,b,0,1);
    decode(id,b2,1,1);
    v2[0]=0; FOR(i,1,n) v2[i]=v2[i-1]*hash_base+str[i];
    ll vhash;
    FOR(i,1,n) if(str[i]!='0'){
        int u=n+1;
        FOR(j,i,n) if(str[j]=='0'){
            u=j;
            break;
        }
        
        FORD(j,u-1,i){
            vhash=v2[j]-v2[i-1]*hp[j-i+1];
            if(found(a,m,vhash,j-i+1) || found(a2,m,vhash,j-i+1) || found(b,n,vhash,j-i+1) || found(b2,n,vhash,j-i+1)){
                res=min(res,1+cal(id | ((1<<j) - (1<<(i-1)))) );
                break;
            }
        }
    }
    
    return res;
}

#include <conio.h>
int main(){
    hp[0]=1; FOR(i,1,19) hp[i]=hp[i-1]*hash_base;
    //freopen("test.txt","r",stdin);
    int T;
    scanf("%d",&T);
    REP(tt,T){
        scanf("%s",a+1); scanf("%s",t+1);
        m=strlen(a+1); n=strlen(t+1);
        FOR(i,1,m) a2[i]=a[m-i+1]; a2[m+1]='\0';
        REP(i,1<<n) dp[i]=-1;
        int res=cal(0);
        if(res!=oo) printf("%d\n",res);
        else puts("impossible");          
    }
    //getch();
    return 0;
}
