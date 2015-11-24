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

int n,x[maxn],p[maxn],m[maxn];
set<pii> mys;

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mys.clear();
        for(int i=1; i<=n; ++i)
            scanf("%d%d%d",&x[i],&p[i],&m[i]);

        ll res = 0;
        for(int i=n; i>=1; --i){
            mys.insert(pii(-p[i],i));
            while(!mys.empty()){
                int pos=mys.begin()->second; mys.erase(mys.begin());
                if(x[i] < m[pos]){
                    res += 1ll*x[i]*p[pos];
                    m[pos] -= x[i];
                    mys.insert(pii(-p[pos],pos));
                    break;
                }else{ //x[i] >=m[pos]
                    res += 1ll*m[pos]*p[pos];;
                    x[i] -= m[pos];

                }
            }
        }

        cout<<res<<endl;
    }
}

