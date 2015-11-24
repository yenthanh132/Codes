#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


int n,k,a[2222];

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n>>k; for(int i=1; i<=n; ++i) cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    int res=0;
    for(int i=1; i<=n; i+=k){
        res+=(a[i]-1)*2;
    }
    cout<<res<<endl;
}

