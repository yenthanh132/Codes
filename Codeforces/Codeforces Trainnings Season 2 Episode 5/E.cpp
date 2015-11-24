#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=10;
ll dp[maxn][maxn*maxn][1<<10];
int n,k,ds[maxn];
double C[100][100];
char s[maxn][maxn];

int main(){
    //freopen("input.txt","r",stdin);

    C[0][0]=1;
    for(int i=1; i<100; ++i){
        C[i][0]=1;
        for(int j=1; j<=i; ++j) C[i][j]=C[i-1][j]+C[i-1][j-1];
    }

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; ++i) scanf("%s",s[i]);
        reset(dp,0);
        dp[0][0][0]=1;
        for(int i=0; i<n; ++i) for(int j=0; j<=k; ++j) for(int mask=0; mask<(1<<(n+2)); ++mask)
            if(dp[i][j][mask]){
                int cnt=0;
                for(int x=0; x<n; ++x) if(s[i][x]=='.') ds[cnt++]=x;

                for(int mask2=0; mask2<(1<<cnt)-1; ++mask2){
                    int state=mask,j2=j;
                    for(int x=0; x<cnt; ++x)
                        if(mask2>>x&1){
                            ++j2;
                        }else{
                            int pos=ds[x];
                            state |= 1<<pos;
                            if(pos==i) state |= 1<<n;
                            if(pos==n-i-1) state |= 1<<(n+1);
                        }
                    if(j2<=k) dp[i+1][j2][state] += dp[i][j][mask];
                }
            }

        int total=0;
        for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) total+=(s[i][j]=='.');

        printf("%0.9lf\n",100 - 100*(dp[n][k][(1<<(n+2))-1]/C[total][k]));

    }
}

