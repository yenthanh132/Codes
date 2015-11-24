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

const int maxn=1000000;
ll a[maxn],b[maxn];
map<ll,int> mys;

int list(ll n, ll arr[]){
    int c=0;
    while(n!=1){
        arr[c++]=n;
        if(n&1) n=n*3+1;
        else n/=2;
    }
    arr[c++]=1;
    return c;
}

int main(){
//freopen("input.txt","r",stdin);
    ll A,B;
    while(scanf("%I64d%I64d",&A,&B), A>0){
        int ca=list(A,a);
        int cb=list(B,b);
//        for(int i=0; i<ca; ++i) printf("%I64d ",a[i]); puts("");
//        for(int i=0; i<cb; ++i) printf("%I64d ",b[i]); puts("");
        mys.clear();
        for(int i=0; i<ca; ++i) mys[a[i]]=i;
        int stepa,stepb;
        ll value;
        for(int i=0; i<cb; ++i) if(mys.count(b[i])){
            stepa=mys[b[i]];
            stepb=i;
            value=b[i];
            break;
        }
        printf("%I64d needs %d steps, %I64d needs %d steps, they meet at %I64d\n",A,stepa,B,stepb,value);
    }
    return 0;
}
