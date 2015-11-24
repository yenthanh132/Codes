#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll a[5];

int main(){
    //freopen("input.txt","r",stdin);
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+4);
    ll res = min((a[1]+a[2]+a[3])/3,a[1]+a[2]);
    cout<<res<<endl;
}

