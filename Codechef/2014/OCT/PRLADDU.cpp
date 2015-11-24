#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1000007;

int T,n,last;
pii mys[maxn];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    for(int tt=0; tt<T; ++tt){
        scanf("%d",&n);
        last=0;
        ll res=0;
        int d;
        for(int i=0; i<n; ++i){
            scanf("%d",&d);
            while(last>0 && ( mys[last].first > 0 ) != (d > 0) && d != 0){
                pii t=mys[last--];
                if(abs(t.first)<=abs(d)){
                    d += t.first;
                    res += 1ll*(i - t.second)*abs(t.first);
                }else{
                    t.first += d;
                    res += 1ll * (i - t.second) * abs(d);
                    mys[++last] = pii(t.first, t.second);
                    d = 0;
                }
            }
            if(d!=0) mys[++last] = pii(d, i);
        }
        printf("%lld\n",res);
    }
}

