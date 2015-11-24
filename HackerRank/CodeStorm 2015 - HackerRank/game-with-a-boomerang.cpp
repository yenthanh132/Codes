#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;


ll get(ll n){
    if(n==2) return 1;
    if(n==3) return 2;
    if(n%2==0){
        ll n2=n/2;
        ll v=get(n2);
        if(n2&1){
            ll res=n/2+v*2;
            res = (res + n - 1)%n + 1;
            return res;
        }else{
            ll res=n/2+v*2;
            if(v>n2/2) res--;
            res = (res + n - 1)%n + 1;
            return res;
        }
    }else{
        ll res = get(n-1) + 1;
        res = (res + n - 1)%n + 1;
        return res;
    }
}

int main(){
//    freopen("input.txt","r",stdin);

    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        cout<<get(n)<<endl;
    }
}

