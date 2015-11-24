#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int t,b;

int gcd(int a, int b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        double x;
        scanf("%lf",&x);
        int xi=int(x*100+1e-9);
        int v,d=0;
        scanf("%d",&b);
        for(int i=0; i<b; ++i){
            scanf("%d",&v);
            v*=100;
            while(v%2==0) v/=2;
            d=gcd(d,v);
        }
        if(xi%d==0) puts("yes");
        else puts("no");
    }
}

