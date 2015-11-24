#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=3007;
const int maxm=307;
int mark[maxn][maxn],n,m,cnt;
double p[maxn][maxm],dp[maxn][maxn];
vector<double> res;

double cal(int i, int j){
    if(j==0) return 1;
    if(i<j) return 0;
    if(mark[i][j]==cnt) return dp[i][j];
    mark[i][j]=cnt;
    double &res=dp[i][j];
    res=cal(i-1,j)*(1-p[i][cnt]);
    if(j>0) res+=cal(i-1,j-1)*p[i][cnt];
    return res;
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i){
        int v;
        for(int j=1; j<=m; ++j){
            scanf("%d",&v);
            p[i][j]=1.0*v/1000;
        }
    }
    reset(mark,0);
    for(int x=1; x<=m; ++x){
        cnt=x;
        for(int j=1; j<=n; ++j){
            double val=cal(n,j);
            if(val>1e-9) res.pb(val);
            else break;
        }
    }
    sort(res.begin(),res.end(),greater<double>());

    double sum=0;
    for(int i=0; i<n; ++i) sum+=res[i];
    printf("%0.9f",sum);
}

