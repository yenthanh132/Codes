#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll solve(ll A, ll left){
    if(left<0) return 0;
    ll res=0;
    ll x=0;
    if(left>=A){
        x=(left-A)/2;
        res = (x+1)*(A+1);
        ++x;
    }
    ll top=left-x;
    if(top>=x){
        top=top-x+1;
        ll bot=0;
        if(top&1) ++bot;
        ll len=(top-bot)/2+1;
        res += len*(top+bot)/2;
    }
    return res*2 - (left/2+1);
}

int main(){
//    freopen("input.txt","r",stdin);

    int a,b,c,T;
    cin>>a>>b>>c>>T;
    ll res = 0;
    for(int x=0; x<=T; ++x){
        int a2=a+x;
        int left=min(T-x,a2-b-c);
        if(left>=0) res+=1ll*(left+2)*(left+1)/2;
    }
    swap(a,b);
    for(int x=0; x<=T; ++x){
        int a2=a+x;
        int left=min(T-x,a2-b-c);
        if(left>=0) res+=1ll*(left+2)*(left+1)/2;
    }
    swap(a,c);
    for(int x=0; x<=T; ++x){
        int a2=a+x;
        int left=min(T-x,a2-b-c);
        if(left>=0) res+=1ll*(left+2)*(left+1)/2;
    }
    ll n=T+3;
    ll C = n*(n-1)*(n-2)/6;
    cout<<C-res<<endl;

}

