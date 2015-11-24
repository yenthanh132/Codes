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

ll X,k;
ll a[maxn],res[maxn];
int m,cnt;

void gen(ll X, ll d){
    if(cnt>=100000) return;
    if(X==1 || d==0){
        res[++cnt]=X;
        return;
    }
    int c=0;
    for(int i=1; cnt<100000 && i<=m && a[i]<=X; ++i)
        if(X%a[i]==0)
            gen(a[i],d-1);
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>X>>k;
    m=0;
    for(ll i=1; i*i<=X; ++i) if(X%i==0){
        a[++m]=i;
        if(i*i<X) a[++m]=X/i;
    }
    sort(a+1,a+m+1);

    cnt=0;
    gen(X,k);
    for(int i=1; i<=cnt; ++i) printf("%I64d ",res[i]);

    return 0;
}
