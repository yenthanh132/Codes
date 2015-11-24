#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxv=10007;

int n,l[15],r[15],p[15];
double f[1<<5][maxv],res;
double dp[2][maxv];

vector< int > vec[15];

void calc(){
    int maxv=0;
    for(int i=0; i<n; ++i) maxv=max(maxv,p[i]);
    for(int v=1; v<=maxv; ++v){
        vec[v].clear();
        for(int i=0; i<n; ++i)
            if(p[i]==v) vec[v].pb(i);
        if(vec[v].empty()) return;
    }
    //check ok
    int flag=0;
    for(int i=0; i<=10000; ++i) dp[0][i]=0; dp[0][0]=1;
    for(int v=1; v<maxv; ++v){
        flag^=1;
        int b=0;
        for(int i=0; i<sz(vec[v]); ++i){
            b|=1<<vec[v][i];
        }
        dp[flag][0]=0;
        double sum=0;
        for(int x=1; x<=10000; ++x){
            sum+=dp[1^flag][x-1];
            dp[flag][x]=sum*f[b][x];
        }
    }
    double tmp=0;
    int b=0;
    for(int i=0; i<sz(vec[maxv]); ++i) b|=1<<vec[maxv][i];
    if(sz(vec[maxv])==1){
        double sum=0;
        for(int x=1; x<=10000; ++x){
            sum+=(x-1)*dp[flag][x-1];
            tmp+=sum*f[b][x];
        }
    }else{
        double sum=0;
        for(int x=1; x<=10000; ++x){
            sum+=dp[flag][x-1];
            tmp+=x*sum*f[b][x];
        }
    }
    res += tmp;
}

void duyet(int i){
    if(i==n){
        calc();
        return;
    }
    for(int v=1; v<=n; ++v){
        p[i]=v;
        duyet(i+1);
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0; i<n; ++i)
        scanf("%d%d",&l[i],&r[i]);

    for(int b=0; b<(1<<n); ++b){
        for(int v=1; v<=10000; ++v){
            f[b][v]=1;
            for(int i=0; i<n; ++i) if(b>>i&1)
                f[b][v] *= (1.0/(r[i]-l[i]+1))*(l[i]<=v && v<=r[i]);
        }
    }
    res=0;
    duyet(0);
    printf("%0.9f\n",res);
}

