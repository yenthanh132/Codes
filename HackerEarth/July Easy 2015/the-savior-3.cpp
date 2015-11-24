#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[3333];

int main(){
//    freopen("input.txt","r",stdin);
    int T,n,c0,c1;
    cin>>T;
    while(T--){
        cin>>n;
        int res=0;
        for(int i=0; i<n; ++i) cin>>a[i];
        for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j) if((a[i]+a[j])%2==0 && a[i]!=a[j]) ++res;
        cout<<res<<endl;
    }
}

