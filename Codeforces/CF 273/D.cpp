#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

bool check(ll r, ll g, ll n){
    ll v=0;
    for(int i=n; i>=1; --i){
        if(r>=i) r-=i;
        else v+=i;
    }
    return v<=g;
}

int f[200007];
ll r,g;

int main(){
    //freopen("input.txt","r",stdin);

    cin>>r>>g;

    ll left=1, right=1000, mid, h;
    while(left<=right){
        mid=(left+right)/2;
        if(check(r,g,mid)){
            h=mid;
            left=mid+1;
        }else right=mid-1;
    }

    int total=h*(h+1)/2;

    f[0]=1;
    for(int i=1; i<=h; ++i)
        for(int j=r; j>=i; --j){
            f[j]+=f[j-i];
            if(f[j]>=oo) f[j]-=oo;
        }

    int res = 0;
    for(int j=0; j<=r; ++j) if(j+g>=total){
        res += f[j];
        if(res>=oo) res-=oo;
    }
    cout<<res<<endl;
}

