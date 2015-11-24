#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
//    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int a[11][11];
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
        if(i==1 || j==1) a[i][j]=1;
        else a[i][j]=a[i-1][j]+a[i][j-1];
    cout<<a[n][n]<<endl;
}

