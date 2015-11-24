#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=5007;

int n,a[maxn];

int main(){
//    freopen("input.txt","r",stdin);
    ll r1=0,r2=0,r3=0;
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=1; i<=n-2; ++i){
        int x=i+1,y=i+1;
        for(int j=i+1; j<n; ++j){
            while(x<=j) ++x;
            while(x<=n && a[i]*a[i] + a[j]*a[j] > a[x]*a[x]) ++x;

            while(y<=j) ++y;
            while(y+1<=n && a[i]+a[j] > a[y+1]) ++y;

            r1 += x-j-1;
            if(x<=n){
                if(a[i]*a[i]+a[j]*a[j]==a[x]*a[x]) ++r2;
                else if(a[i]+a[j] > a[x]) ++r3;
            }
            if(x<=n) r3 += y-x;
        }
    }
    cout<<r1<<' '<<r2<<' '<<r3<<endl;
}

