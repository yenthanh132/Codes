#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    ll N;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&N);
        ll a = 1, b = 1;
        int res = 1;
        while(a+b<=N){
            ++res;
            ll c = a + b;
            a = b;
            b = c;
        }
        printf("%d\n",res);
    }
}

