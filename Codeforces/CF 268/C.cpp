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
#define pb push_back
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=207;



ll p10[maxn],f[maxn];
ll A;

ll mul(ll a, ll b){
    if(a<b) swap(a,b);
    if(b==0) return 0;
    if((a*b)/b==a) return a*b%A;
    ll t=mul(a,b/2);
    t=t*2%A;
    if(b&1) t=(t+a)%A;
    return t;
}

string s;

ll calc(int i, int n, ll sum){
    if(n==0) return sum;
    int v=s[i]-'0';
    ll x=v*(v-1)/2;
    ll res = mul(p10[n-1],x) + mul(p10[n-1],v*sum) + mul(f[n-1],v); res%=A;
    if(v==0) res=0;
    return (res + calc(i+1,n-1,sum+v));
}

int main(){
A=126444381000032ll;
    //cin>>A;
    p10[0]=1%A;
    for(int i=1; i<=200; ++i) p10[i]=mul(p10[i-1],10);
    f[0]=0;
    for(int i=1; i<=200; ++i) f[i]= mul(p10[i-1], 45) + mul(f[i-1],10), f[i]%=A;

    s="2333333333333";
    cout<<calc(0,sz(s),0)<<endl;

    s="2333332";
    cout<<calc(0,sz(s),0);
}
