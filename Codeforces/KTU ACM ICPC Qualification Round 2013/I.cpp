#include <bits/stdc++.h>

#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> iii;
typedef long long ll;

int T,n,m;
string a[11],s;

int main() {
    //freopen("input.txt", "r", stdin);

    cin>>T;
    for(int tt=1; tt<=T; ++tt){
        cout<<"Case #"<<tt<<":"<<endl;
        cin>>n>>m;
        for(int i=1; i<=n; ++i) cin>>a[i];
        for(int j=1; j<=m; ++j){
            cin>>s;
            bool found=0;
            int cnt1=0;
            for(int i=1; i<=n; ++i) if(sz(s)==sz(a[i])){
                int c=0;
                for(int z=0; z<sz(s); ++z) if(s[z]!=a[i][z]) ++c;
                if(c==0){
                    found=1;
                    break;
                }
                if(c==1) ++cnt1;
            }
            if(found || cnt1==1) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }
    return 0;
}


