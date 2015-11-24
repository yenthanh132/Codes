#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int n,k,a[111],minv,maxv;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n>>k;
    minv=oo; maxv=-oo;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
        minv=min(minv,a[i]);
        maxv=max(maxv,a[i]);
    }
    if(maxv-minv>k){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=a[i]; ++j){
                cout<<max(1,j-minv)<<' ';
            }
            cout<<endl;
        }
    }
}

