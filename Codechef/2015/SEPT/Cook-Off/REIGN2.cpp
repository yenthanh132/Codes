#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=5007;

ll dp[maxn][maxn];
int n;
pii a[maxn];

bool cmp(const pii &a, const pii &b){
    if(a.second!=b.second) return a.second < b.second;
    return a.first < b.first;
}

void update(ll &a, ll b){
    if(a==-1 || a<b) a=b;
}

int main(){
//    freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i].first);
        for(int i=1; i<=n; ++i) scanf("%d",&a[i].second);
        sort(a+1,a+n+1,cmp);
        reset(dp,0);
        for(int depth=1; depth<=n; ++depth){
            for(int i=n-depth+1; i>=1; --i){
                update(dp[depth][i], dp[depth][i+1]);
                update(dp[depth][i], dp[depth-1][i+1] + 1ll*(depth-1)*a[i].second + a[i].first);
            }
        }
        for(int i=1; i<=n; ++i){
            printf("%lld",dp[i][1]);
            if(i<n) printf(" "); else puts("");
        }
    }
}

