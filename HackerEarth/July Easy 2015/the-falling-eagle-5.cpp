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

int a[maxn],n,T,mys[maxn],L[maxn],R[maxn],last;

int main(){
//    freopen("input.txt","r",stdin);

    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>a[i];
        a[0]=oo;
        mys[0]=0;
        last=0;
        for(int i=1; i<=n; ++i){
            while(last>0 && a[mys[last]]<=a[i]) --last;
            L[i]=mys[last];
            mys[++last]=i;
        }
        last=0;
        for(int i=n; i>=1; --i){
            while(last>0 && a[mys[last]]<=a[i]) --last;
            R[i]=mys[last];
            mys[++last]=i;
        }

        ll res=0;

        for(int i=1; i<=n; ++i){

            int v = min(a[L[i]],a[R[i]]);
            if(v!=oo) res+=v;

        }

        cout<<res<<endl;
    }
}

