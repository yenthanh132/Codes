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
    int T,X;
    ll K;
    scanf("%d",&T);
    while(T--){
        scanf("%d%lld",&X,&K);
        double len=X;
        for(ll n=1; ; n*=2, len/=2){
            if(n>=K){
                printf("%.9f\n",len*(K-0.5));
                break;
            }else{
                K-=n;
            }
        }
    }
}

