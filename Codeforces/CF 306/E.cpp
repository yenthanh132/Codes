#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;
int a[maxn],n;

int main(){
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];

    if(n==1 && a[0]==0){
        cout<<"YES"<<endl<<0<<endl;
        return 0;
    }
    if(a[n]==1){
        cout<<"NO"<<endl;
        return 0;
    }

    if(a[n-1]==1){
        cout<<"YES"<<endl;
        for(int i=1; i<n; ++i) cout<<a[i]<<"->";
        cout<<a[n]<<endl;

    }else{
        int i=n-2;
        while(i>=1 && a[i]==1) --i;
        if(i>=1){
            cout<<"YES"<<endl;
            for(int j=1; j<i; ++j) cout<<a[j]<<"->";
            cout<<"(0->(";
            for(int j=i+1; j<n-1; ++j) cout<<a[j]<<"->";
            cout<<"0))";
            cout<<"->"<<a[n]<<endl;
        }
        else cout<<"NO"<<endl;
    }
}
