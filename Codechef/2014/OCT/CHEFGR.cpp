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
    int t,n,m,v,s,maxh;
    cin>>t;
    for(int tt=0; tt<t; ++tt){
        cin>>n>>m;
        s=0;
        maxh=0;
        for(int i=1; i<=n; ++i){
            cin>>v;
            s+=v;
            maxh=max(maxh,v);
        }
        if((s+m)%n==0 && (s+m)/n>=maxh) cout<<"Yes"<<endl; else cout<<"No"<<endl;
    }
}

