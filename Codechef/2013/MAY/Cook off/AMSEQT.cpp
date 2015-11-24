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
#define oo 1000000009

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

//fast input
template<typename T>
void read(T& x){
    register int c;
    static bool isNega;
    isNega=false;
    while(!((x=getchar())>='-' && x<='9'));
    if(x=='-') isNega=true, x=0; else x-='0';
    while(((c=getchar())>='-' && c<='9')) x=10*x+(c-'0');
    if(isNega) x=-x;
}


const int maxn=200007;
const int maxv=200000;
const int maxm=20;

int T,n,m,D,a[maxn],dp[maxn],IT[2][maxn*4];

void update(int t, int i, int l, int r, int p, int v){
    if(p<l || p>r) return;
    if(l==r){
        IT[t][i]=(IT[t][i]+v)%oo;
        return;
    }
    int mid=(l+r)/2;
    update(t,i*2,l,mid,p,v); update(t,i*2+1,mid+1,r,p,v);
    IT[t][i]=(IT[t][i*2]+IT[t][i*2+1])%oo;
}

int get(int t, int i, int l, int r, int s, int f){
    if(s>f) return 0;
    if(f<l || s>r) return 0;
    if(s<=l && r<=f){
        return IT[t][i];
    }
    int mid=(l+r)/2;
    return (get(t,i*2,l,mid,s,f)+get(t,i*2+1,mid+1,r,s,f))%oo;
}

//#include <conio.h>

int main(){
    int x;
    ll sum;
    
    //freopen("test.txt","r",stdin);
    read(T);
    REP(tt,T){
        read(n); read(m);
        
        FOR(i,1,n) read(a[i]);
        D=1<<m;
        dp[0]=1; 
        reset(IT,0);
        sum=0;
        update(0,1,0,D,0,1);
        FOR(i,1,n){
            dp[i]=0;
            sum+=a[i];
            x=0;
            REP(i,m-1) if((sum>>i)&1) x|=(1<<i);
            if((sum>>(m-1))&1){
                dp[i]=(get(1,1,0,D,0,x) + get(0,1,0,D,x+1,D))%oo;
                update(1,1,0,D,x,dp[i]);
            }else{
                dp[i]=(get(0,1,0,D,0,x) + get(1,1,0,D,x+1,D))%oo;
                update(0,1,0,D,x,dp[i]);
            }                            
        }
        cout<<dp[n]<<endl;
    }
    //getch();
    return 0;
}
