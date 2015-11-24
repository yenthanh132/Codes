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
char s[maxn],t[maxn];
int dp[maxn][207];
int T,m,n,a,b,k;

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",s+1,t+1);
        m=strlen(s+1); n=strlen(t+1);
        scanf("%d%d%d",&a,&b,&k);
        if(a==0){
            puts("0");
        }else if(b==0){
            int len=abs(m-n);
            int cost=len*a;
            if(cost>k) cost=-1;
            printf("%d\n",cost);
        }else{
            int len=abs(m-n);
            int cost=len*a;
            if(cost>k){
                puts("-1");
                continue;
            }
            for(int i=1; i<=m+1; ++i) for(int v=0; v<=200; ++v) dp[i][v]=oo;
            dp[1][100]=0;
            for(int i=1; i<=m+1; ++i) for(int v=0; v<=200; ++v) if(dp[i][v]<=k){
                int j=i+v-100;
                int cost=0;
                if(s[i]!=t[j]) cost=b;
                if(i<=m) dp[i+1][v]=min(dp[i+1][v],dp[i][v]+cost); //replace
                if(v<200) dp[i][v+1]=min(dp[i][v+1],dp[i][v]+a); //add
                if(i<=m && v>0) dp[i+1][v-1]=min(dp[i+1][v-1],dp[i][v]+a); //remove
            }
            cost=dp[m+1][n-m+100];
            if(cost>k) cost=-1;
            printf("%d\n",cost);
        }

    }
}

