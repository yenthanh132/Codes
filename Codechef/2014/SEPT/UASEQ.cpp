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
#define oo 1000000000000000007ll

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

//Random function
double randf() {
    double base = 0.1;
    double res = 0;
    for (int i = 0; i < 15; i++) {
        res += base * (rand() % 10);
        base /= 10;
    }
    return res;
}

int randi(int n) {
    return (int)floor(randf() * n);
}

const int maxn=100007;

int n,k,a[maxn];
ll ra,rd;

void check(int i, int j){
    if(i>j) swap(i,j);
    ll d = (a[j]-a[i]);
    int len = j-i;
    if(d%len) return;
    d/=len;
    ll ta = a[i] - d*(i-1);
    //Check
    int c = 0;
    for(int x=1; x<=n; ++x) if(ta + (x-1)*d != a[x]){
        ++c;
        if(c>k) return;
    }
    //Found
    if(ta < ra || (ta==ra && d < rd)){
        ra = ta;
        rd = d;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);

    ra = rd = oo;
    if(n<=100){
        for(int i=1; i<n; ++i) for(int j=i+1; j<=n; ++j) check(i,j);
    }else{
        for(int r=0; r<30; ++r){
            int i=randi(n)+1;
            int j=randi(n)+1;
            while(i==j) j=randi(n)+1;
            check(i,j);
        }
    }
    for(int i=0; i<n; ++i) printf("%lld ",ra + rd * i);

    return 0;
}
