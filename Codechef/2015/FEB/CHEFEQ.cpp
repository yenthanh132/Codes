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

int n,a[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
        int r=1;
        sort(a+1,a+n+1);
        for(int i=1,j; i<=n; ){
            j=i;
            while(j<=n && a[j]==a[i]) ++j;
            r=max(r,j-i);
            i=j;
        }
        printf("%d\n",n-r);
    }
}

