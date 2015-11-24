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
    int t;
    ll res=0;
    cin>>t;
    for(int i=1; i<=t; ++i) res+=(i+2)/2;
    cout<<res<<endl;
}

