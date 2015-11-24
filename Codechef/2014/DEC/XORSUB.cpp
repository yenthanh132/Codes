#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1006;

int T,n,a[maxn],k;

int main(){
//    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1; i<=n; ++i) cin>>a[i];
        for(int i=9, s=1; s<=n && i>=0; --i){
            int u=-1;
            for(int j=s; j<=n; ++j) if(a[j]>>i&1){
                u=j;
                break;
            }
            if(u!=-1){
                swap(a[s],a[u]);
                for(int j=1; j<=n; ++j) if(j!=s && (a[j]>>i&1)) a[j]^=a[s];
                ++s;
            }
        }
//        for(int i=1; i<=n; ++i){
//            for(int j=9; j>=0; --j) cout<<(a[i]>>j&1);
//            cout<<endl;
//        }
        for(int i=1; i<=n; ++i) if((k^a[i])>k)
            k^=a[i];
        cout<<k<<endl;
    }
}

