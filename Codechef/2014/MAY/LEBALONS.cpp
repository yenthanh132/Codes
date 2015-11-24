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

const int maxn=41;

ll f[maxn][maxn],pow2[maxn];
int n,m,cnt[maxn],k;
struct balloon{
    int c, p;   
}a[maxn];

bool cmp(const balloon &a, const balloon &b){
    return a.c<b.c;   
}

ll cal(int m){
    reset(f,0);
    f[0][0]=1;
    FOR(i,1,k) FOR(v,0,k){
        f[i][v]=f[i-1][v];
        if(v>0) f[i][v]+=f[i-1][v-1]*(pow2[cnt[i]]-1);
    }
    ll res=0;
    FOR(v,m,k) res+=f[k][v];
    return res;
}

ll phan_tich(int c){
    int x=1,y;
    k=0;
    ll mul2;
    while(x<=n){
        y=x;
        while(y<n && a[y+1].c==a[x].c) ++y;
        if(a[x].c==c) mul2=pow2[y-x];
        else cnt[++k]=y-x+1;
        x=y+1;
    }
    return mul2;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
            
    pow2[0]=1;
    FOR(i,1,40) pow2[i]=pow2[i-1]*2;
    int test;
    ll num,den,sum;
    cin>>test;   
    REP(tt,test){
        cin>>n>>m;   
        FOR(i,1,n) cin>>a[i].c>>a[i].p;
        sort(a+1,a+n+1,cmp);
        reset(f,0);    
        num=den=0;
        FOR(i,1,n){
            ll mul2=phan_tich(a[i].c);
            num+=a[i].p*cal(m-1)*mul2;
        }
        phan_tich(0);
        den=cal(m);
        printf("%0.9lf\n",double(num)/den);
    }
    
    return 0;
}
