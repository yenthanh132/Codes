#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int a[111];
int n;

int main(){
//    freopen("input.txt","r",stdin);
    ll w,m;
    cin>>w>>m;
    n=0;
    while(m>0){
        a[n++]=m%w;
        m/=w;
    }
    for(int i=0; i<n; ++i){
        if(a[i]!=0 && a[i]!=1 && a[i]!=w-1 && a[i]!=w){
            cout<<"NO"<<endl;
            return 0;
        }
        if(a[i]==w || (a[i]>1 && a[i]==w-1)) a[i+1]++;
    }
    cout<<"YES"<<endl;

}

