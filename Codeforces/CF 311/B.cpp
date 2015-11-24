#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[222222],n,w;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>w;
    for(int i=1; i<=n*2; ++i) cin>>a[i];
    sort(a+1,a+n*2+1);
    double v=min(a[1]*1.0, a[n+1]/2.0);
    double res=min(w*1.0,v*3*n);
    printf("%0.9f\n",res);
}

