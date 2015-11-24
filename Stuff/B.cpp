#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=107;

int a[maxn],b[maxn],m,n;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>m;
    for(int i=1; i<=m; ++i) cin>>a[i];
    cin>>n;
    for(int j=1; j<=n; ++j) cin>>b[j];
    sort(a+1,a+m+1); sort(b+1,b+n+1);
    int res = 0;
    int j=1;
    for(int i=1; i<=m; ++i){
        while(j<=n && b[j]<a[i]-1) ++j;
        if(j<=n && b[j]<=a[i]+1){
            ++res;
            ++j;
        }
    }
    cout<<res<<endl;
    return 0;
}

