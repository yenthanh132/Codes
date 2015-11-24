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

int n,x[222],y[222],dp[222][222],can[222][222];

ll val(int x1, int y1, int x2, int y2, int x3, int y3){
    ll vx=y2-y1, vy=x1-x2;
    return vx*(x1-x3)+vy*(y1-y3);
}

int sign(ll v){
    if(v>0) return 1;
    if(v==0) return 0;
    return -1;
}

bool online(int x1, int y1, int x2, int y2, int x3, int y3){
    ll v=val(x1,y1,x2,y2,x3,y3);
    return v==0 && min(x1,x2)<=x3 && x3<=max(x1,x2) && min(y1,y2)<=y3 && y3<=max(y1,y2);
}

bool cut(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    ll v1=val(x1,y1,x2,y2,x3,y3);
    ll v2=val(x1,y1,x2,y2,x4,y4);
    ll v3=val(x3,y3,x4,y4,x1,y1);
    ll v4=val(x3,y3,x4,y4,x2,y2);
    if(online(x1,y1,x2,y2,x3,y3) || online(x1,y1,x2,y2,x4,y4) || online(x3,y3,x4,y4,x1,y1) || online(x3,y3,x4,y4,x2,y2)) return 1;
    return (sign(v1)*sign(v2)<0 && sign(v3)*sign(v4)<0);
}

bool iscan(int i, int j){
    if((i+1)%n==j || (j+1)%n==i) return 1;
    if(can[i][j]!=-1) return can[i][j];
    REP(k,n) if(k!=i && k!=j && (k+1)%n!=i && (k+1)%n!=j)
        if(cut(x[i],y[i],x[j],y[j],x[k],y[k],x[(k+1)%n],y[(k+1)%n])){
            can[i][j]=can[j][i]=0;
            return 0;
        }
    REP(k,n) if(k!=i && k!=j && online(x[i],y[i],x[j],y[j],x[k],y[k])){
        can[i][j]=can[j][i]=0;
        return 0;
    }
    int xmid=(x[i]+x[j]), ymid=(y[i]+y[j]);
    int cnt=0;
    REP(k,n){
        int x1=x[k]*2, y1=y[k]*2;
        int x2=x[(k+1)%n]*2, y2=y[(k+1)%n]*2;
        if(y1>y2){
            swap(y1,y2);
            swap(x1,x2);
        }
        if(y1==y2 || y2<ymid || y1>=ymid) continue;
        double vx=y2-y1, vy=x1-x2;
        double X=x1+1.0*vy*(y1-ymid)/vx;
        if(X<xmid) ++cnt;
    }
    can[i][j]=can[j][i]=cnt&1;
    return can[i][j];
}

int f(int i, int j){
    if((j-i+n)%n<=1) return 1;
    if(!iscan(i,j)) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int &res=dp[i][j]; res=0;
    for(int k=(i+1)%n; k!=j; k=(k+1)%n)
        res=(res+1ll*f(i,k)*f(k,j))%oo;
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    REP(i,n) cin>>x[i]>>y[i];

    reset(can,-1);
    reset(dp,-1);
    cout<<f(0,n-1)<<endl;
    return 0;
}

