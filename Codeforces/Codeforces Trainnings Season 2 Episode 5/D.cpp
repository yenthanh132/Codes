#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int T,m,n,q;
int cnt[20];
ll dp[6][55];
char s[20];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&m,&n,&q);
        reset(cnt,0);
        for(int i=0; i<m; ++i){
            scanf("%s",s);
            ++cnt[strlen(s)];
        }
        reset(dp,0);
        dp[0][0]=1;
        for(int i=0; i<n; ++i) for(int j=0; j<50; ++j) if(dp[i][j])
            for(int l=3; l<=10 && l+j<=50; ++l) dp[i+1][j+l]+=dp[i][j]*cnt[l];
        int len;
        for(int i=0; i<q; ++i){
            scanf("%d",&len);
            printf("%I64d\n",dp[n][len]);
        }
    }
}

