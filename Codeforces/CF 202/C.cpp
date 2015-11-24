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
vector<int> f[maxn],list[maxn],belong[maxn];
int n,m,q,mbig,big_arr[maxn],pos[maxn];
ll a[maxn],sum[maxn],add[maxn];

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&q);
    FOR(i,1,n) scanf("%I64d",&a[i]);
    int k,x;
    mbig=0;
    FOR(i,1,m){
        scanf("%d",&k);
        list[i].resize(k,0);
        sum[i]=0;
        if(k>300){
            big_arr[++mbig]=i;
            pos[i]=mbig;
        }
        REP(j,k){
            scanf("%d",&list[i][j]);
            sum[i]+=a[list[i][j]];
            if(k>300) belong[list[i][j]].pb(mbig);
        }
    }
    
    FOR(i,1,m){
        f[i].resize(mbig+1,0);
        REP(j,sz(list[i])){
            x=list[i][j];
            REP(k,sz(belong[x])) f[i][belong[x][k]]++;
        }
    }
    
    char buf[5];
    REP(tt,q){
        scanf("%s%d",buf,&k);
        if(buf[0]=='?'){
            ll res=0;
            FOR(j,1,mbig) res+=f[k][j]*add[j];
            if(sz(list[k])<=300){
                REP(j,sz(list[k])) res+=a[list[k][j]];       
            }else res+=sum[k];
            printf("%I64d\n",res);                
        }else{
            scanf("%d",&x);
            if(sz(list[k])>300) add[pos[k]]+=x;
            else{
                REP(i,sz(list[k])) a[list[k][i]]+=x;  
                FOR(i,1,mbig) sum[big_arr[i]]+=f[k][i]*x; 
            }
        }
    }
    
    //getch();
    return 0;
}
