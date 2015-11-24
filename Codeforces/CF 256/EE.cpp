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

const int maxn=2000007;
const int maxv=100000;

int m,cnt;
ll a[maxn],X,k,res[maxn];

void gen(ll v, ll d){
    if(cnt>=maxv) return;
    if(d==0 || v==1)
    {
        res[++cnt]=v;
        return;
    }

    int c=0;
    for(int i=1; i<=m && a[i]<=v; ++i) if(v%a[i]==0){
        ++c;
    }
    if(c<=2) //prime
    {
        for(ll i=1; i<=d; ++i){
            res[++cnt]=1;
            if(cnt>=maxv) return;
        }
        res[++cnt]=v;
    }
    else
    {
        for(int i=1; i<=m && a[i]<=v; ++i) if(v%a[i]==0) gen(a[i],d-1);
    }
}

int main(){
    cin>>X>>k;

    m=0;
    for(ll i=1; i*i<=X; ++i) if(X%i==0){
        a[++m]=i;
        if(i*i!=X) a[++m]=X/i;
    }
    sort(a+1,a+m+1);

    cnt=0;
    gen(X,k);

    for(int i=1; i<=min(cnt,maxv); ++i) printf("%I64d ",res[i]);
    return 0;
}
