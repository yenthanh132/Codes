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
//    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(0);
    int T,n,v;
    cin>>T;
    while(T--){
        cin>>n;
        set<int> mys;
        for(int i=0; i<n; ++i){
            cin>>v;
            mys.insert(v);
        }
        cout<<sz(mys)<<endl;
    }
}

