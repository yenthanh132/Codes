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

int a[maxn][maxn],b[maxn][maxn],s[maxn][maxn],dp[maxn][1<<10],lx[maxn],ly[maxn];
int m,n,k,res,cx,cy;

int get(int x1, int y1, int x2, int y2){
    return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];   
}

int cal(int mask, int j){
    int res=0;
    REP(i,m) if(((mask>>i)&1)!=a[i+1][j]) ++res;
    return res;
}

int cal(int x1, int y1, int x2, int y2, int bit){
    int s=(x2-x1+1)*(y2-y1+1);
    int v=get(x1,y1,x2,y2);
    if(bit==0) return v;
    else return s-v;   
}

int cal_pattern(int bit){
    int x0=1,y0;
    int kt=0;
    FOR(i,1,cx){
        int bit1=bit;
        y0=1;
        FOR(j,1,cy){
            kt+=cal(x0,y0,x0+lx[i]-1,y0+ly[j]-1,bit1);
            if(kt>k) return oo;
            bit1^=1;
            y0+=ly[j];
        }
        x0+=lx[i];
        bit^=1;
    }
    return kt;
}

int solve(int x, int y){
    int i,j;
    
    cx=cy=0;
    i=1;
    while(i<=n){
        j=i;
        while(j<n && a[x][j+1]==a[x][i]) ++j;
        ly[++cy]=j-i+1;
        i=j+1;   
    }
    i=1;
    while(i<=m){
        j=i;
        while(j<m && a[j+1][y]==a[i][y]) ++j;
        lx[++cx]=j-i+1;
        i=j+1;
    }
    int ans=oo;
    REP(i,2) ans=min(ans,cal_pattern(i));
    return ans;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    FOR(i,1,m) FOR(j,1,n){
        scanf("%d",&a[i][j]);   
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];    
    }
    
    if(m<=10 || n<=10){
        if(m>n){
            FOR(i,1,m) FOR(j,1,n) b[j][i]=a[i][j];
            swap(m,n);   
            FOR(i,1,m) FOR(j,1,n){
                a[i][j]=b[i][j];
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];   
            }
            
        }   
        REP(mask,1<<m) if(cal(mask,1)<=k) dp[1][mask]=cal(mask,1); else dp[1][mask]=oo;
        FOR(j,2,n){
            REP(mask,1<<m) dp[j][mask]=oo;
            REP(mask,1<<m){
                if(dp[j-1][mask]<oo){
                    dp[j][mask]=min(dp[j][mask],dp[j-1][mask]+cal(mask,j));
                    if(dp[j][mask]>k) dp[j][mask]=oo;
                    int mask2=(1<<m)-1 - mask;
                    dp[j][mask2]=min(dp[j][mask2],dp[j-1][mask]+cal(mask2,j));                                         
                    if(dp[j][mask2]>k) dp[j][mask2]=oo;
                }   
            }
        }
        
        res=oo;
        REP(mask,1<<m) res=min(res,dp[n][mask]);
    }else{
        res=oo;
        FOR(i,1,m) FOR(j,1,n){
            res=min(res,solve(i,j));
            //cout<<i<<' '<<j<<' '<<solve(i,j)<<endl;
        }
    }
    if(res<=k) cout<<res<<endl; else cout<<-1<<endl;  
    return 0;
}
