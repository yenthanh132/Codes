#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=507;

int x[maxn*maxn],y[maxn*maxn];
int n;

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j){
            int v; scanf("%d",&v);
            x[v]=i; y[v]=j;
        }
        int res=0;
        for(int i=2; i<=n*n; ++i) res+=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
        printf("%d\n",res);
    }
}

