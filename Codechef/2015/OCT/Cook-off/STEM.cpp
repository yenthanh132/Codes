#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

string s[22];
int T,n;

bool ok(string t){
    for(int i=2; i<=n; ++i) if(s[i].find(t)==string::npos) return 0;
    return 1;
}

int main(){
//    freopen("input.txt","r",stdin);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1; i<=n; ++i) cin>>s[i];
        string best="";
        for(int i=0; i<sz(s[1]); ++i) for(int j=i; j<sz(s[1]); ++j){
            string t=s[1].substr(i,j-i+1);
            if(sz(t) >= sz(best) && ok(t)){
                if(sz(t) > sz(best) || (sz(t) == sz(best) && t < best)) best = t;
            }
        }
        cout<<best<<endl;
    }
}

