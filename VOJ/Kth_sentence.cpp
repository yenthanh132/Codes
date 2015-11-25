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

const int maxn = 101;
const int maxm = 2001;
const int base = 73471;

int n,m,len[maxn];
ll k,dp[maxm],f[maxm],cnt[30];
char str[maxn][201],res[maxm];

ll cong(ll a, ll b){
    if(a+b>oo) return oo; else return a+b;
}

ll nhan(ll a, ll b){
    if(b==0) return 0;
    if(a*b/b!=a || a*b>oo) return oo; else return a*b;
}

void build(){
    char ch,old;
    ll hashpw,h1,h2,v1,v2;
    int rest;
    reset(f,0); f[0]=1;
    FOR(p,1,m){
        reset(cnt,0);
        REP(i,n){
            h1=h2=0;
            old=0;
            hashpw=1;
            res[p]=0;
            REP(j,min(len[i],p)){
                rest=m-(p-j-1+len[i]);
                
                h1=h1*base+str[i][j];
                h2=h2+str[i][j]-old+hashpw*res[p-j];
                hashpw*=base;
                old=str[i][j];
                
                if(h1==h2 && rest>=0){
                    v1=f[p-j-1];
                    v2=dp[rest];
                    cnt[str[i][j]-'a']=cong(cnt[str[i][j]-'a'],nhan(v1,v2));
                }
            }
        }
    
        REP(i,26)
            if(cnt[i]<k) k-=cnt[i];
            else{
                res[p]=i+'a';
                break;
            }
        
        REP(i,n) if(len[i]<=p){
            h1=h2=0;
            hashpw=1;
            REP(j,len[i]){
                h1=h1*base+str[i][j];
                h2=h2+hashpw*res[p-j];
                hashpw*=base;
            }
            if(h1==h2) f[p]=cong(f[p],f[p-len[i]]);
        }
            
    }
}
         
#include <conio.h>
int main(){
    freopen("test.txt","r",stdin);
    scanf("%d%d%lld\n",&n,&m,&k);
    REP(i,n){
        gets(str[i]);
        len[i]=strlen(str[i]);
    }
    dp[0]=1;
    FOR(i,1,m) REP(j,n) if(i>=len[j]) dp[i]=cong(dp[i],dp[i-len[j]]);
    if(dp[m]<k) puts("-");
    else{
        build();
        FOR(p,1,m) putchar(res[p]); puts("");
    }
    getch();
    return 0;
}
