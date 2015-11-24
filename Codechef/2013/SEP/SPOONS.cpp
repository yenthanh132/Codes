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

const int maxn=80;

bool isprime[maxn];
int cnt[maxn],m,list[maxn];
ll f[maxn];

void phantich(int n, int v){
    int t;
    for(int i=1; i<=m && list[i]<=n; ++i){
        t=n;
        while(t>=list[i]){
            cnt[i]+=(t/list[i])*v;
            t/=list[i];
        }
    }   
}

ll Cal(int n){
    if(f[n]!=-1) return f[n];
    FOR(i,1,m) cnt[i]=0;
    phantich(n,1); phantich(n/2,-1); phantich(n-n/2,-1);      
    ll res=1;
    FORD(i,m,1) 
        while(cnt[i]>0){
            if(res*list[i]>=oo){
                f[n]=oo;
                return oo;
            }
            res*=list[i];
            cnt[i]--;
        }
    f[n]=res;
    return res;
}

int main(){
    //Init
    isprime[2]=1;
    for(int i=3; i<=70; i+=2) isprime[i]=1;
    for(int i=3; i*i<=70; i+=2) if(isprime[i])
        for(int j=i*i; j<=70; j+=i*2) isprime[j]=0;
    list[m=1]=2;
    for(int i=3; i<=70; i+=2) if(isprime[i]) list[++m]=i;
    FOR(v,2,64) f[v]=-1; f[1]=1;
    //=====================
    //FOR(v,1,64) cout<<Cal(v)<<endl;
    int n;
    ll v;
    scanf("%d",&n);
    REP(tt,n){
        scanf("%lld",&v);
        int l=1,r=64,mid,res=64;
        while(l<=r){
            mid=(l+r)/2;
            if(Cal(mid)>=v){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        printf("%d\n",res);
    }
    
    
    return 0;
}
