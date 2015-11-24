#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[22],n,T;
int res,sum;

void duyet(int i){
    if(i>=n){
        res = max(res, sum+abs(a[n]-a[1]));
        return;
    }
    if(i*2>n) sum+=abs(a[i]-a[n-i+1]);
    duyet(i+1);
    if(i*2>n) sum-=abs(a[i]-a[n-i+1]);

    if(a[i-1]%2==0 && a[i+1]%2==0){
        int t=a[i];
        a[i]=(a[i-1]+a[i+1])/2;
        if(i*2>n) sum+=abs(a[i]-a[n-i+1]);
        duyet(i+1);
        if(i*2>n) sum-=abs(a[i]-a[n-i+1]);
        a[i]=t;
    }
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>a[i];
        res=0; sum=0;
        duyet(2);
        cout<<res<<endl;
    }
}

