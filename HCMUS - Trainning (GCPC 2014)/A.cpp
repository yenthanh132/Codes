#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

ll f[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    f[0]=1;
    for(int i=1; i<=100000; ++i) f[i]=f[i-1]*i%oo;
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        cout<<(f[n]-1+oo)%oo<<endl;
    }
}

