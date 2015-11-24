#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string w[111];
set<string> mys;
int T,n,k;

int main(){
//    freopen("input.txt","r",stdin);
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1; i<=n; ++i) cin>>w[i];
        mys.clear();
        for(int i=0; i<k; ++i){
            int c;
            cin>>c;
            string t;
            for(int j=0; j<c; ++j){
                cin>>t;
                mys.insert(t);
            }
        }
        for(int i=1; i<=n; ++i){
            if(mys.count(w[i])) cout<<"YES"; else cout<<"NO";
            if(i<n) cout<<' '; else cout<<"\n";
        }
    }
}

