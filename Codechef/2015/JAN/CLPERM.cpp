#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;
int T,n,k,a[maxn];

ll sum(ll n){ return n*(n+1)/2; }

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=0; i<k; ++i) scanf("%d",&a[i]);
        sort(a,a+k);
        k=unique(a,a+k)-a;
        int v,last=0;
        ll s=0,res=-1;
        for(int i=0; i<k; ++i){
            v=a[i];
            s+=sum(v-1) - sum(last);
            last = v;
            if(s<v){
                res=s;
                break;
            }
        }
        if(res==-1) res = s + sum(n) - sum(last);
        if(res&1) puts("Mom"); else puts("Chef");
    }
}

