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

int a[maxn],n,T;

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        for(int i=1; i<n; ){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                i+=2;
            }else
                ++i;
        }
        bool ok=1;
        for(int i=1; i<n; ++i) if(a[i]>a[i+1]) {ok=0; break;}
        if(!ok) puts("NO");
        else puts("YES");
    }
}

