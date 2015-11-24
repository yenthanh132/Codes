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
    int T,n;
    ll a,b;
    cin>>T;
    while(T--){
        cin>>n>>a>>b;
        int r1=0,r2=0;
        while(a%2==0) a/=2, ++r1;
        while(b%2==0) b/=2, ++r2;
        r1=min(r1,r2);
        cout<<n-r1<<endl;
    }
}

