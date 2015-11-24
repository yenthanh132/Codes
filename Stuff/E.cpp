#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=1007;

int x[maxn],b[maxn];
int n,l;
vector<int> ret;
double dp[maxn];
int trace[maxn];

double calc(int len){
    return sqrt(abs(len-l));
}

bool check(double ans){
    dp[0]=0;
    for(int i=1; i<=n; ++i){
        trace[i]=-1;
        dp[i]=1e18;
        for(int j=0; j<i; ++j) if(dp[i] > dp[j] + (calc(x[i]-x[j]) - ans*b[i])){
            dp[i] = dp[j] + (calc(x[i]-x[j]) - ans*b[i]);
            trace[i]=j;
        }
    }
    if(dp[n]>0) return 0;
    ret.clear();
    int u=trace[n];
    ret.pb(n);
    while(u){
        ret.pb(u);
        u=trace[u];
    }
    return 1;
}

int main(){
//    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n>>l;
    x[0]=0;
    for(int i=1; i<=n; ++i) cin>>x[i]>>b[i];
    double left=0, right=1e18, mid;
    for(int i=0; i<100; ++i){
        mid=(left+right)/2;
        if(check(mid)){
            right=mid;
        }else{
            left=mid;
        }
    }
    check(right);
//    cout<<right<<endl;
    for(int i=sz(ret)-1; i>=0; --i) cout<<ret[i]<<' '; cout<<endl;
}

