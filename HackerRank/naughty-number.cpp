#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[111],b[111],n;
int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=1; i<=n+1; ++i) cin>>b[i];
    sort(a+1,a+n+1); sort(b+1, b+n+2);
    for(int i=1; i<=n; ++i) if(a[i]!=b[i]){
        cout<<b[i];
        return 0;
    }
    cout<<b[n+1];
}

