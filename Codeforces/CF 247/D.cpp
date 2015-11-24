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

int cnt,a[100];
ll dp[100][100][2];

ll get(int n, int k, bool smaller){
    if(n==0){
        if(k==0) return 1;
        else return 0;   
    }
    if(dp[n][k][smaller]!=-1) return dp[n][k][smaller];
    ll &res=dp[n][k][smaller];
    res=0;
    int top=a[n];
    if(smaller && k>0) top=1;
    FOR(b,0,top){
        res+=get(n-1,k-(b==1),smaller | (b<a[n]));   
    }   
    return res;
}

ll count(ll n, int k){
    cnt=0;
    while(n){
        a[++cnt]=n&1;
        n>>=1;   
    }
    reset(dp,-1);
    return get(cnt,k,0);   
}

ll cal(ll n, int k){
    return count(n*2,k)-count(n,k);
}

int cnt_bit(int n){
    int r=0;
    while(n){
        r+=n&1;
        n/=2;   
    }   
    return r;
}
int cnt_bit_n(int n, int k){
    int res=0;
    FOR(i,1,n) if(cnt_bit(i)==k) ++res;
    return res;
}
    
int main(){
    ll m;
    int k;
    cin>>m>>k;
    if(m==1 && k==1){
        cout<<1<<endl;
        return 0;   
    }
    ll left=1, right = oo, mid;
    while(left<=right){
        mid=(left+right)/2;
        ll val = cal(mid,k);
        if(val==m){
            cout<<mid<<endl;
            return 0;   
        }else if(val<m)
            left=mid+1;
        else 
            right=mid-1;
    }
    
    return 0;
}
