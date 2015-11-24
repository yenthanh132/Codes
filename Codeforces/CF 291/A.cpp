#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll x,arr[111],len;

ll val(){
    ll r=0,mul=1;
    for(int i=1; i<=len; ++i){
        r+=mul*arr[i];
        mul*=10;
    }
    return r;
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>x;
    ll t=x;
    len=0;
    while(t){
        arr[++len]=t%10;
        t/=10;
    }
    for(int i=len; i>=1; --i){
        ll t=val();
        if(arr[i]==9 && i==len) continue;
        if(arr[i]>=5) arr[i]=9-arr[i];
    }
    t=val();
    cout<<t<<endl;
}

