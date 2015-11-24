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

int n,m,a[20],pw8[10],pw2[10],c[11][11],d[11];
ll f[11],res;

void dfs(int i,int cnt){
    if(i==0){
        f[cnt]++;
        return;
    }
    int v=0;
    if(a[i]>7) v++;
    if(a[i]>4) v++;
    FOR(j,0,i-1){
        f[cnt+j] += c[i-1][j] * pw2[j] * pw8[i-1-j] * (a[i]-v);
        f[cnt+j+1] += c[i-1][j] * pw2[j] * pw8[i-1-j] * v;
    }
    if(a[i]==4 || a[i]==7) dfs(i-1,cnt+1); else dfs(i-1,cnt);
}
    
ll mypow(int v0, int n){
    if(n==0) return 1;
    ll t=mypow(v0,n/2);
    t=(t*t)%oo;
    if(n&1) return (t*v0)%oo; else return t;
}

int tohop(int n, int k){
    if(n<k) return 0;
    ll res=1;
    REP(j,k){
        res=(res*(n-j))%oo;
    }
    return res%oo;
}

int sum;

void update_res(){
    int cnt[11];
    reset(cnt,0);
    FOR(j,1,7) cnt[d[j]]++;
    ll ans=1;
    FOR(i,0,10){
        ans=(ans*tohop(f[i],cnt[i]))%oo;
        //cout<<tohop(f[i],cnt[i])<<endl;
    }
    res=(res+ans)%oo;
}

void duyet(int i){
    if(i>1 && sum>=d[1]) return;
    if(i==8){
        update_res();
        return;
    }
    if(i==1){
        FOR(j,1,10){
            d[i]=j;
            duyet(i+1);
        }
    }else{
        FOR(j,0,10){
            d[i]=j;
            sum+=j;
            duyet(i+1);
            sum-=j;
        }
    }
}
            

//#include <conio.h>
int main(){
    //freopen("input.txt","r",stdin);
    cin>>m;
    n=0;
    while(m){
        a[++n]=m%10;
        m/=10;
    }
    pw8[0]=1;
    FOR(i,1,9) pw8[i]=pw8[i-1]*8;
    pw2[0]=1;
    FOR(i,1,9) pw2[i]=pw2[i-1]*2;
    reset(c,0);
    c[0][0]=1;
    FOR(i,1,10){
        c[i][0]=1;
        FOR(j,1,10) c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    reset(f,0);
    dfs(n,0);
    
    f[0]--;
    res=0;
    
    sum=0;
    duyet(1);
    
    cout<<res<<endl;
    //getch();
    
    return 0;
}
