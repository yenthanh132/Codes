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
    //freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int maxd = 1;
    for(int i=2; i*i<=n; ++i) if(n%i==0){
        maxd=max(maxd,max(i,n/i));
    }
    cout<<n-maxd<<endl;
}

